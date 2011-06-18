%{
	#include <string>
        #include <iostream>

        #include "KML.h"
        extern KML* tree;

        #include "textnode.h"
        #include "boolnode.h"
        #include "numbernode.h"
        #include "Document.h"
        #include "Placemark.h"
        #include "Folder.h"
        #include "Name.h"
        #include "Style.h"
        #include "Description.h"
        #include "Visibility.h"
        #include "Point.h"
        #include "LineString.h"
        #include "LinearRing.h"
        #include "Polygon.h"
        #include "Multigeometry.h"
        #include "StyleURL.h"
        #include "Coordinates.h"
	#include "OuterBoundaryIs.h"
	#include "InnerBoundaryIs.h"
	#include "IconStyle.h"
	#include "LabelStyle.h"
	#include "LineStyle.h"
	#include "PolyStyle.h"
	#include "Color.h"
	#include "Scale.h"
	#include "Heading.h"
	#include "Icon.h"
	#include "Hotspot.h"
	#include "Href.h"
	#include "Width.h"
	#include "Fill.h"
	#include "Outline.h"


        node* last_element;

	extern int yylex();
        extern int flush_lex(void);
	void yyerror(const char *s) { std::cout << "ERROR: " << s << " in line: " << flush_lex() << "\n" ;}

void makeHotspot()
{
  if (!dynamic_cast<Hotspot*>(last_element))
  {
    last_element->AddChild(new Hotspot());
    last_element = last_element->GetLastChild();
  }
}
%}

%union{
		std::string *str;
}

%token KML_SYM
%token ID_SYM
%token STRING // z "
%token TEXT // bez "
%token DOCUMENT_SYM
%token PLACEMARK_SYM
%token NAME_SYM
%token STYLE_SYM
%token FOLDER_SYM
%token NUMBER
%token DESCRIPTION_SYM
%token FILL_SYM
%token POINT_SYM
%token MULTIGEOMETRY_SYM
%token INNER_BOUNDARY_IS_SYM
%token OUTER_BOUNDARY_IS_SYM
%token LINE_STRING_SYM
%token POLYGON_SYM
%token COORDINATES_SYM
%token HOTSPOT_SYM
%token YUNITS_SYM
%token XUNITS_SYM
%token X_SYM
%token Y_SYM
%token ICON_SYM
%token SCALE_SYM
%token OUTLINE_SYM
%token COLOR_SYM
%token LABEL_STYLE_SYM
%token STYLE_URL_SYM
%token LINE_STYLE_SYM
%token POLY_STYLE_SYM
%token ICON_STYLE_SYM
%token LINEAR_RING_SYM
%token HREF_SYM
%token HEADING_SYM
%token VISIBILITY_SYM
%token WIDTH_SYM
%token TAG_OPEN // '<'
%token TAG_CLOSE // '>'
%token TAG_END // '/'
%token COMMA //',' 
%token BOOLEAN_VAL /// 1 | 0
%token EQ // '='

%type<str> options
%type<str> TEXT BOOLEAN_VAL NUMBER STRING

%%

input: kml_start kml kml_end 
;

kml_start: TAG_OPEN KML_SYM options TAG_CLOSE
{
  if (tree)
  {
    delete tree;
  }
  tree = new KML($3);
  last_element = tree
}
;

kml_end: TAG_OPEN TAG_END KML_SYM TAG_CLOSE
;

kml: /* empty */ 
			| kml document_start document document_end
			| kml placemark_start placemark placemark_end
			| kml folder_start folder folder_end
;

document_start: TAG_OPEN DOCUMENT_SYM options TAG_CLOSE
{
last_element->AddChild(new Document($3));
last_element = last_element->GetLastChild();
}
; 

document_end: TAG_OPEN TAG_END DOCUMENT_SYM TAG_CLOSE
{
last_element = last_element->GetParent()
}
;

document: /* empty */
				| document placemark_start placemark placemark_end
				| document name_start name name_end
				| document style_start style style_end
				| document folder_start folder folder_end
				| document description_start description description_end
				| document visibility_start visibility visibility_end
;

placemark_start: TAG_OPEN PLACEMARK_SYM options TAG_CLOSE
{
last_element->AddChild(new Placemark($3));
last_element = last_element->GetLastChild();
}
; 

placemark_end: TAG_OPEN TAG_END PLACEMARK_SYM TAG_CLOSE
{
last_element = last_element->GetParent()
}
;

