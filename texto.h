/*
  TODO:
    - Falta a parte de percorrer palavra por palavra (integra com a classe Corretor)
    - Falta a parte de alterar uma palavra
    - E o contexto (palavra anterior e a seguinte)
*/

#include "palavra.h"
#include <fstream>
#include <iostream>
#include <list>

class Texto {
private:
  std::list<Palavra> texto;
  std::string arquivo;
  std::ifstream infile;

public:

  std::string getArquivo() {
    return this->arquivo;
  }

  void setArquivo() {
    std::string nome_arquivo;
    std::cout << "Qual o nome do arquivo texto a ser lido?" << '\n';
    std::cin >> nome_arquivo;

    this->arquivo = nome_arquivo;

    infile.open(nome_arquivo);
    if (!(infile)) {
      std::cout << "Erro ao ler o arquivo texto" << '\n';
      exit(1);
    }
  }

  Texto () {
    setArquivo();
    std::string word;
    char x;

    while (!(infile.eof())) {
      while ( infile.get(x) && (x != '\t' && x != '\r' && x != ' ') ) {
        if (x == ',' || x == '.' || x == '?' || x == '!' || x == ':' || x == '\n')
          break;
        word+= x;
      }
      texto.push_back(Palavra(word));
      if (x == ',' || x == '.' || x == '?' || x == '!' || x == ':' || x == '\n')
        texto.push_back(Palavra(x));
      word.clear();
    }
  }

  bool eh_sinal(char x) {
    if (x == ',' || x == '.' || x == '?' || x == '!' || x == ':' || x == '\n')
      return true;
    return false;
  }

  void display(std::ofstream& ofs) {
    std::string content;
    for (Palavra i : texto) {
      content+= i.getPalavra();
      if (!(eh_sinal(i.getPalavra()[0]))) {
        content+= " ";
      } else {
        content.pop_back();
        content.pop_back();
        content+= i.getPalavra();
      }
    }
    ofs << content;
  }

  void display() {
    for (Palavra i : texto) {
      std::cout << i.getPalavra() << '\n';
    }
  }

  void gravarArquivo() {
    char Opcao = 'x';

    do {
      std::cout << "\nDeseja criar um novo arquivo com o texto alterado ou sobreescrever o antigo?" << '\n';
      std::cout << "Aperte 'S' para um novo arquivo ou 'N' para sobreescrever" << '\n';
      std::cin >> Opcao;

      Opcao = tolower(Opcao);

      if (Opcao == 's') {
        novoArquivo();
      }

      if (Opcao == 's' || Opcao == 'n')
        salvarAlteracoes();

    } while((!(Opcao == 's' || Opcao == 'n')));
  }

  void novoArquivo() {
    std::string nome_arquivo;
    std::cout << "Qual o nome do arquivo texto a ser escrito?" << '\n';
    std::cin >> nome_arquivo;

    std::cout << "Gravando as alterações de " << getArquivo() << " em: " << nome_arquivo << '\n';
    this->arquivo = nome_arquivo;
  }

  void salvarAlteracoes() {
    std::ofstream ofs;

    ofs.open(getArquivo());
    if (!(ofs)) {
      std::cout << "Erro ao gravar o arquivo texto" << '\n';
      exit(1);
    }

    display(ofs);

  }

};
