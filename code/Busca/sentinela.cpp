#include<bits/stdc++.h>

using namespace std;

int main(){

    int v[11] = {0,10,20,30,40,50,60,70,80,90 };
    int x, i;

    cin >> x;
    v[10] = x;

    for(i = 0; x != v[i]; i++);

    if(i < 10)
        cout << "achei\n";
    else
        cout << "achei nao\n";

    return 0;
}
