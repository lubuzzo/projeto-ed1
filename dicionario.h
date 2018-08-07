#include <iostream>
#include <fstream>
#include <sstream>

#include "arvore.h"

/* TODO:
    - Precisa da consulta de palavra semelhante (2 primeiras letras iguais)
    - CHecar se o ifstream e o ofstream conseguiram abrir o arquivo
*/

class Dicionario {
private:
  Arvore t;

public:
  //Construtor lê o arquivo e gera a AVL
  Dicionario() {
    std::string line;
    std::ifstream infile("dic.txt");
    while (std::getline(infile, line)) {
      t.inserir(line);
    }
    //Tinha esquecido desse pequeno detalhe
    infile.close();
  };

  //Destrutor vai gravar no arquivo
  //A escrita em disco é lenta, por isso vamos manter a árvore em memória e só escrever em disco ao final
  //Escrevendo, assim, apenas uma vez no disco
  ~Dicionario() {
    t.display_file();
  }

  //Função para printar a árvore
  //Provavelmente só vai servir para debug, mas é necessário
  void display() {
    t.display();
  }

  //Inserir uma palavra no dicionário
  void inserir(std::string x) {
    t.inserir(x);
  }

  //Usa a função de buscar na árvore
  bool buscar(std::string x) {
    return t.buscar(x);
  }
};