placemark: /* empty */
				| placemark point_start point point_end
				| placemark line_string_start line_string line_string_end
				| placemark linear_ring_start linear_ring linear_ring_end
				| placemark polygon_start polygon polygon_end
				| placemark multigeometry_start multigeometry multigeometry_end
				| placemark style_url_start style_url style_url_end
                                | placemark name_start name name_end
                                | placemark visibility_start visibility visibility_end
                                | placemark description_start description description_end
;

style_url_start: TAG_OPEN STYLE_URL_SYM options TAG_CLOSE
{
last_element->AddChild(new StyleURL($3));
last_element = last_element->GetLastChild();
}
;

style_url: TEXT
{
last_element->AddChild(new textnode($1));
}
;

style_url_end: TAG_OPEN TAG_END STYLE_URL_SYM TAG_CLOSE
{
last_element = last_element->GetParent()
}
;



point_start: TAG_OPEN POINT_SYM options TAG_CLOSE
{
last_element->AddChild(new Point($3));
last_element = last_element->GetLastChild();
}
;

point: coordinates_start one_coordinates coordinates_end
;

coordinates_start: TAG_OPEN COORDINATES_SYM options TAG_CLOSE
{
last_element->AddChild(new Coordinates($3));
last_element = last_element->GetLastChild();
}
;

coordinates: one_coordinates
						| coordinates one_coordinates
;

one_coordinates: NUMBER COMMA NUMBER COMMA NUMBER
{
if (dynamic_cast<Coordinates*>(last_element))
{
  dynamic_cast<Coordinates*>(last_element)->addCoordinate($1, $3, $5);
}
}
;

coordinates_end: TAG_OPEN TAG_END COORDINATES_SYM TAG_CLOSE
;

point_end: TAG_OPEN TAG_END POINT_SYM TAG_CLOSE
{
last_element = last_element->GetParent()
}
;

line_string_start: TAG_OPEN LINE_STRING_SYM options TAG_CLOSE
{
last_element->AddChild(new LineString($3));
last_element = last_element->GetLastChild();
}
;

line_string: coordinates_start coordinates coordinates_end
;

line_string_end: TAG_OPEN TAG_END LINE_STRING_SYM TAG_CLOSE
{
last_element = last_element->GetParent()
}
;

linear_ring_start: TAG_OPEN LINEAR_RING_SYM options TAG_CLOSE
{
last_element->AddChild(new LinearRing($3));
last_element = last_element->GetLastChild();
}
;

linear_ring: coordinates_start coordinates coordinates_end
;

linear_ring_end: TAG_OPEN TAG_END LINEAR_RING_SYM TAG_CLOSE
{
last_element = last_element->GetParent()
}
;

polygon_start: TAG_OPEN POLYGON_SYM options TAG_CLOSE
{
last_element->AddChild(new Polygon($3));
last_element = last_element->GetLastChild();
}
;

polygon: polygon_more outer_boundary_is_start outer_boundary_is outer_boundary_is_end
				/*outer_boundary_is_start outer_boundary_is outer_boundary_is_end polygon_more
				| *//*
				| polygon_more outer_boundary_is_start outer_boundary_is outer_boundary_is_end polygon_more*/
;

polygon_end:TAG_OPEN TAG_END POLYGON_SYM TAG_CLOSE
{
last_element = last_element->GetParent()
}
;

polygon_more: /* empty */
							| polygon_more inner_boundary_is_start inner_boundary_is inner_boundary_is_end
;

outer_boundary_is_start: TAG_OPEN OUTER_BOUNDARY_IS_SYM options TAG_CLOSE
{
last_element->AddChild(new OuterBoundaryIs($3));
last_element = last_element->GetLastChild();
}
;

outer_boundary_is: linear_ring_start linear_ring linear_ring_end
;

outer_boundary_is_end: TAG_OPEN TAG_END OUTER_BOUNDARY_IS_SYM TAG_CLOSE
{
last_element = last_element->GetParent()
}
;

inner_boundary_is_start: TAG_OPEN INNER_BOUNDARY_IS_SYM options TAG_CLOSE
{
last_element->AddChild(new InnerBoundaryIs($3));
last_element = last_element->GetLastChild();
}
;

inner_boundary_is: linear_ring_start linear_ring linear_ring_end
;

inner_boundary_is_end: TAG_OPEN TAG_END INNER_BOUNDARY_IS_SYM TAG_CLOSE
{
last_element = last_element->GetParent()
}
;


multigeometry_start: TAG_OPEN MULTIGEOMETRY_SYM options TAG_CLOSE
{
last_element->AddChild(new Multigeometry($3));
last_element = last_element->GetLastChild();
}
;

