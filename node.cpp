/* 
 * File:   node.cpp
 * Author: tomko
 * 
 * Created on 3 czerwiec 2011, 14:26
 */

#include <iosfwd>
#include <iostream>
#include <fstream>
#include <string>

#include "node.h"
#include "textnode.h"
#include "KML.h"

node::node() :id("")
{

}

node::node(std::string *i)
{
  if (i)
  {
    id = i->substr(1, i->size()-2);
    delete i;
  }
  else
  {
    id = "";
  }
}

node::node(const node& orig)
{
}

node::~node()
{
  while(children.size() != 0)
  {
    delete children.front();
    children.erase(children.begin());
  }
}

std::ostream& operator<<(std::ostream& out, const node& n)
{
  out << n.name << "\n";
  if (n.id != "")
  {
    out << "id: " << n.id << "\n";
  }
  else
  {
    out << "no id\n";
  }
  out << "Children of " << n.name << ":";
  if (n.children.empty())
  {
    out << "none\n";
    return out;
  }
  out << "\n";
  std::list<node*>::const_iterator it, end;
  end = n.children.end();
  for (it = n.children.begin(); it != end; it++)
  {
    out << "child of; " << n.name << " " << **it << "\n";
  }
  out << "End of children from " << n.name << "\n";
  return out;
}

void node::saveToFile(std::string file, int level)
{
  std::ofstream of;
  if (dynamic_cast<KML*>(this))
  {
    of.open(file.c_str());
  }
  else
  {
    of.open(file.c_str(), std::ios::app);
    of << "\n";
  }
  for (int i=0; i<level; i++) of << "\t";;
  of << "<" << name;
  if (id != "")
  {
    of << " id=\"" <<  id << "\"";
  }
  of << ">";
  of.close();
  std::list<node*>::const_iterator it, end;
  end = children.end();
  for (it = children.begin(); it != end; it++)
  {
    (*it)->saveToFile(file, level+1);
  }
  of.open(file.c_str(), std::ios::app);
  for (int i=0; i<level; i++) of << "";;
  of << "</" << name << ">\n";
  of.close();
}