#include <iostream>
#include <string>
using namespace std;

struct No {
  string chave;
  No* proximo;
};

string p(string k){
    No* tmp = new No;
    tmp->proximo = nullptr;
    tmp->chave = k;

    return tmp->chave;
}

int main(){

    cout << p("dasd") << endl;
}