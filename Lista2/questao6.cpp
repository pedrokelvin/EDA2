#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << fixed << #x << " is " << x << endl;
#define INF 2147483647 //2^31-1

void CriarHeap(vector<int> v)
{
    int n = v.size();
    vector<int> heap(n);

    for(int i = 0 ; i < n ; i++)
    {
        heap[i] = v[i];
        int pai = (i - 1)/2;
        int atual = i;

        while (heap[pai] > heap[atual] && atual != pai)
        {
            swap(heap[pai], heap[atual]);
            int aux = pai;
            pai = (pai - 1)/2;
            atual = aux;
        }
    }

    //Printar em ordem
    for(int i = 0 ; i < n ; i++)
    {
        //cout << heap[0] << " "; //-> printar primeiro elemento (menor)
        int atual = 0;
        heap[0] = INF;//sentinela: infinito

        do//remover primeiro elemento:descer primeiro elemento e subindo os menores
        {
            int l = 2 * atual + 1;
            int r = 2 * atual + 2;
            if(l == n - 1)
            {
                swap(heap[atual], heap[l]);
                atual = l;
            }
            else if(l > n) 
                break;
            else if(heap[l] < heap[r])
            {
                swap(heap[atual], heap[l]);
                atual = l;
            }
            else if(r < n)
            {
                swap(heap[atual], heap[r]);
                atual = r;
            }
        }while(atual < n || heap[atual] != INF);
    }
}

void HeapifyNoVetor(vector<int> &v, int n, int i)
{
    int atual = i;
    int l = 2*i + 1;
    int r = 2*i + 2; 
 
    if (n >l && v[l] > v[atual])
        atual = l;
    if (n >r && v[r] > v[atual])
        atual = r;
    if (atual != i)
    {
        swap(v[i], v[atual]);
        HeapifyNoVetor(v, n, atual);
    }
}
 
void HeapSort(vector<int> &v, int n)
{
    //Montar o heap
    for (int i = n / 2 - 1; i >= 0; i--)
        HeapifyNoVetor(v, n, i);

    //Extrair um por um
    for (int i = n - 1; i >= 0; i--)
    {
        swap(v[0], v[i]);
        HeapifyNoVetor(v, i, 0);
    }
}
 
int main()
{
    int tam = 2; //tamanho dos elementos
    for(int j = 0 ; j < 25 ; j++)
    {
        vector<int> v;
        for(int i = 0 ; i < tam ; i++)
            v.push_back(rand() % 100000);

        auto begin = chrono::high_resolution_clock::now(); //comeca o clock
        CriarHeap(v); //Criando a estrutura Heap e depois removendo em ordem
        auto end = chrono::high_resolution_clock::now();//termina o clock
        cout << tam << " elementos (Criando o Heap): " << (long double)chrono::duration_cast<chrono::nanoseconds>(end-begin).count()/1000000000 << " s" << endl;

        begin = chrono::high_resolution_clock::now(); //comeca o clock
        HeapSort(v, v.size()); //Heap Sort no Vetor
        end = chrono::high_resolution_clock::now();//termina o clock
        cout << tam << " elementos (Heap no vetor): " << (long double)chrono::duration_cast<chrono::nanoseconds>(end-begin).count()/1000000000 << " s" << endl;

        tam *= 2; //dobrar elemento
    }
    return 0;
}
