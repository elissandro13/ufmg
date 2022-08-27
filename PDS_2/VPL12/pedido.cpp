#include "pedido.hpp"


Pedido::~Pedido() {
  // TODO: Implemente este metodo.
  for (auto it = m_produtos.begin(); it != m_produtos.end(); ++it) {

      delete *it;
  }
}

void Pedido::setEndereco(const std::string& endereco) {
  
  m_endereco = endereco;
}

float Pedido::calculaTotal() const {
  float total = 0;

  for (auto it = m_produtos.begin(); it != m_produtos.end(); ++it){
      total += (*it)->getQtd() * (*it)->getValor();
  }

  return total;
}


void Pedido::adicionaProduto(Produto* p) {
  
  m_produtos.push_back(p);

}

std::string Pedido::resumo() const {
  // TODO: Implemente este metodo.
  /**
   * Aqui voce deve percorrer a lista de produtos para criar um resumo completo
   * do pedido. A cada iteracao, utilize o metodo descricao de cada produto para
   * montar o resumo do pedido. Por fim, adicione o endereco de entrega.
   *
   */

  std::string resumo = "";
  for (auto it = m_produtos.begin(); it != m_produtos.end(); ++it){
      //std::cout << "olou ou " << (*it)->descricao() << "acabio \n";
      resumo += (*it)->descricao() + "\n";
  }

  resumo += "Endereco: " + m_endereco + "\n";

  //std::cout << "resumooooo " << resumo << "acabio \n";
  return resumo;
}