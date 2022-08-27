#include "usuario.hpp"

Usuario::Usuario(const std::string& login, const std::string& password) {
  
  password_ = password;
  login_ = login;
}

std::string Usuario::getLogin() const {
  
  return login_;
}

std::string Usuario::getPassword() const {
  
  return password_;
}

void Usuario::setPassword(const std::string& password) {
  password_ = password;
}

void Usuario::setLogin(const std::string& login) {
  login_ = login;
}