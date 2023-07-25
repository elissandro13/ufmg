#ifndef EXPRESSOES_H
#define EXPRESSOES_H

#include <string>

using namespace std;

string convertePosfixoInfixo(string exp);

string converteInfixoPosfixo(string infix);

double resolvePostfix(string exp);

double resolveInfixa(string exp);

#endif