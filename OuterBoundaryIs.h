/* 
 * File:   OuterBoundaryIs.h
 * Author: tomko
 *
 * Created on 4 czerwiec 2011, 20:34
 */

#ifndef OUTERBOUNDARYIS_H
#define	OUTERBOUNDARYIS_H

#include <string>

#include "node.h"

class OuterBoundaryIs : public node
{
public:
  OuterBoundaryIs();
  OuterBoundaryIs(std::string *s);
  OuterBoundaryIs(const OuterBoundaryIs& orig);
  virtual ~OuterBoundaryIs();
private:
  void init();
};

#endif	/* OUTERBOUNDARYIS_H */

