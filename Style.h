/* 
 * File:   Style.h
 * Author: tomko
 *
 * Created on 3 czerwiec 2011, 17:15
 */

#ifndef STYLE_H
#define	STYLE_H

#include <string>
#include <list>

#include "node.h"
#include "LabelStyle.h"
#include "IconStyle.h"
#include "LineStyle.h"
#include "PolyStyle.h"
#include "KML.h"

class Style : public node
{
public:
  Style();
  Style(std::string *s);
  Style(const Style& orig);
  virtual ~Style();

  void paintEditWindow(GtkWidget *box);
  void saveFromEditWindow(GtkWidget *box);
  
  std::list<std::string>* getPosibilities();

  void searchStyle(KML *kml);

  IconStyle* getIconstyle() const
  {
    return iconstyle;
  }

  LabelStyle* getLabelstyle() const
  {
    return labelstyle;
  }

  LineStyle* getLinestyle() const
  {
    return linestyle;
  }

  PolyStyle* getPolystyle() const
  {
    return polystyle;
  }


private:
  void init();
  LabelStyle *labelstyle;
  IconStyle *iconstyle;
  LineStyle *linestyle;
  PolyStyle *polystyle;
};

#endif	/* STYLE_H */

