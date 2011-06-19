/* 
 * File:   node.h
 * Author: tomko
 *
 * Created on 3 czerwiec 2011, 14:26
 */

#ifndef NODE_H
#define	NODE_H

#include <list>
#include <iostream>
#include <string>
#include <cairo/cairo.h>

class node
{
public:
  node();
  node(std::string* i);
  node(const node& orig);
  virtual ~node();

  friend std::ostream& operator<<(std::ostream& out, const node& n);

  virtual void saveToFile(std::string file, int level);
  virtual void draw(cairo_t* cr, double a_x, double b_x, double a_y, double b_y);
  virtual void findHW(double& max_x, double& min_x, double& max_y, double& min_y);

  std::list<node*> GetChildren() const
  {
    return children;
  }

  void SetChildren(std::list<node*> children)
  {
    this->children = children;
  }

  node* GetParent() const
  {
    return parent;
  }

  void SetParent(node* parent)
  {
    this->parent = parent;
  }

  void AddChild(node* child)
  {
    children.push_back(child);
    child->SetParent(this);
  }

  void RemoveChild(node* child)
  {
    delete child;
    children.remove(child);
    child = 0;
  }

  std::string GetName() const
  {
    return name;
  }

  void SetName(std::string name)
  {
    this->name = name;
  }

  std::string GetId() const
  {
    return id;
  }

  void SetId(std::string id)
  {
    this->id = id;
  }

  node* GetLastChild()
  {
    return children.back();
  }


protected:
  node *parent;
  std::list<node*> children;
  std::string name;
  std::string id;
  virtual void init()=0;

};

#endif	/* NODE_H */

