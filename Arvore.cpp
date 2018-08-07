#include <fstream>
#include "Arvore.h"
#include "string.h"

/* = = = CONSTRUTOR  = = = */
Arvore::Arvore() {// raiz recebe NULL
    arv = NULL;
}
/* = = = END CONSTRUTOR = = = */

/* = = = ROTAÇÕES = = = */

/* Simples */
void Arvore::LL(AVL_Arv *pA){
    AVL_Arv pB;

    pB = (*pA)->esq;
    (*pA)->esq = pB->dir;
    pB->dir = *pA;
    (*pA)->fat_bak = 0;
    pB->fat_bal = 0;
    *pA = pB;
}

void Arvore::RR(AVL_Arv *pA){
    AVL_Arv pB;

    pB = (*pA)->dir;
    (*pA)->dir = pB->esq;
    pB->esq = *pA;
    (*pA)->fat_bal = 0;
    pB->fat_bal = 0;
    *pA = pB;
}

/* Composta */
void Arvore::LR(AVL_Arv *pA){
    AVL_Arv pB, pC;

    pB = (*pA)->esq;
    pC = pB->dir;
    pB->dir = pC->esq;
    pC->esq = pB;
    (*pA)->esq = pC->dir;
    pC->dir = *pA;
    if (pC->fat_bal == +1) (*pA)->fat_bal = -1; else (*pA)->fat_bal = 0;
    if (pC->fat_bal == -1) pB->fat_bal = +1; else pB->fat_bal = 0;
    pC->fat_bal = 0;
    *pA = pC;
}

void Arvore::RL(AVL_Arv *pA){
    AVL_AVL_Arvde pB, pC; 
    pB = (*pA)->dir;
    pC = pB->esq;
    pB->esq = pC->dir;
    pC->dir = pB;
    (*pA)->dir = pC->esq;
    pC->esq = *pA;
    if (pC->fat_bal == -1) (*pA)->fat_bal = +1; else (*pA)->fat_bal = 0;
    if (pC->fat_bal == +1) pB->fat_bal = -1; else pB->fat_bal = 0;
    pC->fat_bal = 0;
    *pA = pC;
}
/* = = = END ROTAÇÕES = = = */



/* = = = AUXILIARES = = = */

/* Retorna a Altura da Arvore a partir de um NO */
int Arvore::Altura(AVL_Arv no){
    int hesq, hdir;
    
    if (no == NULL)
        return -1; // altura de arvore vazia e -1
    hesq = Altura(no->esq);
    hdir = Altura(no->dir);
    
    if (hesq > hdir)
        return hesq + 1;
    else
        return hdir + 1;
}

/* Calcular Fator de Balanceamento */
int Arvore::FB(AVL_Arv no){
    if (no == NULL)
        return 0;
    return no->fat_bal;
}

/* Se BalancaEsquerda e FBE > 0 LL se não FBE < 0 LR */
int Arvore::BalancaEsquerda(AVL_Arv *arv){
    int fbe = FB((*arv)->esq); //Fator de balanceamento a esquerda
    
    if (fbe > 0) {
        LL(no);
        return 1;
    }

    else if (fbe < 0) {
        LR(no);
        return 1;
    }
    
    return 0;
}

/* Se BalancaEsquerda e FBD > 0 RR se não FBD < 0 RL */
int Arvore::BalancaDireita(AVL_Arv *arv){
    int fbd = FB((*arv)->dir);//Fator de balenceamento a direita

    if (fbd < 0) {
        RR(no);
        return 1;
    }
    else if (fbd > 0) {
        RL(no);
        return 1;
    }

    return 0;
}

/* Se o FB = 2 então BalancaEsquerda | Se FB = -2  então BalancaDireta */
int BalancaNo(AVL_Arv *arv){
    int fb = FB(*arv);
    
    if (fb > 1)
        return BalancaEsquerda(no);
    else if (fb < -1)
        return BalancaDireita(no);

    return 0;
}

void Arvore::imprimeArvore(AVL_Arv arv){
    if(arv==NULL)
       return;
    imprimeArvore(arv->esq);
    printf("%s\n",arv->Item);
    imprimeArvore(arv->dir);
}
/* = = = END AUXILIARES = = = */



/* = = = MANIPULAÇÂO DA ARVORE = = = */
int Insere(AVL_Arv *arv, TItem x){
    if (*arv == NULL) {
        *arv = (AVL_Arv) malloc(sizeof(AVL_Node));
        (*arv)->Item = x; (*arv)->esq = NULL; (*arv)->dir = NULL; (*arv)->fat_bal = 0;
        return 1;
    }
    else if (x.Chave < (*arv)->Item.Chave) {
        if (Insere(&(*arv)->esq, x))
            switch ((*arv)->fat_bal) { // subarvore esquerda cresceu
                case -1: (*arv)->fat_bal = 0; return 0;
                case 0: (*arv)->fat_bal = +1; return 1;
                case +1: return !BalancaEsquerda(no);
            }
        return 0;
    }
    else if (x.Chave > (*arv)->Item.Chave) {
        if (Insere(&(*arv)->dir, x))
            switch ((*arv)->fat_bal) { // subarvore direita cresceu
                case +1: (*arv)->fat_bal = 0; return 0;
                case 0: (*arv)->fat_bal = -1; return 1;
                case -1: return !BalancaDireita(no);
            }
        return 0;
    }
    else
        return 0; // retorna 0 caso o item ja estiver na arvore
}



/* = = = END MANIPULAÇÂO DA ARVORE = = = */