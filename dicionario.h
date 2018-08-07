#include <iostream>
#include <fstream>
#include <sstream>

#include "arvore.h"

class Dicionario {
private:
  Arvore t;

public:
  Dicionario() {
    std::string line;
    std::ifstream infile("dic.txt");
    while (std::getline(infile, line)) {
      t.inserir(line);
    }
  };

  void display() {
    t.display();
  }
};
