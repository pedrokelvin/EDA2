#include<bits/stdc++.h>

using namespace std;
#define ii pair<int, int>

//Busca sequencial com Índice Primário
//Usando Vetor

/*
Tabela terá 30 elementos;
O numero de indices desejados serão 5;
30/5 = 6;
0+n/30
primeiro elemento = 0
segundo = (0+30)/5 = 6
terceiro = (0+30*2)/5 = 12
quarto = (0+30*3)/5 = 18
quinto = (0+30*4)/5 = 24
*/

vector<ii> tabela_indices;
int tabela[30] = {3,6,-1,-1,18,20,29,-1,38,-1,-1,59,66,-1,90,-1,129,-1,138,150,-1,-1,-1,210,218,-1,229,-1,-1,250};

//Ele busca o valor e retorna o valor do registro onde ele se encontra.
//Caso nao ache, retorna -1
int busca(int valor){

    for(int i = 0; i < tabela_indices.size(); ++i)
    {
        if(valor <= tabela_indices[i].first)
        {
            int novo_indice = tabela_indices[i-1].second;

            while(novo_indice < 30) //enquanto eu ainda varrer a tabela...
            {
                if(valor == tabela[novo_indice])
                    return novo_indice;

                novo_indice++;
            }
        }
    }

    return -1;
}

//Caso o elemento a ser removido seja valido, ele coloca -1
//em sua posicao, sinalizando que é uma posicao válida
void remocao(int elemento){

    int indice = busca(elemento);

    if(indice == -1)
        cout << "Elemento nao existe\n";
    else
        tabela[indice] = -1;
}

void inserir(int elemento){

    bool flag = false;

    for(int i = 0; i < tabela_indices.size(); ++i)
    {
        if(elemento < tabela_indices[i].first)
        {
            int novo_indice = tabela_indices[i-1].second;

            while(novo_indice < 30 && elemento > tabela[novo_indice])
            {

                if(tabela[novo_indice] == -1)
                {
                    tabela[novo_indice] = elemento;
                    return;
                }
                novo_indice++;
            }

            cout << "Nao foi possivel achar espaço\n";
            return;
        }
    }
}

void imprime(){

    for(int i = 0; i < 30; ++i)
        cout << "valor: " << tabela[i] << " indice: " << i << endl;

}

int main(){

    tabela_indices.push_back({3,0});
    tabela_indices.push_back({29,6});
    tabela_indices.push_back({66,12});
    tabela_indices.push_back({138,18});
    tabela_indices.push_back({218,24});

    int num;

    while(cin >> num)
    {
        inserir(num);
        imprime();
    }

    return 0;
}
