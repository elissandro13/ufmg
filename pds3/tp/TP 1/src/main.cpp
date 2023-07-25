#include <iostream>
#include <string>
#include <sstream>
#include "pilha.h"
#include <algorithm>
#include <iomanip>
#include "uteis.h"
#include "expressoes.h"
#include <cstring>



using namespace std;

//esse


bool checkIfPostfix(string str){

    istringstream ss(str);
    string sub_str;
    
    while(getline(ss, sub_str, ' ')) {
        if(sub_str.compare("(") == 0 || sub_str.compare(")") == 0)
            return false;
    }

    return true;
};

bool checkIfInfix(string str) {

    return !checkIfPostfix(str);

};

int main() 
{

    string str;
    string ressultado = "";
    string tipo_operacao = "";
    string tipo_convercao = "";
    string express = "";

    int t = 0;

    while (getline(cin, str)) {
        if(t == 0) {

            istringstream ss(str);
            string opcao;
            int i = 0;
            while(getline(ss, opcao, 'A')) {
                if (i == 0 && opcao.compare("LER POSFIX") == 0) {
                    tipo_operacao = "POSFIXA";
                    
                } else if(i == 0 && opcao.compare("LER INFIX") == 0){
                    tipo_operacao = "INFIXA";
                    
                }
                if(i == 1) {
                    express = opcao;
                    break;
                } 
                i++;
            
            }
        } else if (t == 1) {

            if(str.compare("POSFIXA") == 0) {
                tipo_convercao = "POSFIXA";
            } else if(str.compare("INFIXA") == 0){
                tipo_convercao = "INFIXA";
            }

        } else if (t == 2){
            ressultado = str;
            //cout << ressultado;
            break;
        }
        t++;
    }


     cout << fixed << setprecision(6);

    if(express[0] == ' ')
        express = express.replace(0,1,"");
    if(express[0] == ' ')
        express = express.replace(0,1,"");
    
    if(tipo_operacao.compare(tipo_convercao) == 0) {
        if(tipo_convercao.compare("INFIXA")) {
            if(checkIfInfix(express)){
                cout << "EXPRESSAO OK: "<< express << endl;
                cout << "INFIXA: " << resolveInfixa(express) << endl;
            } else {
                cout << "ERRO: "<< express <<" NAO VALIDA" <<endl;
            }
            
        } else {
            if(checkIfPostfix(express)){
                cout << "EXPRESSAO OK: "<< express << endl;
                cout << "POSTIFIXA: " << resolvePostfix(express) << endl;
            } else {
                cout << "ERRO: "<< express <<" NAO VALIDA" <<endl;
            }
        }
    } else if (tipo_convercao.compare("INFIXA") == 0){
        if(checkIfPostfix(express)){
                cout << "EXPRESSAO OK: "<< express << endl;
               cout << "POSTIFIXA: " << resolveInfixa(convertePosfixoInfixo(express)) << endl; 
            } else {
                cout << "ERRO: "<< express <<" NAO VALIDA" <<endl;
            }
       
    } else {
        if(checkIfInfix(express)){
                cout << "EXPRESSAO OK: "<< express << endl;
                cout << "INFIXA: " << resolvePostfix(converteInfixoPosfixo(express)) << endl; 
            } else {
                cout << "ERRO: "<< express <<" NAO VALIDA" <<endl;
            }
        }
    return 0;
};
