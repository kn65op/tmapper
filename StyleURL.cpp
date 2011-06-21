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
#include "Style.h"

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
  Style *style =dynamic_cast<Style*> (kml->getStyle(dynamic_cast<textnode*> (children.front())->getText().substr(1)));
  if(!style)
  {
    return;
  }
  if (style->getIconstyle())
  {
    dynamic_cast<Placemark*> (parent)->setIconstyle(style->getIconstyle());
  }
  if (style->getLabelstyle())
  {
    dynamic_cast<Placemark*> (parent)->setLabelstyle(style->getLabelstyle());
  }
  if (style->getPolystyle())
  {
    dynamic_cast<Placemark*> (parent)->setPolystyle(style->getPolystyle());
  }
  if (style->getLinestyle())
  {
    dynamic_cast<Placemark*> (parent)->setLinestyle(style->getLinestyle());
  }
}