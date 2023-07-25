#include <string>
#include "pilha.h"
#include "uteis.h"
#include <iostream>
#include <sstream>
#include "pilha.h"
#include <algorithm>
#include <iomanip>

using namespace std;


string convertePosfixoInfixo(string exp) {

    string infix="";
    Pilha<string> p;
    exp = replaceAll(exp,"  ", " ");

    istringstream ss(exp);
    string sub_posfix;


    while(getline(ss, sub_posfix, ' ')) {
        
        if(isNumber(sub_posfix))
        {
            p.empilha(sub_posfix);
        }
        else 
        {
            string op1 = p.desempilha();
            string op2 = p.desempilha();
            //cout << "( " + op2 + " " + sub_posfix + " " + op1 + " )" << endl;                      
    
            p.empilha("( " + op2 + " " + sub_posfix + " " + op1 + " )");
        }

    }
    //cout << "---------" << infix << "###########";

    /* while (!p.vazio())
    {
        cout << p.desempilha() << ";";
    }
    */
    

    //infix = "p.desempilha();";

    
    return p.pegaTopo();

};



string converteInfixoPosfixo(string infix) {
    string posfix="";
    //string aux="";
    Pilha<string> p;
    infix = replaceAll(infix,"  ", " ");
    

    p.empilha("(");
    infix += " ";
    infix += ")";
    
    istringstream ss(infix);
    string sub_infix;


    while(getline(ss, sub_infix, ' ')) {
    
        if(sub_infix.compare(" ") == 0)
            continue;
        else if(sub_infix.compare("(") == 0)
            p.empilha(sub_infix);
        else if(isNumber(sub_infix)) {
            //if(sub_infix.compare("(") == 0 || sub_infix.compare(")") == 0)  
                //cout << "linha 95" << endl;
            posfix += " ";
            posfix += sub_infix;            
        } else if (isOperador(sub_infix)) {
            while(!p.vazio() && comparaPrecedencia(p.pegaTopo(), sub_infix))
            {
                //if(sub_infix.compare("(") == 0 || sub_infix.compare(")") == 0)  
                    //cout << "linha 102" << endl;
                posfix += " ";
                posfix += p.desempilha();
                
            }
            p.empilha(sub_infix);
        } else if (sub_infix.compare(")") == 0) {
            while (!p.vazio() && p.pegaTopo().compare("(") != 0)
            {
                //if(sub_infix.compare("(") == 0 || sub_infix.compare(")") == 0)  
                    //cout << "linha 111" << endl;
                posfix += " ";
                posfix += p.desempilha();
                
            }

            p.desempilha();
           
        }
            
        
    }   

    posfix = replaceAll(posfix,"  ", " ");
    if(posfix[0] == ' ')
        posfix = posfix.replace(0,1,"");
    return posfix;

};







double resolvePostfix(string exp) {

    Pilha<double> p;
    exp = replaceAll(exp,"  ", " ");
    istringstream ss(exp);
    string sub_string;
    

    while(getline(ss, sub_string, ' ')) {
      
        if(isOperador(sub_string))
        {
            double y = p.desempilha();
            double x = p.desempilha();
            p.empilha(operacao(x,y,sub_string));
            

        } else {
            
           p.empilha(stod(sub_string));
        }
    
    }

    return p.desempilha();
};


double resolveInfixa(string exp) { 
    Pilha <double> nums;
    Pilha <string> ops;

    exp = replaceAll(exp,"  ", " ");
    istringstream ss(exp);
    string sub_string;
  

    while(getline(ss, sub_string, ' ')) {
    
        if(sub_string.compare(" ") == 0)
            continue;
        
        else if(sub_string.compare("(") == 0){

            ops.empilha(sub_string);

        }

        else if(isNumber(sub_string)) {
            
            
            nums.empilha(stod(sub_string));
        }
        //entra na solução
        else if(sub_string.compare(")") == 0) {

            while (!ops.vazio() && ops.pegaTopo().compare("(") != 0){

                double val2 = nums.desempilha();

                double val1 = nums.desempilha();

                string op = ops.desempilha();
                //cout << "chamada 260";
                nums.empilha(operacao(val1, val2, op));

            }

            //retira parenteses
            if(!ops.vazio())
                string tmp = ops.desempilha();
        }

        else {

            while(!ops.vazio() && comparaPrecedencia(ops.pegaTopo(), sub_string) && isOperador(ops.pegaTopo())){
                
                double y = nums.desempilha();
               
                double x = nums.desempilha();
                     
                string op1 = ops.desempilha();
                         
                nums.empilha(operacao(x, y, op1));
            }
             
            ops.empilha(sub_string);

        }
    }

    //ressolve o resto;
    while(!ops.vazio()){
        double y2 = nums.desempilha();
                
        double x2 = nums.desempilha();
                
        string op2 = ops.desempilha();
                                 
        nums.empilha(operacao(x2, y2, op2));
    }
     

      
    
    return nums.desempilha();
   
};