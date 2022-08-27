#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>  // Isto é uma dica. 

using namespace std;

int main() {

    string frase;
    string palavra;
    map <string, int> palavras;
    while(getline (cin, palavra)) {
        //cout << palavra;
        
        frase += palavra;
        //frase += " ";
        if(palavra[palavra.size()-1] == '.') {
            
            break;
        }
    };
    //cout << endl << frase;

    istringstream ss(frase);

 
    while(getline(ss, palavra, ' ')) {
        
        if (palavras.count(palavra) == 0)
            palavras.insert({palavra,1});
        else palavras[palavra]++;

    }   

    pair <string,int> comum;

    comum.second = 0;
    for (auto it = palavras.begin(); it != palavras.end(); it++) {
        //if(it.key)
        //cout << endl << it->first << it->second;
        if(it->second > comum.second) {
            comum.first = it->first;
            comum.second = it->second;
        }
    }

    cout << comum.first << endl;



    return 0;
}