/* 
 * File:   Fill.h
 * Author: tomko
 *
 * Created on 4 czerwiec 2011, 21:30
 */

#ifndef FILL_H
#define	FILL_H

#include <string>

#include "node.h"

class Fill : public node
{
public:
  Fill();
  Fill(std::string *s);
  Fill(const Fill& orig);
  virtual ~Fill();

  bool getFill();
private:
  void init();
};

#endif	/* FILL_H */

