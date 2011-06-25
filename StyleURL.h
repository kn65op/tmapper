/* 
 * File:   StyleURL.h
 * Author: tomko
 *
 * Created on 4 czerwiec 2011, 19:15
 */

#ifndef STYLEURL_H
#define	STYLEURL_H

#include <string>

#include "node.h"
#include "KML.h"

class StyleURL : public node
{
public:
  StyleURL();
  StyleURL(std::string *s);
  StyleURL(std::string s);
  StyleURL(const StyleURL& orig);
  virtual ~StyleURL();

  bool ifShow();
  
  void connectStyle(KML *kml);

  void setText(std::string t);
  std::string getText();

private:
  void init();

};

#endif	/* STYLEURL_H */

