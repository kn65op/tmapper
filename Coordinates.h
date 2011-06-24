/* 
 * File:   Coordinates.h
 * Author: tomko
 *
 * Created on 4 czerwiec 2011, 19:32
 */

#ifndef COORDINATES_H
#define	COORDINATES_H

#include <string>
#include <vector>
#include <gtk-2.0/gtk/gtk.h>

#include "node.h"

class MainWindow;

class Coordinates : public node
{
public:
  Coordinates();
  Coordinates(std::string *s);
  Coordinates(const Coordinates& orig);
  virtual ~Coordinates();

  void addCoordinate(std::string *x, std::string *y, std::string *z);
  void saveToFile(std::string file, int level);
  void findHW(double& max_x, double& min_x, double& max_y, double& min_y);
  void makeTree(GtkTreeStore* treestore, GtkTreeIter* parent);
  void mapCoordinates(MainWindow *mw,  double a_x, double b_x, double a_y, double b_y);
  node* findFromTreeView(std::string s);

  int getSize() const;

  double* getCoordinates(int i) const
  {
    return coordinates[i];
  }

private:
  std::vector<double*> coordinates;

  void init();
};

#endif	/* COORDINATES_H */

