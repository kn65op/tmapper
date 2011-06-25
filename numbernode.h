/* 
 * File:   numbernode.h
 * Author: tomko
 *
 * Created on 4 czerwiec 2011, 21:03
 */

#ifndef NUMBERNODE_H
#define	NUMBERNODE_H

#include <string>
#include <gtk-2.0/gtk/gtk.h>

#include "node.h"

class numbernode : public node
{
public:
  numbernode();
  numbernode(std::string *s);
  numbernode(std::string s);
  numbernode(const numbernode& orig);
  virtual ~numbernode();

  void saveToFile(std::string file, int level);
  void makeTree(GtkTreeStore* treestore, GtkTreeIter* parent);
  bool ifRemove();
  bool ifShow();
  
  void setVal(std::string val);

  double getVal() const
  {
    return val;
  }

  void setVal(double val)
  {
    this->val = val;
  }


private:
  double val;
  void init();
};

#endif	/* NUMBERNODE_H */

