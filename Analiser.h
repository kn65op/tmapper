/* 
 * File:   Analiser.h
 * Author: tomko
 *
 * Created on 18 maj 2011, 16:56
 */

#ifndef ANALISER_H
#define	ANALISER_H

#include <string>

class KML;


extern int yyparse();
extern FILE * yyin;

class Analiser
{
public:
  Analiser(std::string);
  Analiser();
  Analiser(const Analiser& orig);
  virtual ~Analiser();
  int Analise(void);
  void saveKMLToFile(std::string file);


  std::string GetFilename() const
  {
    return filename;
  }

  void SetFilename(std::string filename)
  {
    this->filename = filename;
  }

  KML* GetKML() const
  {
    return kml;
  }

  void SetKML(KML* kml)
  {
    this->kml = kml;
  }


private:
  std::string filename;
  KML *kml;
};

#endif	/* ANALISER_H */

