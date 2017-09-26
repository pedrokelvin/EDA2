// Implementing bubble sort with C++

#include<bits/stdc++.h>

using namespace std;

vector<int> bubbleSort(vector<int> v){

    int aux;

    for(int i = v.size() - 1; i > 0; --i)
    {
        for(int j = 0; j < i; ++j)
        {
            if(v[j] > v[j+1])
            {
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
        }
    }

    return v;
}


int main(){

    vector<int> v;
    v = {3,7,4,10,1,0,2,5};

    v = bubbleSort(v);

    for(auto i:v)
        cout << i << " ";
    cout << endl;

    return 0;
}
