/* 
 * File:   Style.h
 * Author: tomko
 *
 * Created on 3 czerwiec 2011, 17:15
 */

#ifndef STYLE_H
#define	STYLE_H

#include <string>

#include "node.h"
#include "KML.h"

class Style :public node
{
public:
  Style();
  Style(std::string *s);
  Style(const Style& orig);
  virtual ~Style();

  void searchStyle(KML *kml);

private:
  void init();
};

#endif	/* STYLE_H */

