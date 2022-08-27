#include "vetor.h"
#include <string>





Vetor::Vetor(int inicio, int fim) {

    inicio_ = inicio;
    fim_ = fim;
    int tam = fim -(inicio);

    if(tam < 0)
        -tam;
    
    tam++;

    elementos_ = new string[tam];

    for(int i = 0; i < tam; i++)
        elementos_[i] = '0';

}

void Vetor::atribuir(int i, std::string valor) {
    // PRECONDIÇÃO: i está dentro do intervalo de índices do vetor.
    if(!(i >= inicio_ && i<=  fim_))
        return;

   
    int index = i -(inicio_);

    elementos_[index] = valor;


}


string Vetor::valor(int i) const {

    int index = i -(inicio_);
    if(!(i >= inicio_ && i<=  fim_) || elementos_[index] !=)
        return NULL;
    // (1) i está dentro do intervalo de índices do vetor.
    // (2) i foi inicializando anteriormente.
    return elementos_ [index];

}

Vetor::~Vetor() {

    delete[] elementos_;
}
