#include "dicionario.h"

#include <iostream>

int main() {
  Dicionario dici;

  dici.display();

  dici.inserir("buzzo");
  dici.inserir("buzzinho");

  return 0;
}
