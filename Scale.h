/* 
 * File:   Scale.h
 * Author: tomko
 *
 * Created on 4 czerwiec 2011, 21:05
 */

#ifndef SCALE_H
#define	SCALE_H

#include <string>

#include "node.h"

class Scale : public node
{
public:
  Scale();
  Scale(std::string *s);
  Scale(const Scale& orig);
  virtual ~Scale();
private:
  void init();
};

#endif	/* SCALE_H */

