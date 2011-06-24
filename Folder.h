/* 
 * File:   Folder.h
 * Author: tomko
 *
 * Created on 3 czerwiec 2011, 16:39
 */

#ifndef FOLDER_H
#define	FOLDER_H

#include "node.h"
#include <string>

class Folder : public node
{
public:
  Folder();
  Folder(std::string *s);
  Folder(const Folder& orig);
  virtual ~Folder();

  void paintEditWindow(GtkWidget *box);
  void saveFromEditWindow(GtkWidget *box);

private:
  void init();
};

#endif	/* FOLDER_H */

