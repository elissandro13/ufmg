#include "pilha.h"
#include <string>
#include <iostream>

using namespace std;


bool isOperador(string c) {

    if(c.compare("+") == 0) 
        return true;
    else if(c.compare("*") == 0) 
        return true;
    else if(c.compare("/") == 0) 
        return true;
    else if(c.compare("-") == 0) 
        return true;
    

    return false;

};

bool isNumber(string c) {
    if(!isOperador(c) && c.compare(" ") != 0 && c.compare("  ") != 0 && c.compare("(") != 0 && c.compare(")") != 0)
        return true;
    return false;
};

string replaceAll(string str, const string& from, const string& to) {
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); 
    }
    return str;
};

int precedencia(string c)
{  
    if(c.compare("+") == 0) 
        return 1;
    else if(c.compare("*") == 0) 
        return 2;
    else if(c.compare("/") == 0) 
        return 2;
    else if(c.compare("-") == 0) 
        return 1; 

    return -1; 
                              
}; 

bool comparaPrecedencia (string op1, string op2)  
{  
    int p1 = precedencia(op1);  
    int p2 = precedencia(op2);  
      
    return p1 >= p2;
     
}; 

double operacao(double x, double y, string op){
    //cout << "Opecaao " << x << op << y << endl;
    if(op.compare("+") == 0) 
        return x+y;
    else if(op.compare("*") == 0) 
        return x*y;
    else if(op.compare("/") == 0) {
        if(y == 0) {
            cout << "Divisão por 0 impossível" << endl;
            return 0;
        }
        else {
            return x/y;
        }        
        
    }
        
    else if(op.compare("-") == 0) 
        return x-y;

    return 0;

};