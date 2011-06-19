/* 
 * File:   Analiser.cpp
 * Author: tomko
 * 
 * Created on 18 maj 2011, 16:56
 */

#include "Analiser.h"
#include <cstdio>
#include <iostream>

#include "KML.h"
#include "tree.h"


extern void yy_flush_buffer();

Analiser::Analiser(std::string f) : filename(f)
{
  tree = 0;
  kml = 0;
}

Analiser::Analiser()
{
  tree = 0;
  kml = 0;
}

Analiser::Analiser(const Analiser& orig)
{
}

Analiser::~Analiser()
{
}

void Analiser::Analise()
{
  yyin = fopen(filename.c_str(), "r");
  if (!yyin)
  {
    kml = 0;
    return;
  }
  yyparse() ? std::cout << "Źle\n" : std::cout << "OK\n";
  fclose(yyin);
  yyin = 0;
  kml = tree;
}

void Analiser::saveKMLToFile(std::string file)
{
  if (kml)
  {
    kml->saveToFile(file, 0);
  }
  else
  {
    kml = new KML();
    kml->saveToFile(file, 0);
  }
}