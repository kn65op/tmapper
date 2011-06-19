/* 
 * File:   numbernode.h
 * Author: tomko
 *
 * Created on 4 czerwiec 2011, 21:03
 */

#ifndef NUMBERNODE_H
#define	NUMBERNODE_H

#include <string>

#include "node.h"

class numbernode : public node
{
public:
  numbernode();
  numbernode(std::string *s);
  numbernode(const numbernode& orig);
  virtual ~numbernode();

  void saveToFile(std::string file, int level);

  int getVal() const
  {
    return val;
  }

  void setVal(int val)
  {
    this->val = val;
  }


private:
  double val;
  void init();
};

#endif	/* NUMBERNODE_H */

