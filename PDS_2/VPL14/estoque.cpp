#include <string>
#include <map>
#include "Estoque.hpp"
#include <iostream>


void Estoque::add_mercadoria(const std::string& mercadoria, unsigned int qtd) {

    if(m_estoque.find(mercadoria) != m_estoque.end()) {
        m_estoque[mercadoria] += qtd;
        return;
    }
    m_estoque.insert(make_pair(mercadoria,qtd));

}

void Estoque::sub_mercadoria(const std::string& mercadoria, unsigned int qtd) {
  
  if(m_estoque.find(mercadoria) == m_estoque.end() || m_estoque[mercadoria] < qtd) {
    
    std::cout << mercadoria << " inexistente" << std::endl;
    return;
  }
  m_estoque[mercadoria] -= qtd;
}

unsigned int Estoque::get_qtd(const std::string& mercadoria) const {
  // TODO
  auto it = m_estoque.find(mercadoria);
  if(it != m_estoque.end())
    return it->second;
  return 0;
}

void Estoque::imprime_estoque() const {

    for(auto it = m_estoque.begin(); it != m_estoque.end(); it++){
        
        std::cout << it->first << ", " << it->second << std::endl;
    }
  // TODO
}

Estoque& Estoque::operator += (const Estoque& rhs) {
  
  for(auto it = rhs.m_estoque.begin(); it != rhs.m_estoque.end(); it++){
        
        this->add_mercadoria(it->first, it->second);
    }
  return *this;
}

Estoque& Estoque::operator -= (const Estoque& rhs) {
  for(auto it = rhs.m_estoque.begin(); it != rhs.m_estoque.end(); it++){
        
        this->sub_mercadoria(it->first, it->second);
    }
  return *this;
}

bool operator < (Estoque& lhs, Estoque& rhs) {
  // TODO
  for(auto it = rhs.m_estoque.begin(); it != rhs.m_estoque.end(); it++){

        std::cout << "Coco" << "p :" << it->second << it->first <<  "s : " <<  std::endl;    
        if(lhs.m_estoque.find(it->first) != lhs.m_estoque.end()) {
            auto o = lhs.m_estoque.find(it->first);
            //if(it->second <= o->second)
            std::cout << "p :" << it->second << it->first <<  "s : " << o->second << o->first << std::endl;
            if(it->second <= o->second)
                return false;
        } else {
            return true;
        }
        
    }
  return true;
}

bool operator > (Estoque& lhs, Estoque& rhs) {
  // TODO
   for(auto it = rhs.m_estoque.begin(); it != rhs.m_estoque.end(); it++){
        
        if(lhs.m_estoque.find(it->first) != lhs.m_estoque.end()) {
            auto o = lhs.m_estoque.find(it->first);
            if(it->second >= o->second)
                return false;
        } else {
            return false;
        }
        
    }
  return true;
}