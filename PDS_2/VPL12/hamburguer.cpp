#include "hamburguer.hpp"

std::string Hamburguer::descricao() const {
  // TODO: Implemente este metodo.
  /*
   * Note que aqui voce deve retornar uma descricao detalhada do Hamburguer.
   *
   * Exemplos:
   * 1X Hamburguer X-tudo artesanal.
   * 1X Hamburguer X-tudo simples.
   */
   std::string ater = "";
   if(artesanal_) {
        ater = "artesanal.";
   } else {
        ater = "simples.";
   }

  return std::to_string(m_qtd) + "X " + "Hamburguer "  + tipo_  + " " + ater;
}

Hamburguer::Hamburguer(const std::string& tipo, bool artesanal, int qtd, float valor_unitario) {
    tipo_ = tipo;
    artesanal_ = artesanal;
    m_qtd = qtd;
    m_valor_unitario = valor_unitario;
}