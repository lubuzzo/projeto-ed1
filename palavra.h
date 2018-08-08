#include <string.h>
#include <iostream>

class Palavra {
  private:
    std::string palavra;

  public:

    Palavra() {
      palavra = "";
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

    std::string getPalavra() {
      return this->palavra;
    }

    void setText(std::string texto) {
      this->palavra = texto;
    }

    bool operator==(Palavra outra) {
      return (!(this->getPalavra().compare(outra.getPalavra())));
    }

    void operator=(std::string x) {
      this->palavra = x;
    }

};