multigeometry: /* empty */
							| multigeometry point_start point point_end
							| multigeometry line_string_start line_string line_string_end
							| multigeometry linear_ring_start linear_ring linear_ring_end
							| multigeometry polygon_start polygon polygon_end
							| multigeometry multigeometry_start multigeometry multigeometry_end
;

multigeometry_end: TAG_OPEN TAG_END MULTIGEOMETRY_SYM TAG_CLOSE
{
last_element = last_element->GetParent()
}
;

name_start: TAG_OPEN NAME_SYM options TAG_CLOSE
{
last_element->AddChild(new Name($3));
last_element = last_element->GetLastChild();
}
; 

name_end: TAG_OPEN TAG_END NAME_SYM TAG_CLOSE
{
last_element = last_element->GetParent()
}
;

name: TEXT
{
last_element->AddChild(new textnode($1));
}
;


style_start: TAG_OPEN STYLE_SYM options TAG_CLOSE
{
last_element->AddChild(new Style($3));
last_element = last_element->GetLastChild();
}
; 

style_end: TAG_OPEN TAG_END STYLE_SYM TAG_CLOSE
{
last_element = last_element->GetParent()
}
;

style: /* empty */
			| style icon_style_start icon_style icon_style_end
			| style label_style_start label_style label_style_end
			| style line_style_start line_style line_style_end
			| style poly_style_start poly_style poly_style_end
;

icon_style_start: TAG_OPEN ICON_STYLE_SYM options TAG_CLOSE
{
last_element->AddChild(new IconStyle($3));
last_element = last_element->GetLastChild();
}
;

icon_style_end: TAG_OPEN TAG_END ICON_STYLE_SYM TAG_CLOSE
{
last_element = last_element->GetParent()
}
;

icon_style: /* empty */
						| icon_style color_start color color_end
						| icon_style scale_start scale scale_end
						| icon_style heading_start heading heading_end
						| icon_style icon_start icon icon_end
						| icon_style hotspot
;

heading_start: TAG_OPEN HEADING_SYM options TAG_CLOSE
{
last_element->AddChild(new Heading($3));
last_element = last_element->GetLastChild();
}
;

heading: NUMBER
{
last_element->AddChild(new numbernode($1));
}
;

heading_end: TAG_OPEN TAG_END HEADING_SYM TAG_CLOSE
{
last_element = last_element->GetParent()
}
;

icon_start: TAG_OPEN ICON_SYM options TAG_CLOSE
{
last_element->AddChild(new Icon($3));
last_element = last_element->GetLastChild();
}
;

icon: /* empty */
			| icon href_start href href_end
;

icon_end: TAG_OPEN TAG_END ICON_SYM TAG_CLOSE
{
last_element = last_element->GetParent()
}
;

href_start: TAG_OPEN HREF_SYM options TAG_CLOSE
{
last_element->AddChild(new Href($3));
last_element = last_element->GetLastChild();
}
;

href: TEXT
{
last_element->AddChild(new textnode($1));
}
;

href_end: TAG_OPEN TAG_END HREF_SYM TAG_CLOSE
{
last_element = last_element->GetParent()
}
;

hotspot: TAG_OPEN HOTSPOT_SYM hotspot_options TAG_END TAG_CLOSE
{
last_element = last_element->GetParent()
}
;

hotspot_options: /* empty */
					| hotspot_options X_SYM EQ STRING
{
makeHotspot();
dynamic_cast<Hotspot*>(last_element)->setX($4);
}
					| hotspot_options Y_SYM EQ STRING
{
makeHotspot();
dynamic_cast<Hotspot*>(last_element)->setY($4);
}
					| hotspot_options XUNITS_SYM EQ STRING
{
makeHotspot();
dynamic_cast<Hotspot*>(last_element)->setXunits($4);
}
					| hotspot_options YUNITS_SYM EQ STRING
{
makeHotspot();
dynamic_cast<Hotspot*>(last_element)->setYunits($4);
}
;

label_style_start: TAG_OPEN LABEL_STYLE_SYM options TAG_CLOSE
{
last_element->AddChild(new LabelStyle($3));
last_element = last_element->GetLastChild();
}
;

label_style_end: TAG_OPEN TAG_END LABEL_STYLE_SYM TAG_CLOSE
{
last_element = last_element->GetParent()
}
;

label_style: /* empty */
						| label_style color_start color color_end
						| label_style scale_start scale scale_end
;

