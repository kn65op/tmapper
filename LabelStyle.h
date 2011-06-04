/* 
 * File:   LabelStyle.h
 * Author: tomko
 *
 * Created on 4 czerwiec 2011, 20:52
 */

#ifndef LABELSTYLE_H
#define	LABELSTYLE_H

#include <string>

#include "node.h"

class LabelStyle : public node
{
public:
  LabelStyle();
  LabelStyle(std::string *s);
  LabelStyle(const LabelStyle& orig);
  virtual ~LabelStyle();
private:
  void init();
};

#endif	/* LABELSTYLE_H */

