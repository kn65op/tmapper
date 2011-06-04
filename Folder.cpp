/* 
 * File:   Folder.cpp
 * Author: tomko
 * 
 * Created on 3 czerwiec 2011, 16:39
 */

#include "Folder.h"

using namespace std;

Folder::Folder()
{
  init();
}

Folder::Folder(std::string* s): node(s)
{
  init();
}

Folder::Folder(const Folder& orig)
{
}

Folder::~Folder()
{
}

void Folder::init()
{
  name = "Folder";
}