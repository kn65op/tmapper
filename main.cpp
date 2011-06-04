#include <iostream>
#include <cstdio>

#include "Analiser.h"
#include "MainWindow.h"
#include "tree.h"
#include "KML.h"

int main(int argc, char **argv)
{
  MainWindow *gui = new MainWindow;

  gui->init(argc,argv);
  gui->build();
  gui->run();

  delete gui;
  /*tree = 0;
  //std::cout << *tree << "\n";
  Analiser a1("test");//, a2("test2"), a3("test3"), a4("test4");
  std::cout << "test: ";
  a1.Analise();
  std::cout << "DRZEWO: \n";
  std::cout << *tree << "\n";*/
  /*std::cout << "test2: ";
  a2.Analise();
  std::cout << "test3: ";
  a3.Analise();
  std::cout << "test4: ";
  a4.Analise();*/
  return 0;
}
