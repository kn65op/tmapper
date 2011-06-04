/* 
 * File:   Style.cpp
 * Author: tomko
 * 
 * Created on 3 czerwiec 2011, 17:15
 */

#include "Style.h"
#include <string>

using namespace std;

Style::Style()
{
  init();
}

Style::Style(std::string* s) :node(s)
{
  init();
}

Style::Style(const Style& orig)
{
}

Style::~Style()
{
}

void Style::init()
{
  name = "Style";
}