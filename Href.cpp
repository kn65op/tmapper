/* 
 * File:   Href.cpp
 * Author: tomko
 * 
 * Created on 4 czerwiec 2011, 21:27
 */

#include "Href.h"

using namespace std;

#include <string>

#include "node.h"
#include "textnode.h"

Href::Href()
{
  init();
}

Href::Href(std::string *s) : node(s)
{
  init();
}

Href::Href(const Href& orig)
{
}

Href::~Href()
{
}

void Href::init()
{
  name = "href";
}

std::string Href::getText()
{
  return dynamic_cast<textnode*> (children.front())->getText();
}