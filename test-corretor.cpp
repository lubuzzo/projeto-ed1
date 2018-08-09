#include "corretor.h"

#include <iostream>

int main() {
  Corretor corretor;
  
  corretor.getDicionario().display();

  if (corretor.getDicionario().buscar("tradicional"))
    std::cout << "está no dicionário" << '\n';
  else
    std::cout << "não está no dicionário" << '\n';

  return 0;
}
