/* 
 * File:   Name.h
 * Author: tomko
 *
 * Created on 3 czerwiec 2011, 17:06
 */

#ifndef NAME_H
#define	NAME_H

#include "node.h"

#include <string>

class Name : public node
{
public:
  Name();
  Name(std::string *s);
  Name(const Name& orig);
  virtual ~Name();

  std::string getText();
  
private:
  void init();
};

#endif	/* NAME_H */

