#include "arvore.h"

#include <iostream>

int main() {
  Arvore t;

  if(t.vazia())
    std::cout << "vazia" << '\n';
  else
    std::cout << "não-vazia" << '\n';

  t.inserir("21");
  t.inserir("26");
  t.inserir("16");
  t.inserir("11");
  t.inserir("31");
  t.inserir("06");
  t.inserir("36");
  t.inserir("68");
  t.inserir("44");
  t.inserir("22");
  t.inserir("11");
  t.inserir("90");
  t.inserir("39");
  t.inserir("70");
  t.display();

  if(t.vazia())
    std::cout << "vazia" << '\n';
  else
    std::cout << "não-vazia" << '\n';

  return 0;
}
