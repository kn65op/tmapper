/* 
 * File:   StyleURL.cpp
 * Author: tomko
 * 
 * Created on 4 czerwiec 2011, 19:15
 */

#include "StyleURL.h"

#include <string>

#include "node.h"

using namespace std;

StyleURL::StyleURL()
{
  init();
}

StyleURL::StyleURL(std::string* s) : node(s)
{
  init();
}

StyleURL::StyleURL(const StyleURL& orig)
{
}

StyleURL::~StyleURL()
{
}

void StyleURL::init()
{
  name = "styleURL";
}