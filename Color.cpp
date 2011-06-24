/* 
 * File:   Color.cpp
 * Author: tomko
 * 
 * Created on 4 czerwiec 2011, 21:00
 */

#include "Color.h"

using namespace std;

#include <string>
#include <sstream>

#include "node.h"
#include "textnode.h"

Color::Color()
{
  init();
}

Color::Color(std::string *s) : node(s)
{
  init();
}

Color::Color(std::string s)
{
  AddChild(new textnode(s));
  init();
}

Color::Color(const Color& orig)
{
}

Color::~Color()
{
}

void Color::init()
{
  name = "color";
  color_ok = false;
}

double* Color::getColor()
{
  if (color_ok)
  {
    return color;
  }
  int col[4];
  textnode *tn = dynamic_cast<textnode*> (children.front());
  for (int i = 0; i < 4; i++)
  {
    std::stringstream ss;
    ss << std::hex << tn->getText().substr(2 * i, 2);
    ss >> col[i];
    //std::cout << col[i] << " int\n";
    color[3-i] = col[i]/255.0; // zamiana kolorów
  }
  color_ok = true;
  return color;
}

std::string Color::getText()
{
  return dynamic_cast<textnode*>(children.front())->getText();
}

void Color::setText(std::string t)
{
  color_ok = false;
  return dynamic_cast<textnode*>(children.front())->setText(t);
}