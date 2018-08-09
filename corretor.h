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
};
