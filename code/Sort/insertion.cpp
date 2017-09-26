// Implementing Insertion Sort

#include<bits/stdc++.h>

using namespace std;

void insertionSort(vector<int> vetor){

    int i, j, aux;

    for(i = 1; i < vetor.size(); ++i)
    {
        j = i - 1;

        while(j >= 0 && vetor[i] < vetor[j])
        {
            aux = vetor[j];
            vetor[j] = vetor[i];
            vetor[i] = aux;
            j--;
        }

    }

}

int main(){

    return 0;
}
