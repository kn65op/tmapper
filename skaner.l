%{
#include <string>
#include <iostream>
#include "parser.hpp"
#define SAVE_TOKEN yylval.str = new std::string(yytext, yyleng)
#define TOKEN(t) (yylval->token = t)
extern "C" int yywrap() { };

int lines = 1;
void restart() {lines = 1;}
int flush_lex(void) {YY_FLUSH_BUFFER; int tmp = lines; lines = 1; return tmp;}
int text_able = 0;
int bool_able = 0;


%}

%s TAG
%s TI
%s BOOL

%%


[ \t]                   ;
[\n]                    {/*std::cout << "nwoalinia" << "\n";*/lines++;}
<TAG>kml		{/*std::cout << yytext << " `\n";*/ return KML_SYM;}
<TAG>id                 {/*std::cout << yytext << " ~\n";*/ return ID_SYM;}
<TAG>Document           {/*std::cout << yytext << " .\n";*/ return DOCUMENT_SYM;}
<TAG>Placemark          {/*std::cout << yytext << " ,\n";*/ return PLACEMARK_SYM;}
<TAG>name               {/*std::cout << yytext << " " << text_able  << " m\n";*/ if (!text_able) BEGIN(TI); text_able = !text_able; return NAME_SYM;}
<TAG>Style              {/*std::cout << yytext << " n\n";*/ return STYLE_SYM;}
<TAG>Folder             {/*std::cout << yytext << " b\n";*/ return FOLDER_SYM;}
<TAG>description        {/*std::cout << yytext << " " << text_able  << " v\n";*/ if (!text_able) BEGIN(TI); text_able = !text_able; return DESCRIPTION_SYM;}
<TAG>fill               {/*std::cout << yytext << " c\n";*/ if (!bool_able) BEGIN(BOOL); bool_able = !bool_able; return FILL_SYM;}
<TAG>Point              {/*std::cout << yytext << " x\n";*/ return POINT_SYM;}
<TAG>MultiGeometry      {/*std::cout << yytext << " z\n";*/ return MULTIGEOMETRY_SYM;}
<TAG>innerBoundaryIs    {/*std::cout << yytext << " ;\n";*/ return INNER_BOUNDARY_IS_SYM;}
<TAG>outerBoundaryIs    {/*std::cout << yytext << " l\n";*/ return OUTER_BOUNDARY_IS_SYM;}
<TAG>LineString         {/*std::cout << yytext << " k\n";*/ return LINE_STRING_SYM;}
<TAG>Polygon            {/*std::cout << yytext << " j\n";*/ return POLYGON_SYM;}
<TAG>coordinates        {/*std::cout << yytext << " h\n";*/ return COORDINATES_SYM;}
<TAG>hotSpot            {/*std::cout << yytext << " g\n";*/ return HOTSPOT_SYM;}
<TAG>xunits             {/*std::cout << yytext << " f\n";*/ return XUNITS_SYM;}
<TAG>yunits             {/*std::cout << yytext << " d\n";*/ return YUNITS_SYM;}
<TAG>x                  {/*std::cout << yytext << " s\n";*/ return X_SYM;}
<TAG>y                  {/*std::cout << yytext << " a\n";*/ return Y_SYM;}
<TAG>Icon               {/*std::cout << yytext << " ]\n";*/ return ICON_SYM;}
<TAG>scale              {/*std::cout << yytext << " [\n";*/ return SCALE_SYM;}
<TAG>outline            {/*std::cout << yytext << " p\n";*/ if (!bool_able) BEGIN(BOOL); bool_able = !bool_able; return OUTLINE_SYM;}
<TAG>color              {/*std::cout << yytext << " o\n";*/ if (!text_able) BEGIN(TI); text_able = !text_able; return COLOR_SYM;}
<TAG>LabelStyle         {/*std::cout << yytext << " i\n";*/ return LABEL_STYLE_SYM;}
<TAG>styleUrl           {/*std::cout << yytext << " u\n";*/ if (!text_able) BEGIN(TI); text_able = !text_able; return STYLE_URL_SYM;}
<TAG>LineStyle          {/*std::cout << yytext << " y\n";*/ return LINE_STYLE_SYM;}
<TAG>PolyStyle          {/*std::cout << yytext << " t\n";*/ return POLY_STYLE_SYM;}
<TAG>IconStyle          {/*std::cout << yytext << " r\n";*/ return ICON_STYLE_SYM;}
<TAG>LinearRing         {/*std::cout << yytext << " e\n";*/ return LINEAR_RING_SYM;}
<TAG>href               {/*std::cout << yytext << " " << text_able  << " w\n";*/ if (!text_able) BEGIN(TI); text_able = !text_able; return HREF_SYM;}
<TAG>visibility         {/*std::cout << yytext << " 0\n";*/ if (!bool_able) BEGIN(BOOL); bool_able = !bool_able; return VISIBILITY_SYM;}
<TAG>width              {/*std::cout << yytext << " 9\n";*/ return WIDTH_SYM;}
<BOOL>0|1               {/*std::cout << yytext << " 8\n";*/ SAVE_TOKEN; BEGIN(0); return BOOLEAN_VAL;}
<TI>[^<>]+              {/*std::cout << yytext << " 1\n";*/ SAVE_TOKEN; BEGIN(0); int i=0; while ((i = yylval.str->find('\n', i+1)) != std::string::npos) lines++; return TEXT;}
-?[0-9]+\.?[0-9]*       {/*std::cout << yytext << " 7\n";*/ SAVE_TOKEN; return NUMBER;}
 \"[^"]*\"              {/*std::cout << yytext << " 6\n";*/ SAVE_TOKEN; return STRING;}
"<"			{/*std::cout << yytext << " 5\n";*/ BEGIN(TAG); return TAG_OPEN;}
">"         		{/*std::cout << yytext << " 4\n";*/ return TAG_CLOSE;}
<TAG>"/"                {/*std::cout << yytext << " 3\n";*/ return TAG_END;}
","                     {/*std::cout << yytext << " 2\n";*/ return COMMA;}
<TAG>"="                {/*std::cout << yytext << " =\n";*/ return EQ;}
<TAG>.                  {/*std::cout << "Niedozwolony znak!\n";*/ return SYM_NOT_VALID;}

%%
