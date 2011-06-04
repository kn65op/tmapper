/* 
 * File:   Analiser.h
 * Author: tomko
 *
 * Created on 18 maj 2011, 16:56
 */

#ifndef ANALISER_H
#define	ANALISER_H

#include <string>

extern int yyparse();
extern FILE * yyin;

class Analiser
{
public:
  Analiser(std::string);
  Analiser(const Analiser& orig);
  virtual ~Analiser();
  void Analise(void);
private:
  std::string filename;

};

#endif	/* ANALISER_H */

