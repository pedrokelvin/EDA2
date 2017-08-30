#include<bits/stdc++.h>

using namespace std;

void Merge(vector<int>& A,vector<int>& L,vector<int>& R){

    int i = 0, j = 0, k = 0;

    while(k < A.size() && i < L.size() && j < R.size())
    {
        if(L[i] <= R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < L.size())
        A[k++] = L[i++];

    while(j < R.size())
        A[k++] = R[j++];

}

void MergeSort(vector<int>& A){

    if(A.size() < 2) return;

    int mid = A.size()/2;
    vector<int> L;
    vector<int> R;

    for(int i = 0; i < mid; ++i)
        L.push_back(A[i]);
    for(int i = mid; i < A.size(); ++i)
        R.push_back(A[i]);

    MergeSort(L);
    MergeSort(R);
    Merge(A,L,R);
}

int main(){

    vector<int> A {7,1,3,10,9,4,19,17};

    MergeSort(A);

    for(auto i:A)
        cout << i << ' ';
    cout << endl;

    return 0;
}
