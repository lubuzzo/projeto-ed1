#include <iostream>

using namespace std;

class Arvore {
private:
  struct no {
    std::string valor;
    no* esquerda;
    no* direita;
    int peso;
  };

  no* raiz;

public:
  Arvore () {
    raiz = NULL;
  };

  void inserir(std::string x) {
    raiz = inserir(x, raiz);
  }

  no* inserir(std::string x, no* t) {
    if(t == NULL) {
      t = new no;
      t->valor = x;
      t->peso = 0;
      t->esquerda = t->direita = NULL;
    } else if(x < t->valor) {
      t->esquerda = inserir(x, t->esquerda);
      if(peso(t->esquerda) - peso(t->direita) == 2) {
        if(x < t->esquerda->valor)
          t = rotEE(t);
        else
          t = rotDE(t);
      }
    } else if(x > t->valor) {
      t->direita = inserir(x, t->direita);
      if(peso(t->direita) - peso(t->esquerda) == 2) {
        if(x > t->direita->valor)
          t = rotDD(t);
        else
          t = rotED(t);
        }
      }

      t->peso = max(peso(t->esquerda), peso(t->direita))+1;
      return t;
    }

    void inorder(no* t) {
      if(t == NULL)
        return;
      inorder(t->esquerda);
      cout << t->valor << " ";
      inorder(t->direita);
    }

    void display() {
      inorder(raiz);
      cout << endl;
    }

    no* rotEE(no* &t) {
      no* u = t->esquerda;
      t->esquerda = u->direita;
      u->direita = t;
      t->peso = max(peso(t->esquerda), peso(t->direita))+1;
      u->peso = max(peso(u->esquerda), t->peso)+1;
      return u;
    }

    no* rotDD(no* &t) {
      no* u = t->direita;
      t->direita = u->esquerda;
      u->esquerda = t;
      t->peso = max(peso(t->esquerda), peso(t->direita))+1;
      u->peso = max(peso(t->direita), t->peso)+1 ;
      return u;
    }

    no* rotED(no* &t) {
      t->direita = rotEE(t->direita);
      return rotDD(t);
    }

    no* rotDE(no* &t) {
      t->esquerda = rotDD(t->esquerda);
      return rotEE(t);
    }

    int peso(no* t) {
      return (t == NULL ? -1 : t->peso);
    }
};
