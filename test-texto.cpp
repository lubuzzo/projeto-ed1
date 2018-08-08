#include "texto.h"

int main() {

  Texto textin;

  /*
  textin.display();

  std::cout << "conteúdo do arquivo: " << textin.getArquivo() << " exibido" << '\n';

  */

  textin.contexto(3);

  textin.gravarArquivo();


  return 0;
}
