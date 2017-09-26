#include<bits/stdc++.h>

using namespace std;


vector<int> shellSort(vector<int>& v){
    int n = v.size();
    int metade = n/2;
    int c,j;

    while(metade>0)
    {
        for(int i = metade; i < n; ++i)
        {
            c = v[i];
            j = i;

            while(j>=metade && v[j-metade] > c)
            {
                v[j] = v[j -metade];
                j = j - metade;
            }
            v[j] = c;
        }
        metade /= 2;
    }
    return v;
}


int main(){

    vector<int> v = {10,2,9,7,6,3,11,4,8,5,1};
    v = shellSort(v);
    
    for(auto i:v)
        cout << i << ' ';
    cout << endl;

    return 0;
}
