/* 
 * File:   textnode.h
 * Author: tomko
 *
 * Created on 3 czerwiec 2011, 17:31
 */

#ifndef TEXTNODE_H
#define	TEXTNODE_H

#include <string>
#include "node.h"

class textnode :public node
{
public:
  textnode();
  textnode(std::string *t);
  textnode(const textnode& orig);
  virtual ~textnode();
private:
  std::string Text;
  void init();
};

#endif	/* TEXTNODE_H */

