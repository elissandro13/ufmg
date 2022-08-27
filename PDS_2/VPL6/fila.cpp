#include "fila.h"



  // Retorna o primeiro elemento da fila.
  // Precondição: a fila *não* pode estar vazia.  
Fila::Fila() {

    primeiro_ = nullptr;
    ultimo_ = nullptr;
}


string Fila::primeiro() {

    if(vazia())
        return NULL;

    return primeiro_->chave;
}

  // Retorna o último elemento da fila.
  // Precondição: a fila *não* pode estar vazia.  
string Fila::ultimo() {

    if(vazia())
        return NULL;

    return ultimo_->chave;
}

  // Informa se a fila está vazia.
bool Fila::vazia() {

    return (primeiro_ == nullptr);
}

  // Insere um elemento no fim da fila.
void Fila::Inserir(string k) {

    if(tamanho() == 0){
        No* tmp = new No{k,nullptr};
        primeiro_ = tmp;
        ultimo_ = tmp;

    } else if(tamanho() == 1) {
        ultimo_ = new No{k, nullptr};
        primeiro_->proximo = ultimo_;

    } else {

        No* tmp = new No{k,nullptr};

        ultimo_->proximo = tmp;
        ultimo_ = tmp;


    }


}

  // Remove o elemento no início da fila. 
  // Precondição: a fila *não* pode estar vazia.
void Fila::Remover() {
    if(vazia())
        return;


    No* tmp = primeiro_;
    primeiro_ = primeiro_->proximo;
    delete tmp;
    
}

  // Retorna o número de elementos na fila.
int Fila::tamanho() {

    if(vazia())
        return 0;

    int cont = 1;
    No* tmp = primeiro_;
    for(No* tmp = primeiro_; tmp->proximo != nullptr; tmp = tmp->proximo){
        cont++;
        
        
        //cout << "chegou" << cont << endl;
        
    }

    return cont;
}

  // Libera toda a memória alocada para a fila.
Fila::~Fila() {
    while(!vazia()){
        Remover();
    }

}