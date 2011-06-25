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
  Hotspot(std::string x, std::string y, std::string xunits, std::string yunits);
  Hotspot(const Hotspot& orig);
  virtual ~Hotspot();

  void saveToFile(std::string file, int level);
  void makeTree(GtkTreeStore* treestore, GtkTreeIter* parent);
  void setAll(std::string x, std::string y, std::string xunits, std::string yunits);
  node* findFromTreeView(std::string s);

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
    if (x->find(".") != std::string::npos) x->replace(x->find("."), 1, ",");
    this->x = atof(x->substr(1, x->size() - 2).c_str());
    delete x;
  }

  void setX(std::string x)
  {
    if (x.find(".") != std::string::npos) x.replace(x.find("."), 1, ",");
    this->x = atof(x.c_str());
  }

  std::string getXunits() const
  {
    return xunits;
  }

  void setXunits(std::string xunits)
  {
    if (xunits == "")
    {
      xunits = "\"\"";
    }
    else
    {
      if (xunits[0] != '"')
      {
        xunits.insert(xunits.begin(), '"');
      }
      if (xunits[xunits.size() - 1] != '"')
      {
        xunits.insert(xunits.end(), '"');
      }
    }
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
    if (y->find(".") != std::string::npos) y->replace(y->find("."), 1, ",");
    this->y = atof(y->substr(1, y->size() - 2).c_str());
    delete y;
  }

  void setY(std::string y)
  {
    if (y.find(".") != std::string::npos) y.replace(y.find("."), 1, ",");
    this->y = atof(y.c_str());
  }

  std::string getYunits() const
  {
    return yunits;
  }

  void setYunits(std::string yunits)
  {
    if (yunits == "")
    {
      yunits = "\"\"";
    }
    else
    {
      if (yunits[0] != '"')
      {
        yunits.insert(yunits.begin(), '"');
      }
      if (yunits[yunits.size() - 1] != '"')
      {
        yunits.insert(yunits.end(), '"');
      }
    }
    this->yunits = yunits;
  }

  void setYunits(std::string *yunits)
  {
    this->yunits = *yunits;
    delete yunits;
  }


private:
  double x, y;
  std::string xunits, yunits;
  void init();
};

#endif	/* HOTSPOT_H */