scale_start: TAG_OPEN SCALE_SYM options TAG_CLOSE
{
last_element->AddChild(new Scale($3));
last_element = last_element->GetLastChild();
}
;

scale: NUMBER
{
last_element->AddChild(new numbernode($1));
}
;

scale_end: TAG_OPEN TAG_END SCALE_SYM TAG_CLOSE
{
last_element = last_element->GetParent()
}
;

line_style_start: TAG_OPEN LINE_STYLE_SYM options TAG_CLOSE
{
last_element->AddChild(new LineStyle($3));
last_element = last_element->GetLastChild();
}
;

line_style_end: TAG_OPEN TAG_END LINE_STYLE_SYM TAG_CLOSE
{
last_element = last_element->GetParent()
}
;

line_style: /* empty */
						| line_style color_start color color_end
						| line_style width_start width width_end
;

width_start: TAG_OPEN WIDTH_SYM options TAG_CLOSE
{
last_element->AddChild(new Width($3));
last_element = last_element->GetLastChild();
}
;

width: NUMBER
{
last_element->AddChild(new numbernode($1));
}
;

width_end: TAG_OPEN TAG_END WIDTH_SYM TAG_CLOSE
{
last_element = last_element->GetParent()
}
;

poly_style_start: TAG_OPEN POLY_STYLE_SYM options TAG_CLOSE
{
last_element->AddChild(new PolyStyle($3));
last_element = last_element->GetLastChild();
}
;

poly_style_end: TAG_OPEN TAG_END POLY_STYLE_SYM TAG_CLOSE
{
last_element = last_element->GetParent()
}
;

poly_style: /* empty */
						| poly_style color_start color color_end
						| poly_style fill_start fill fill_end
						| poly_style outline_start outline outline_end
;

color_start: TAG_OPEN COLOR_SYM options TAG_CLOSE
{
last_element->AddChild(new Color($3));
last_element = last_element->GetLastChild();
}
;

color: TEXT
{
last_element->AddChild(new textnode($1));
}
;

color_end: TAG_OPEN TAG_END COLOR_SYM TAG_CLOSE
{
last_element = last_element->GetParent()
}
;

fill_start: TAG_OPEN FILL_SYM options TAG_CLOSE
{
last_element->AddChild(new Fill($3));
last_element = last_element->GetLastChild();
}

;

fill: BOOLEAN_VAL
{
last_element->AddChild(new boolnode($1));
}
;

fill_end: TAG_OPEN TAG_END FILL_SYM TAG_CLOSE
{
last_element = last_element->GetParent()
}
;

outline_start: TAG_OPEN OUTLINE_SYM options TAG_CLOSE
{
last_element->AddChild(new Outline($3));
last_element = last_element->GetLastChild();
}
;

outline: BOOLEAN_VAL
{
last_element->AddChild(new boolnode($1));
}
;

outline_end: TAG_OPEN TAG_END OUTLINE_SYM TAG_CLOSE
{
last_element = last_element->GetParent()
}
;

folder_start: TAG_OPEN FOLDER_SYM options TAG_CLOSE
{
last_element->AddChild(new Folder($3));
last_element = last_element->GetLastChild();
}
; 

folder_end: TAG_OPEN TAG_END FOLDER_SYM TAG_CLOSE
{
last_element = last_element->GetParent()
}
;

folder:  /* empty */
				| folder name_start name name_end
				| folder visibility_start visibility visibility_end
				| folder description_start description description_end
                                | folder placemark_start placemark placemark_end

;

visibility_start: TAG_OPEN VISIBILITY_SYM options TAG_CLOSE
{
last_element->AddChild(new Visibility($3));
last_element = last_element->GetLastChild();
}
;

visibility: BOOLEAN_VAL
{
last_element->AddChild(new boolnode($1));
}
;

visibility_end: TAG_OPEN TAG_END VISIBILITY_SYM TAG_CLOSE
{
last_element = last_element->GetParent()
}
;



description_start: TAG_OPEN DESCRIPTION_SYM options TAG_CLOSE
{
last_element->AddChild(new Description($3));
last_element = last_element->GetLastChild();
}
;

description: TEXT
{
last_element->AddChild(new textnode($1));
}
;

description_end:  TAG_OPEN TAG_END DESCRIPTION_SYM TAG_CLOSE
{
last_element = last_element->GetParent()
}
;

options:  /* emptty */ {$$ = NULL}
				| options attr EQ STRING {$$ = $4}
;

attr: /* empty */
			| ID_SYM
;	
