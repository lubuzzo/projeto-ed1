#ifndef ARVORE_H
#define ARVORE_H
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>

using namespace std;

typedef int TChave;

typedef struct {
    TChave Chave;
} TItem;

typedef struct AVL_Node *AVL_Arv;

typedef struct AVL_Node{
    int fat_bal; //Fator de Balenceamento 
    TItem Item;

    AVL_Arv esq, dir;
}AVL_Node;


class Arvore{
    private:
        AVL_Arv arv;
        
        /* Auxiliares */
        int Altura(AVL_Arv arv); 
        int FB(AVL_Arv arv);
        void imprimeArvore(AVL_Arv arv)
        int BalancaDireita(AVL_Arv *arv);
        int BalancaEsquerda(AVL_Arv *arv);
        int BalancaNo(AVL_Arv *arv);

        /* Rotações */
        void LL(AVL_Arv *arv);
        void RR(AVL_Arv *arv);
        void LR(AVL_Arv *arv);
        void RL(AVL_Arv *arv);


        
    public:
        Arvore(); //Construtor

        int vazia(AVL_Arv *arv);
        int insere(Palavra palavra, AVL_Arv *arv);
        int remove(Palavra palavra, AVL_Arv *arv);
        int buscar(Palavra palavra, AVL_Arv *arv);
}
#endif 