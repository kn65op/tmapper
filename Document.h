/* 
 * File:   Document.h
 * Author: tomko
 *
 * Created on 3 czerwiec 2011, 16:10
 */

#ifndef DOCUMENT_H
#define	DOCUMENT_H

#include <string>
#include <list>
#include <gtk-2.0/gtk/gtk.h>

#include "node.h"

class Document :public node
{
public:
  Document();
  Document(std::string* s);
  Document(const Document& orig);
  virtual ~Document();
  
  std::list<std::string>* getPosibilities();

  void paintEditWindow(GtkWidget *box);
  void saveFromEditWindow(GtkWidget *box);
  
  //void saveToFile(std::string fill, int level);
private:
  void init();
};

#endif	/* DOCUMENT_H */

