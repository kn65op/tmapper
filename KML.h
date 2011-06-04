/* 
 * File:   KML.h
 * Author: tomko
 *
 * Created on 3 czerwiec 2011, 14:14
 */

#ifndef KML_H
#define	KML_H

#include <list>
#include <string>

#include "node.h"

class KML : public node
{
public:
  KML();
  KML(std::string* s);
  KML(const KML& orig);
  virtual ~KML();
private:
  void init();
};

#endif	/* KML_H */

