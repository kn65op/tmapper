/* 
 * File:   node.cpp
 * Author: tomko
 * 
 * Created on 3 czerwiec 2011, 14:26
 */

#include <iosfwd>
#include <iostream>
#include <string>

#include "node.h"
#include "textnode.h"

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
  out << "Children:";
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
    out << **it << "\n";
  }
  return out;
}