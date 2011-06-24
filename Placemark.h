/* 
 * File:   Placemark.h
 * Author: tomko
 *
 * Created on 3 czerwiec 2011, 16:29
 */

#ifndef PLACEMARK_H
#define	PLACEMARK_H

#include "node.h"

class LabelStyle;
class IconStyle;
class LineStyle;
class PolyStyle;
class Icon;
class KML;

#include <string>
#include <gtk-2.0/gtk/gtk.h>

class Placemark: public node
{
public:
  Placemark();
  Placemark(std::string *s);
  Placemark(const Placemark& orig);
  virtual ~Placemark();
  
  void removeStyle(KML *kml);
  
  void paintEditWindow(GtkWidget *box);
  void saveFromEditWindow(GtkWidget *box);
  
  
  IconStyle* getIconstyle() const
  {
    return iconstyle;
  }

  void setIconstyle(IconStyle* iconstyle)
  {
    this->iconstyle = iconstyle;
  }

  LabelStyle* getLabelstyle() const
  {
    return labelstyle;
  }

  void setLabelstyle(LabelStyle* labelstyle)
  {
    this->labelstyle = labelstyle;
  }

  LineStyle* getLinestyle() const
  {
    return linestyle;
  }

  void setLinestyle(LineStyle* linestyle)
  {
    this->linestyle = linestyle;
  }

  PolyStyle* getPolystyle() const
  {
    return polystyle;
  }

  void setPolystyle(PolyStyle* polystyle)
  {
    this->polystyle = polystyle;
  }


private:
  void init();
  LabelStyle *labelstyle;
  IconStyle *iconstyle;
  LineStyle *linestyle;
  PolyStyle *polystyle;
};

#endif	/* PLACEMARK_H */

