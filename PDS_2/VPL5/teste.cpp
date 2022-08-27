#include <iostream>
#include <string>


using std::cin;
using std::cout; 
using std::string; 


void index(int inicio, int fim) {

    std::string* elementos_;
    int inicio_ = inicio;
    int tam = fim -(inicio);

    if(tam < 0)
        -tam;
    
    tam++;

    cout << tam << "\n";
    elementos_ = new string[tam];
    cout << "Tamanho:" << sizeof(elementos_)/sizeof(elementos_[0]) << "\n";;

}


int main() {


    index(-10,10);
    index(1,5);
    index(-7,-4);

}