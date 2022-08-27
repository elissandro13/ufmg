#include "google_password.hpp"
#include "usuario.hpp"

#include <iostream>

void GooglePassword::insert(const std::string& url,
                            const std::string& login,
                            const std::string& password) {
  
  /**
   * Lembre-se que as credenciais so podem ser inseridas com as seguintes
   * condicoes:
   * Condicao 1: A senha nao pode ter a seguencia '123456'.
   * Condicao 2: A senha nao pode ter mais do que 50 caracteres (no maximo 50).
   * Condicao 3: A senha nao pode ter menos do que 6 caracteres (no minimo 6).
   * Condicao 4: A senha nao pode ter caracteres em branco ' '.
   *
   * Exemplos de senhas invalidas:
   * 123456
   * test_123456
   * 123456_test
   * test_123456_test
   * senha test
   */
    auto it = m_passwords.find(url);
    if(it == m_passwords.end() && checkPassword(password)) {
        Usuario usertmp(login, password);
        m_passwords.insert(make_pair(url,usertmp));
    }

}

void GooglePassword::remove(const std::string& url) {
   m_passwords.erase(url);
}


void GooglePassword::update(const std::string& url,
                            const std::string& login,
                            const std::string& old_password,
                            const std::string& new_password) {
  
  /**
   * Este metodo nao pode inserir novas credenciais, apenas atualizar as
   * ja existentes. Alem disso, o login e/ou senha do usuario so podem ser
   * atualizados se a senha armazenada no sistema for igual a old_password.
   * Nao esqueca de verificar se o novo password tambem e valido.
   */

   auto it = m_passwords.find(url);
   if(it != m_passwords.end() && it->second.getPassword() == old_password && checkPassword(new_password)) {
        Usuario usertmp(login, new_password);
        it->second = usertmp;
   }

}

void GooglePassword::printPasswords() {
  
  /**
   * Exemplo de saida:
   * 3
   * aaa.site.com: login and password
   * www.site.com: login and password
   * zzz.site.com: login and password
   *
   */

   std::cout << m_passwords.size() << std::endl;

   for (auto it = m_passwords.begin(); it != m_passwords.end(); it++)
    {
        
        std::cout << it->first << ": " << it->second.getLogin()  << " and " << it->second.getPassword()  << std::endl;; 
     
    }
}


bool checkTamanho(const std::string& password)  {

    return password.length() <= 50 && password.length() >= 6;
}


bool checkCaracteresVazios(const std::string& password)  {

    for (int i = 0; i <  password.length(); i++) {
        if(password[i] == ' ')
            return  false;
    }

    return true;
}

bool checkSequencia(const std::string& password)  {    

    for (int i = 0; i <  password.length(); i++) {
        if(password[i] == '1' && i <= password.length() - 5) {
            if(password[i+1] == '2' && password[i+2] == '3' && password[i+3] == '4' && password[i+4] == '5' && password[i+5] == '6')
                return false;
        }
            
    }

    return true;
}

bool GooglePassword::checkPassword(const std::string& password)  const{
  
    return (checkTamanho(password) && checkCaracteresVazios(password) && checkSequencia(password));

}
