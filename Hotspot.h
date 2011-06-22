/* 
 * File:   Hotspot.h
 * Author: tomko
 *
 * Created on 4 czerwiec 2011, 21:20
 */

#ifndef HOTSPOT_H
#define	HOTSPOT_H

#include <string>
#include <cstdlib>
#include <gtk-2.0/gtk/gtk.h>

#include "node.h"

class Hotspot : public node
{
public:
  Hotspot();
  Hotspot(std::string *s);
  Hotspot(const Hotspot& orig);
  virtual ~Hotspot();

  void saveToFile(std::string file, int level);
  void makeTree(GtkTreeStore* treestore, GtkTreeIter* parent);

  double getX() const
  {
    return x;
  }

  void setX(double x)
  {
    this->x = x;
  }

  void setX(std::string* x)
  {
    this->x = atoi(x->c_str());
    delete x;
  }

  std::string getXunits() const
  {
    return xunits;
  }

  void setXunits(std::string xunits)
  {
    this->xunits = xunits;
  }

  void setXunits(std::string *xunits)
  {
    this->xunits = *xunits;
    delete xunits;
  }

  double getY() const
  {
    return y;
  }

  void setY(double y)
  {
    this->y = y;
  }

  void setY(std::string* y)
  {
    this->y = atoi(y->c_str());
    delete y;
  }

  std::string getYunits() const
  {
    return yunits;
  }

  void setYunits(std::string yunits)
  {
    this->yunits = yunits;
  }

  void setYunits(std::string *yunits)
  {
    this->yunits = *yunits;
    delete yunits;
  }


private:
  double x,y;
  std::string xunits, yunits;
  void init();
};

#endif	/* HOTSPOT_H */

