/* 
 * File:   textnode.h
 * Author: tomko
 *
 * Created on 3 czerwiec 2011, 17:31
 */

#ifndef TEXTNODE_H
#define	TEXTNODE_H

#include <string>
#include <gtk-2.0/gtk/gtk.h>

#include "node.h"

class textnode :public node
{
public:
  textnode();
  textnode(std::string *t);
  textnode(std::string t);
  textnode(const textnode& orig);
  virtual ~textnode();

  void saveToFile(std::string file, int level);

  void makeTree(GtkTreeStore* treestore, GtkTreeIter* parent);

  std::string getText() const
  {
    return Text;
  }

  void setText(std::string Text)
  {
    this->Text = Text;
  }

private:
  std::string Text;
  void init();
};

#endif	/* TEXTNODE_H */

