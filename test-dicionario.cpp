#include "dicionario.h"

#include <iostream>

int main() {
  Dicionario dici;

  // dici.display();
  //
  // dici.inserir("buzzo");
  // dici.inserir("buzzinho");
  // dici.inserir("dimitri");
  //
  // if (dici.buscar("tradicional"))
  //   std::cout << "está no dicionário" << '\n';
  // else
  //   std::cout << "não está no dicionário" << '\n';
  //
  // dici.inserir("tradicional");
  //
  // if (dici.buscar("tradicional"))
  //   std::cout << "está no dicionário" << '\n';
  // else
  //   std::cout << "não está no dicionário" << '\n';


  dici.getSemelhantes("abacate");
  dici.showSemelhantes();

  return 0;
}
