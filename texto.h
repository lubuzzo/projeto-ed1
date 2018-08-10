#pragma once

/*
  TODO:
    - Falta a parte de percorrer palavra por palavra (integra com a classe Corretor)
    - Falta a parte de alterar uma palavra
    - Os métodos de interação com o usuário devem ser movidos para a Classe Corretor
*/

#include "palavra.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Texto {
private:
  std::vector<Palavra> texto;
  std::string arquivo;
  std::ifstream * infile;

public:

  void contexto(int pos) {
	  std::cout << "atual: " << (texto[pos]).getPalavra() << endl; //achei necessário já que o usuário deve saber em qual palavra está

    if ((pos-1) >= 0)
      std::cout << "anterior: " << (texto[pos-1]).getPalavra() << '\n';

    if ((pos+1)<=(texto.size()))
      std::cout << "próxima: " << (texto[pos+1]).getPalavra() << '\n';
  }

  std::string getArquivo() {
    return this->arquivo;
  }

  void setArquivo() {
    std::string nome_arquivo;
    std::cout << "Qual o nome do arquivo texto a ser lido?" << '\n';
    std::cin >> nome_arquivo;

    this->arquivo = nome_arquivo;

    infile->open(nome_arquivo);
    if (!(*infile)) {
      std::cout << "Erro ao ler o arquivo texto" << '\n';
      exit(1);
    }
  }

  Texto () {
    infile = new std::ifstream;
    setArquivo();
    std::string word;
    char x;

    while (!(infile->eof())) {
      while ( infile->get(x) && (x != '\t' && x != '\r' && x != ' ') ) {
        if (eh_sinal(x))
          break;
        word+= x;
      }
      texto.push_back(Palavra(word));
      if (eh_sinal(x))
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
    for (std::vector<Palavra>::iterator i = texto.begin(); i != texto.end(); ++i) {
      content+= i->getPalavra();
      if (!(eh_sinal(i->getPalavra()[0]))) {
        content+= " ";
      } else {
        content.pop_back();
        content.pop_back();
        content+= i->getPalavra();
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

  /* Criei duas variáveis, 'word' e 'firstTwoLetters', 'word' irá receber a palavra na i-ésima posição do vetor texto
  /* e 'firstTwoLetters' irá puxar as primeiras duas letras da string em 'word'. (Com certeza daria pra fazer text[0][0] + texto[0][1] 
  /* direto em 'firstTwoLetters', mas assim fica mais limpo, acho.
  /* Retorna 'firstTwoLetters', se existe. Caso contrário retorna NULL. */
  string findSimilarWords(int i) {
	  string word, firstTwoLetters;

	  if(texto[i]) {
		  cout << texto[i] << ":" << endl;

		  word = texto[i];
		  firstTwoLetters = word[0] + word[1];

		  return firstTwoLetters;
	  } else
		  return NULL; // ******Não sei se vai retornar NULL como string ou NULL mesmo. Testar.
  }

  /* Este método deve supostamente adicionar palavras no dicionário e corrigi-las */
  /****Nota: sinceramente não sei aonde que vai chamar isso aqui, aonde fica as chamadas que o usuário em si vai fazer. Portanto, na chamada criada deve-se passar o i do escopo  */
  void changeDictionary(int i) {
	  int op;

	  /* Primeiro, mostra-se o contexto na tela */
	  contexto(i);

	  /* Depois, o menu */
	  cout << endl << "Selecione uma opção:" << endl;
	  cout << "\t" << "1 - Adicionar palavra atual no dicionário" << endl;
	  cout << "\t" << "2 - Corrigir palavra atual" << endl;

	  if (i <= texto.size())
		  cout << "\t" << "3 - Ir para a próxima palavra" << endl;
	  if (i > 0)
		  cout << "\t" << "4 - Ir para a palavra anterior" << endl;

	  /* Lê a opção do usuário */
	  cin >> op;

	  switch (op) {
		  case 1:
			  //insertTree(texto[pos].getPalavra);
			  break;
		  case 2:
			  //?????
			  break;
		  case 3:
			  changeDictionary(int ++i); //recursão que chama? não consegui pensar em uma forma mais 'inteligente' de fazer isso
			  break;
		  case 4:
			  changeDictionary(int --i);
			  break;
	  }
  }
};
