// Copyright 2022 Universidade Federal de Minas Gerais (UFMG)

#include "complexo.h"

#include <cmath>

Complexo::Complexo() {
    modulo_ = 0;  
    argunmento_ = 0;
    cos_ = 0;
    seno_ = 0;
}

Complexo::Complexo(double a, double b) {

    modulo_ = sqrt((a*a)+(b*b));
    argumento_ = sen_ * cos_;
    sen_ = b / modulo_;
    cos_ = a /modulo_;

}

double Complexo::real() {
  return modulo_ * cos_;
}

double Complexo::imag() {
  return modulo_ * sen_;
}

bool Complexo::igual(Complexo x) {
  return (this.modulo_ == x.modulo_ && this.argumento_ == x.argumento_);
}

void Complexo::Atribuir(Complexo x) {

    *this = x;
}

double Complexo::modulo() {
  return modulo_ ;
}

Complexo Complexo::conjugado() {
  Complexo c;
  return c;
}

Complexo Complexo::simetrico() {
  Complexo c;
  return c;
}

Complexo Complexo::inverso() {
  Complexo i;
  return i;
}

Complexo Complexo::somar(Complexo y) {
  Complexo s;
  s.real() = this.real() + y.real();
  s.imag() = this.imag() + y.imag();
  return s;
}

Complexo Complexo::subtrair(Complexo y) {
  Complexo s;
  s.real() = this.real() - y.real();
  s.imag() = this.imag() - y.imag();
  return s;
}

Complexo Complexo::multiplicar(Complexo y) {
  Complexo p;
  return p;
}

Complexo Complexo::dividir(Complexo y) {
  Complexo d;
  return d;
}

