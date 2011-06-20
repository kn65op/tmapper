/* 
 * File:   Style.cpp
 * Author: tomko
 * 
 * Created on 3 czerwiec 2011, 17:15
 */

#include "Style.h"

#include <string>

#include "node.h"
#include "KML.h"

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

void Style::searchStyle(KML* kml)
{
  kml->addStyle(id, this);
}