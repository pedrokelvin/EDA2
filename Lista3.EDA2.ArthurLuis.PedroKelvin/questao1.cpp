#include <bits/stdc++.h>

using namespace std;

void merge(vector<int> &v, int l, int m, int r);
void mergeSort(vector<int> &v, int n);

int main()
{
    vector<int> v = {12,6,5,4,3,7,9,8,3,10,23,4456,5,64,79,8,6};
    mergeSort(v, v.size());

    for(auto i:v)
        cout << i << ' ';
    cout << endl;

    return 0;
}

void mergeSort(vector<int> &v, int n){

   int tam_sub_vetor;
   int inicio_esq;

   for (tam_sub_vetor=1; tam_sub_vetor<=n-1; tam_sub_vetor = 2*tam_sub_vetor)
   {
       for (inicio_esq=0; inicio_esq<n-1; inicio_esq += 2*tam_sub_vetor)
       {

           int m = inicio_esq + tam_sub_vetor - 1;
           int inicio_dir = min(inicio_esq + 2*tam_sub_vetor - 1, n-1);
           merge(v, inicio_esq, m, inicio_dir);
       }
   }
}

void merge(vector<int> &v, int l, int m, int r){

    int i, j, k;
    int size1 = m - l + 1;
    int size2 =  r - m;

    int L[size1], R[size2];

    for (i = 0; i < size1; i++)
        L[i] = v[l + i];
    for (j = 0; j < size2; j++)
        R[j] = v[m + 1+ j];

    i = 0;
    j = 0;
    k = l;
    while (i < size1 && j < size2)
    {
        if (L[i] <= R[j])
        {
            v[k] = L[i];
            i++;
        }
        else
        {
            v[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < size1)
    {
        v[k] = L[i];
        i++;
        k++;
    }

    while (j < size2)
    {
        v[k] = R[j];
        j++;
        k++;
    }
}