/* 
 * File:   Description.h
 * Author: tomko
 *
 * Created on 3 czerwiec 2011, 17:20
 */

#ifndef DESCRIPTION_H
#define	DESCRIPTION_H

#include "node.h"

#include <string>

class Description : public node
{
public:
  Description();
  Description(std::string* s);
  Description(std::string s);
  Description(const Description& orig);
  virtual ~Description();
  
  bool ifShow();
  
  void setText(std::string t);
  std::string getText();
  
private:
  void init();
};

#endif	/* DESCRIPTION_H */

