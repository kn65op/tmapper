/* 
 * File:   PolyStyle.h
 * Author: tomko
 *
 * Created on 4 czerwiec 2011, 20:58
 */

#ifndef POLYSTYLE_H
#define	POLYSTYLE_H

#include <string>

#include "node.h"

class PolyStyle : public node
{
public:
  PolyStyle();
  PolyStyle(std::string *s);
  PolyStyle(const PolyStyle& orig);
  virtual ~PolyStyle();
  
  void paintEditWindow(GtkWidget *box);
  void saveFromEditWindow(GtkWidget *box);

  bool getFill();
  bool getOutline();
  
  void noFillOk();
  void noOutlineOk();

private:
  void init();

  bool fill;
  bool fill_ok;
  bool outline;
  bool outline_ok;
};

#endif	/* POLYSTYLE_H */

