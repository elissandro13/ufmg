#include "venda.hpp"

#include <iomanip>

Venda::~Venda() {
  for (auto it = m_pedidos.begin(); it !=  m_pedidos.end(); ++it) {

      delete *it;
  }
}

void Venda::adicionaPedido(Pedido* p) {
  m_pedidos.push_back(p);
}

void Venda::imprimeRelatorio() const {
  // TODO: Implemente este metodo
  /**
   * Aqui voce tem que percorrer a lista de todos os pedidos e imprimir o resumo
   * de cada um. Por ultimo, devera ser exibido o total de venda e a quantidade
   * de pedidos processados.

    Pedido 1
    2X Pizza Calabresa, 4 pedacos e borda recheada.
    1X Pizza Frango com catupity, 6 pedacos e sem borda recheada.
    2X Hamburguer X-tudo artesanal.
    Endereco: Av. Pres. Antonio Carlos, 6627 - Pampulha, Belo Horizonte - MG
    Pedido 2
    4X Hamburguer X-salada simples.
    1X Comida japonesa - Combo 1, 4 sushis, 5 temakis e 6 hots.
    Endereco: Rua Reitor Pires Albuquerque, ICEx - Pampulha, Belo Horizonte - MG
    Relatorio de Vendas
    Total de vendas: R$ 315.90
    Total de pedidos: 2

   */
    int count = 0;
    float totalVendas = 0;
    for (auto it = m_pedidos.begin(); it !=  m_pedidos.end(); ++it) {

        std::cout << "Pedido " << ++count << std::endl;
        std::cout << (*it)->resumo();
        totalVendas += (*it)->calculaTotal();

    }
    std::cout << "Relatorio de Vendas\n";
    std::cout << std::fixed;
    std::cout << std::setprecision(2);
    std::cout << "Total de vendas: R$ " << totalVendas << std::endl;
    std::cout << "Total de pedidos: " << count << std::endl;
}