/* 
 * File:   Style.cpp
 * Author: tomko
 * 
 * Created on 3 czerwiec 2011, 17:15
 */

#include "Style.h"

#include <string>

#include "node.h"
#include "KML.h"

using namespace std;

Style::Style()
{
  init();
}

Style::Style(std::string* s) : node(s)
{
  init();
}

Style::Style(const Style& orig)
{
}

Style::~Style()
{
}

void Style::init()
{
  name = "Style";
  labelstyle = 0;
  polystyle = 0;
  iconstyle = 0;
  linestyle = 0;
}

void Style::searchStyle(KML* kml)
{
  kml->addStyle(id, this);
  std::list<node*>::const_iterator it, end;
  end = children.end();
  for (it = children.begin(); it != end; it++)
  {
    if (dynamic_cast<IconStyle*> (*it))
    {
      iconstyle = dynamic_cast<IconStyle*> (*it);
    }
    else if (dynamic_cast<LabelStyle*> (*it))
    {
      labelstyle = dynamic_cast<LabelStyle*> (*it);
    }
    else if (dynamic_cast<PolyStyle*> (*it))
    {
      polystyle = dynamic_cast<PolyStyle*> (*it);
    }
    else if (dynamic_cast<LineStyle*> (*it))
    {
      linestyle = dynamic_cast<LineStyle*> (*it);
    }
  }
}