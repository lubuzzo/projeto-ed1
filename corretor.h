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
    verificarTexto();
  };

  ~Corretor() {
    //salvarAlteracoes();
  }

  void verificarTexto() {
    int opcao = 0, pos = -1;
    for (int i = 0; i < textin.getTexto().size(); i++) {
      pos = -1;
      if (!(dicio.buscar(textin.getTexto()[i].getPalavra())) && (!(textin.eh_sinal( textin.getTexto()[i].getPalavra()[0]) )) || (!(textin.getTexto()[i].getPalavra() != " "))) {
        std::cout << "Palavra: " << textin.getTexto()[i].getPalavra() << " não encontrada!" << '\n';
        do {
          std::cout << "\nSelecione uma das opções abaixo:" << '\n';
          std::cout << "1) Corrigir com base em palavras semelhantes" << '\n';
          std::cout << "2) Adicionar ao dicionário" << '\n';
          std::cout << "3) Ignorar" << '\n';
          std::cout << "4) Terminar execução" << '\n';
          std::cin >> opcao;
          if (opcao == 1) {

            dicio.getSemelhantes(textin.getTexto()[i].getPalavra());
            if (dicio.getSizeSemelhantes() > 0) {
              dicio.showSemelhantes();
              std::cin >> pos;
              //std::cout << "o: " << dicio.getSemelhantes(pos) << '\n';
              textin.setTexto(dicio.getSemelhantes(pos), i);
            } else {
              std::cout << "Não foi encontrada recomendações" << '\n';
              break;
            }
          }
          else if (opcao == 2) {
            dicio.inserir(textin.getTexto()[i].getPalavra());
          }
          else if (opcao == 3) {
              break;
          }
          else if (opcao == 4) {
            textin.gravarArquivo();
            dicio.display_file();
            exit(1);
          }

        } while(!(opcao == 1 || opcao == 2 || opcao == 3 || opcao == 4));
      }
    }
    textin.gravarArquivo();
    dicio.display_file();
  }

  Dicionario getDicionario() {
    return this->dicio;
  }

  Texto getTexto() {
    return this->textin;
  }
};
