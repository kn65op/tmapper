/* 
 * File:   boolnode.h
 * Author: tomko
 *
 * Created on 3 czerwiec 2011, 22:07
 */

#ifndef BOOLNODE_H
#define	BOOLNODE_H

#include "node.h"

class boolnode : public node
{
public:
  boolnode();
  boolnode(std::string * b);
  boolnode(const boolnode& orig);
  virtual ~boolnode();

  void saveToFile(std::string file, int level);

  bool getVal() const
  {
    return val;
  }

  void setVal(bool val)
  {
    this->val = val;
  }


private:
  bool val;
  void init();
};

#endif	/* BOOLNODE_H */

