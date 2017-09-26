#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << fixed << #x << " is " << x << endl;

int rotacoes = 0;

typedef struct No
{
    int val; //valor
    No *esq; //esquerda
    No *dir; //direita
    int H; //altura
}No;
 
int H(No *N)
{
    return (N == NULL) ? 0 : N -> H;
}
 
//Rotacao a direita
No *rotacaoDireita(No *y)
{
    rotacoes++;
    No *x = y -> esq;
    No *T2 = x -> dir;
 
    x -> dir = y;
    y -> esq = T2;
 
    y -> H = max(H(y -> esq), H(y -> dir))+1;
    x -> H = max(H(x -> esq), H(x -> dir))+1;
 
    return x;
}
 
//Rotacao a esquerda
No *rotacaoEsquerda(No *x)
{
    rotacoes++;
    No *y = x -> dir;
    No *T2 = y -> esq;
 
    y -> esq = x;
    x -> dir = T2;
 
    x -> H = max(H(x -> esq), H(x -> dir))+1;
    y -> H = max(H(y -> esq), H(y -> dir))+1;
 
    return y;
}
 
//Encontrar Fator de balanceamento
int fatorBalanceamento(No *N)
{
    if (N == NULL)
        return 0;
    return H(N -> esq) - H(N -> dir);
}
 
//Criar um no novo na arvore
No* newNo(int val)
{
    No* no = (No*) malloc(sizeof(No));
    no -> val = val;
    no -> H = 1;
    no -> esq = NULL;
    no -> dir = NULL;
    return(no);
}

//Inserir valor na arvore
No* insert(No* no, int val)
{
    if (no == NULL)
        return(newNo(val));
 
    if (val < no -> val)
        no -> esq  = insert(no -> esq, val);
    else if (val > no -> val)
        no -> dir = insert(no -> dir, val);
    else
        return no;
 
    no -> H = 1 + max(H(no -> esq), H(no -> dir));
    int balancear = fatorBalanceamento(no);
 
    if (balancear > 1 && val < no -> esq -> val)
        return rotacaoDireita(no);
 
    else if (balancear < -1 && val > no -> dir -> val)
        return rotacaoEsquerda(no);

    else if (balancear > 1 && val > no -> esq -> val)
    {
        no -> esq = rotacaoEsquerda(no -> esq);
        return rotacaoDireita(no);
    }
 
    else if (balancear < -1 && val < no -> dir -> val)
    {
        no -> dir = rotacaoDireita(no -> dir);
        return rotacaoEsquerda(no);
    }
    return no;
}
 
int main()
{
    No *raiz = NULL;

    srand(time(NULL));

    auto begin = chrono::high_resolution_clock::now();

    for(int i = 0 ; i < 1000 ; i++)
        raiz = insert(raiz, rand() % 10000);

    auto end = chrono::high_resolution_clock::now();
    cout << "Tempo de execucao (Arvore AVL): " << (long double)chrono::duration_cast<chrono::nanoseconds>(end-begin).count()/1000000000 << "s" << endl;

    cout << "Rotacoes arvore avl = " << rotacoes << endl;

    return 0;
}