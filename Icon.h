/* 
 * File:   Icon.h
 * Author: tomko
 *
 * Created on 4 czerwiec 2011, 21:08
 */

#ifndef ICON_H
#define	ICON_H

#include <string>

#include "node.h"

class Icon : public node
{
public:
  Icon();
  Icon(std::string *s);
  Icon(const Icon& orig);
  virtual ~Icon();

  std::string getImage();
private:
  void init();
};

#endif	/* ICON_H */

