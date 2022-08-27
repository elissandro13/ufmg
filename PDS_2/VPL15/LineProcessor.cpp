#include <regex>
#include <math.h>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>


#include "LineProcessor.hpp"

void LinePrinter::processaLinha(const std::string &str) {
  std::cout << str << std::endl;
}

bool ContadorPopRural::linhaValida(const std::string &str) const {
  // Neste exemplo usaremos expressoes regulares para verificar se uma linha
  // eh valida ou nao.
  //
  // Esta expressao regular eh formada por cinco partes. Cada uma dessas
  // partes eh um dos tres tipos de padrao regular abaixo:
  //
  // \\w+ eh qualquer palavra com um ou mais digitos, letras e sublinhas (_)
  // \\s* eh qualquer sequencia de zero ou mais espacos (inclui tab)
  // \\d+ eh qualquer sequencia de um ou mais digitos
  std::regex regularExpr("\\w+\\s*\\d+\\s*\\d+");

  // A funcao regex_match vai retornar verdadeiro se a string str casa-se com
  // a expressao regular que acabamos de criar:
  return std::regex_match(str, regularExpr);
}

void ContadorPopRural::processaLinha(const std::string &str) {
  //
  // Em geral eh mais facil ler dados de uma string se a string eh transformada
  // em um objeto do tipo stringstream:
  std::stringstream ss(str);
  //
  // Iremos ler os dados da string nestas tres variaveis abaixo:
  std::string nomePais;
  unsigned populacao, percUrbana;
  //
  // Como sabemos que a linha contem string int int, podemos fazer a leitura
  // facilmente usando o operador de streaming:
  ss >> nomePais >> populacao >> percUrbana;
  //
  // Note que precisamos arredondar o valor que serah impresso. O arredondamento
  // serah feito via a funcao floor. Ou seja, decimais serao sempre
  // arredondados para baixo:
  unsigned popRural = floor(populacao - (populacao * (percUrbana/100.0)));
  //
  // Uma vez encontrados os valores que precisam ser impressos, seguimos o
  // modelo do enunciado do exercicio:
  std::cout << popRural << " pessoas vivem no campo no " << nomePais <<
    std::endl;
}

bool ContadorNumNaturais::linhaValida(const std::string &str) const {
  // TODO: Implemente este metodo
  //'/^[0-9]+$/'
    //r("[[:digit:]]+");
    //(\s*[0-9]+)+
  std::regex regularExpr("[0-9 ]+");
  //if(std::regex_match(str, regularExpr)) std::cout << "asdasd";
  return std::regex_match(str, regularExpr);
}

void ContadorNumNaturais::processaLinha(const std::string &str) {
  // TODO: Implemente este metodo:
  int soma = 0;
  //std::regex regularExpr("[0-9]+");
  //std::string num = str;
  //str.erase(std::remove(num.begin(), num.end(), ' '), num.end());

  for(int it = 0; it < str.size(); ++it) {
        //std::string num = str[it];
        if(str[it] != ' ')
            soma += int(str[it] - '0');
        //std::cout  << "c: " << str[it] << " = "<< int(str[it] - '0') << "/";
   }
    //std::cout << "Soma: ";
  std::cout << soma << std::endl;
}

bool LeitorDeFutebol::linhaValida(const std::string &str) const {
    // TODO: Implemente este metodo
    //std::string palavra = *str;
    //char *token = strtok(str, " ");
    //std::string palavra = *str;
    //std::string token = palavra.substr(0, palavra.find(delimiter));

    //\d-\d{3}-\d{4}
    // /^[A-Za-z]+$ /[0-9] \ [0-9] 
    //[A-Za-z] [0-9]
    //^[A-Za-z]+ *[0-9] *[A-Za-z]+ *[0-9]
    std::regex regularExpr("^[A-Za-z]+ *[0-9]+ *[A-Za-z]+ *[0-9]+");
  //if(std::regex_match(str, regularExpr)) std::cout << "asdasd";
    return std::regex_match(str, regularExpr);
}

