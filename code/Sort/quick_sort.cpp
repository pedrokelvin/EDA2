#include<bits/stdc++.h>

using namespace std;
#define ll long long

int partition(int *v, int begin, int end){

    int pIndex = begin;

    for(int i = begin; i < end; ++i)
    {
        if(v[i] <= v[end])
        {
            swap(v[i],v[pIndex]);
            pIndex++;
        }
    }
    swap(v[pIndex],v[end]);
    return pIndex;
}

void QuickSort(int *v,int begin, int end){

    if(begin >= end)
        return;

    int pivo = partition(v,begin,end);
    //Pela esquerda
    QuickSort(v,begin,pivo-1);
    //Pela direita
    QuickSort(v,pivo+1,end);
}

int main(){

    int pivo;
    int v[] = {7,2,1,6,8,5,3,4};
    QuickSort(v,0,7);

    for(int i = 0; i < 8; ++i)
        cout << v[i] << " ";
    cout << endl;

    return 0;
}
