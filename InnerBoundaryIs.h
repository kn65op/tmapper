/* 
 * File:   InnerBoundaryIs.h
 * Author: tomko
 *
 * Created on 4 czerwiec 2011, 20:36
 */

#ifndef INNERBOUNDARYIS_H
#define	INNERBOUNDARYIS_H

#include <string>

#include "node.h"

class InnerBoundaryIs : public node
{
public:
  InnerBoundaryIs();
  InnerBoundaryIs(std::string *s);
  InnerBoundaryIs(const InnerBoundaryIs& orig);
  virtual ~InnerBoundaryIs();
  
  bool ifShow();
  
private:
  void init();
};

#endif	/* INNERBOUNDARYIS_H */

