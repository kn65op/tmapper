/* 
 * File:   KML.h
 * Author: tomko
 *
 * Created on 3 czerwiec 2011, 14:14
 */

#ifndef KML_H
#define	KML_H

#include <string>
#include <map>

#include "node.h"

class KML : public node
{
public:
  KML();
  KML(std::string* s);
  KML(const KML& orig);
  virtual ~KML();

  void connectStyles();

  void addStyle(std::string id, node* n);
  node* getStyle(std::string id);

//  void saveToFile(std::string file, int level);
private:
  void init();

  std::map<std::string, node*> styles;
};

#endif	/* KML_H */

