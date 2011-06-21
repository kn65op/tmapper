/* 
 * File:   Width.h
 * Author: tomko
 *
 * Created on 4 czerwiec 2011, 21:29
 */

#ifndef WIDTH_H
#define	WIDTH_H

#include <string>

#include "node.h"

class Width : public node
{
public:
  Width();
  Width(std::string *s);
  Width(const Width& orig);
  virtual ~Width();

  double getWidth();
private:
  void init();
};

#endif	/* WIDTH_H */

