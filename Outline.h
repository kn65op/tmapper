/* 
 * File:   Outline.h
 * Author: tomko
 *
 * Created on 4 czerwiec 2011, 21:33
 */

#ifndef OUTLINE_H
#define	OUTLINE_H

#include <string>

#include "node.h"

class Outline : public node
{
public:
  Outline();
  Outline(std::string *s);
  Outline(std::string s);
  Outline(const Outline& orig);
  virtual ~Outline();
  
  void setText(std::string t);
  std::string getText();

  bool getOutline();
private:
  void init();
};

#endif	/* OUTLINE_H */

