#ifndef UTEIS_H
#define UTEIS_H

using namespace std;


#include <string>

bool isOperador(string c);

bool isNumber(string c);

string replaceAll(string str, const string& from, const string& to);

int precedencia(string c);

bool comparaPrecedencia (string op1, string op2);

double operacao(double x, double y, string op);

#endif