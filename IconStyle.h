/* 
 * File:   IconStyle.h
 * Author: tomko
 *
 * Created on 4 czerwiec 2011, 20:49
 */

#ifndef ICONSTYLE_H
#define	ICONSTYLE_H

#include <string>
#include <gtk-2.0/gtk/gtk.h>

#include "node.h"

class IconStyle : public node
{
public:
  IconStyle();
  IconStyle(std::string *s);
  IconStyle(const IconStyle& orig);
  virtual ~IconStyle();
  
  void paintEditWindow(GtkWidget *box);
  void saveFromEditWindow(GtkWidget *box);

  std::string getImage();

  double getX();
  double getY();
  std::string getXunits();
  std::string getYunits();

private:
  void init();
};

#endif	/* ICONSTYLE_H */

