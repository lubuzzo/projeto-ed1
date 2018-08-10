#pragma once

#include <string.h>
#include <iostream>

using namespace std;

class Palavra {
  private:
    string palavra;

  public:

    Palavra() {
      palavra = "";
    }

    Palavra(string x) {
      palavra = x;
    }

    Palavra(char x) {
      palavra = x;
    }

    int compare_string(char *primeiro, char *segundo) {
      while (*primeiro == *segundo) {
        if (*primeiro == '\0' || *segundo == '\0')
          break;

        primeiro++;
        segundo++;
      }

      if (*primeiro == '\0' && *segundo == '\0')
        return 0;
      else
        return -1;
    }

    string getPalavra() {
      return this->palavra;
    }

	/* 'firstTwoLetters' irá receber as duas primeiras letras da palavra no nó e retornar para arvore.h */
	string getFirstTwoLetters() {
		string firstTwoLetters;

		firstTwoLetters = this->palavra[0] + this->palavra[1];

		return firstTwoLetters;
	}

    void setText(string texto) {
      this->palavra = texto;
    }

    bool operator==(Palavra outra) {
      return (!(this->getPalavra().compare(outra.getPalavra())));
    }

    void operator=(string x) {
      this->palavra = x;
    }

};
