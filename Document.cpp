/* 
 * File:   Document.cpp
 * Author: tomko
 * 
 * Created on 3 czerwiec 2011, 16:10
 */

#include "Document.h"

#include <string>

using namespace std;

Document::Document()
{
  init();
}

Document::Document(std::string* s) :node(s)
{
  init();
}

Document::Document(const Document& orig)
{
}

Document::~Document()
{
}

void Document::init()
{
  name = "Document";
}