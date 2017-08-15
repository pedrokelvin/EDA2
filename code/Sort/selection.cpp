//Implementing Selection Sort

#include<bits/stdc++.h>

using namespace std;

void selectionSort(vector<int> vetor){

    int j, i, min, aux;

    for(i = 0; i < vetor.size(); ++i)
    {
        min = i;

        for(j = i + 1; j < vetor.size(); j++)
        {
            if(vetor[j] < vetor[min])
                min = j;
        }

        if(min > i)
        {
            aux = vetor[i];
            vetor[i] = vetor[min];
            vetor[min] = aux;
        }

    }

    for(auto i:vetor)
        cout << i << " ";
    cout << endl;
}


int main(){

    vector<int> v;
    v = {10,7,8,16,5,1,2};

    selectionSort(v);

    return 0;
}
