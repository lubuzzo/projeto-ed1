#pragma once

#include "dicionario.h"
#include "texto.h"
#include <iostream>

class Corretor {
private:
  Dicionario dicio;
  Texto textin;

public:
  Corretor () {
    //getDicionario().display();
  };


  //~Corretor ();

  Dicionario getDicionario() {
    return this->dicio;
  }

  Texto getTexto() {
    return this->textin;
  }

  /* Basicamente, este método que junta tudo, puxa cada palavra do texto
  /* e coloca o dicionário pra pesquisar palavras parecidas */
  void showSimilarWords() {
	  int i = 0;

	  /* Se achou algo, entra e bate a pesquisa*/
	  while(string firstTwoLetters = textin.findSimilarWords(i) != NULL) {
		  dicio.similarWords(firstTwoLetters);
		  ++i; //Incrementa o i para continuar percorrendo o texto
	  }
  }
};
