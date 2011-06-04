/* 
 * File:   Visibility.h
 * Author: tomko
 *
 * Created on 3 czerwiec 2011, 22:04
 */

#ifndef VISIBILITY_H
#define	VISIBILITY_H

#include <string>

#include "node.h"


class Visibility : public node
{
public:
  Visibility();
  Visibility(std::string *s);
  Visibility(const Visibility& orig);
  virtual ~Visibility();
private:
  void init();
};

#endif	/* VISIBILITY_H */

