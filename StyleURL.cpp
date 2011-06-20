/* 
 * File:   StyleURL.cpp
 * Author: tomko
 * 
 * Created on 4 czerwiec 2011, 19:15
 */

#include "StyleURL.h"

#include <string>

#include "node.h"
#include "textnode.h"
#include "KML.h"
#include "IconStyle.h"
#include "LabelStyle.h"
#include "LineStyle.h"
#include "PolyStyle.h"
#include "Placemark.h"

using namespace std;

StyleURL::StyleURL()
{
  init();
}

StyleURL::StyleURL(std::string* s) : node(s)
{
  init();
}

StyleURL::StyleURL(const StyleURL& orig)
{
}

StyleURL::~StyleURL()
{
}

void StyleURL::init()
{
  name = "styleUrl";
}

void StyleURL::connectStyle(KML* kml)
{
  node *style = kml->getStyle(dynamic_cast<textnode*> (children.front())->getText().substr(1));
  if (dynamic_cast<IconStyle*> (style))
  {
    dynamic_cast<Placemark*> (parent)->setIconstyle(dynamic_cast<IconStyle*> (style));
  }
  else if (dynamic_cast<LabelStyle*> (style))
  {
    dynamic_cast<Placemark*> (parent)->setLabelstyle(dynamic_cast<LabelStyle*> (style));
  }
  else if (dynamic_cast<PolyStyle*> (style))
  {
    dynamic_cast<Placemark*> (parent)->setPolystyle(dynamic_cast<PolyStyle*> (style));
  }
  else if (dynamic_cast<LineStyle*> (style))
  {
    dynamic_cast<Placemark*> (parent)->setLinestyle(dynamic_cast<LineStyle*> (style));
  }
}