/* 
 * File:   Href.h
 * Author: tomko
 *
 * Created on 4 czerwiec 2011, 21:27
 */

#ifndef HREF_H
#define	HREF_H

#include <string>

#include "node.h"

class Href : public node
{
public:
  Href();
  Href(std::string *s);
  Href(std::string s);
  Href(const Href& orig);
  virtual ~Href();

  bool ifShow();
  
  std::string getText();
  void setText(std::string t);
private:
  void init();
};

#endif	/* HREF_H */

