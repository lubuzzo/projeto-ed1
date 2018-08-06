#include "palavra.h"
#include <iostream>

int main() {
  Palavra teste, teste2;

  teste.setText("oie");

  teste2.setText("oi");

  std::cout << "igual : " << (teste == teste2) << '\n';

  if (teste == teste2)
    std::cout << "String: " << teste.getPalavra() << '\n';
  else
    std::cout << "String1: " << teste.getPalavra() << "\nString2: " << teste2.getPalavra() << '\n';

  return 0;
}