void LeitorDeFutebol::processaLinha(const std::string &str) {
  // TODO: Implemente este metodo:
  //  * America 2000 Atletico 1  -->  Vencedor: America
    std::string time1, time2, ponto;
    int ponto1, ponto2;
    std::regex rgxTime("[A-Za-z]+");
    std::regex rgxPonto("[0-9]+");
    std::smatch match, matchPontos;

    if (std::regex_search(str.begin(), str.end(), match, rgxTime))
            //time1 = match[1];
            //time2 = match[2];

    if (std::regex_search(str.begin(), str.end(), matchPontos, rgxPonto))
            ponto = matchPontos.str(1);
            //std::cout << ponto;
            //ponto2 = std::stoi(matchPontos.str(2));

    //for(std::string::iterator it = ponto.begin(); it != ponto.end(); ++it) {
    //    if(*it == ' ') {
    //        *it = '_';
    //    }
    //}
    int res =  matchPontos.str(1).compare( matchPontos.str(2));
    std::cout << match[1] << match[2] << matchPontos[1] << matchPontos[2];
    //std::cout << "POnto 1 " << ponto;
  std::cout << str <<  " --> "; 
  if(res > 0) {
    std::cout << "Vencedor: " << match[1] << std::endl; 
  } else if(res < 0){
    std::cout << "Vencedor: " << match[2] << std::endl;
  } else {
    std::cout << "Empate"  << std::endl;
  }
}

void ContadorDePalavras::processaLinha(const std::string &str) {
  // TODO: Implemente este metodo:
    std::regex rx("(\\w+)(;|,)*");

   auto words_begin = std::sregex_iterator(str.begin(), str.end(), rx);
   auto words_end = std::sregex_iterator();

   auto count = std::distance(words_begin, words_end);

  std::cout << count << std::endl;
}

bool InversorDeFrases::linhaValida(const std::string &str) const {
  // TODO: Implemente este metodo
  std::regex regularExpr("[A-Za-z ]+");
  //if(std::regex_match(str, regularExpr)) std::cout << "asdasd";
  return std::regex_match(str, regularExpr);
  
}

void InversorDeFrases::processaLinha(const std::string &str) {
  // TODO: Implemente este metodo:
  std::string tmp = "";
  std::vector<std::string> v;
  for(int i = 0; i < str.size(); i++) {
    if(str[i] == ' ' | str[i+1] == '\n') {
        v.push_back(tmp);
        //std::cout << tmp << std::endl;
        tmp = "";

    } else {

        tmp+= str[i];
    }

  }
  v.push_back(tmp);
  //std::cout << "Final: " << tmp << std::endl;
    auto it = v.end();
    while (it != v.begin())
    {
     --it;
        std::cout << *it << std::endl;

    } 
 
  
}

bool EscritorDeDatas::linhaValida(const std::string &str) const {
  std::string dateFormat = "\\s*\\d\\d?/\\d\\d?/\\d{4}";
  std::regex regularExpr("\\s*\\d\\d?/\\d\\d?/\\d{4}");
  // TODO: Implemente este metodo
  // Note que você pode usar uma expressao regular como:
  // "\\s*\\d\\d?/\\d\\d?/\\d{4}" para saber se a linha eh valida:
  //if(std::regex_match(str, regularExpr))
    //cout << "certo";
  return std::regex_match(str, regularExpr);;
}

void EscritorDeDatas::processaLinha(const std::string &str) {
  // TODO: Implemente este metodo:
  // Lembre-se que as iniciais dos meses sao:
  // "Jan", "Fev", "Mar", "Abr", "Mai", "Jun", "Jul", "Ago", "Set", "Out",
  // "Nov", e "Dez".
  std::cout << "Imprime algo aqui!" << std::endl;
}