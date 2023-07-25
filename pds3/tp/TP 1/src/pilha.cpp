#include <iostream>
#include "pilha.h"

using namespace std;


template <class T> Pilha<T>::Pilha() {
    primeiro = nullptr;

};

template <class T> bool Pilha<T>::vazio() {
    return (primeiro == nullptr);
};

template <class T> int Pilha<T>::tamanho() {
    if(vazio())
        return 0;

    int cont = 1;
    for(No<T>* tmp = primeiro; tmp->proximo != nullptr; tmp = tmp->proximo){
        cont++;
        
    }

    return cont;
};


template <class T> T Pilha<T>::pegaTopo() {
    return primeiro->elemento;
};

template <class T> void Pilha<T>::Remover() {
    if(vazio())
        return;

    No<T>* tmp = primeiro;
    primeiro = primeiro->proximo;
    delete tmp;

};

template <class T> T Pilha<T>::desempilha() {
    if(vazio())
        return 0;
    No<T>* tmp = primeiro;
    primeiro = primeiro->proximo;
    T num = tmp->elemento;
    delete tmp;

    return num;
};

template <class T> void Pilha<T>::empilha(T x) {
    if(tamanho() == 0)
    {
        No<T>* tmp = new No<T>{x,nullptr};
        primeiro = tmp;

    } else {
        No<T>* tmp = new No<T>{x,primeiro};
        primeiro = tmp;
    }
};

template <class T> Pilha<T>::~Pilha() {
    while(!vazio())
        Remover();
}

template class Pilha<double>;
template class Pilha<string>;