#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << fixed << #x << " is " << x << endl;

void CountSort(vector<string> &v, int ind)
{
	int n = v.size();
	vector<string> result(n);
	map<char, int> hist; //histograma

	for (int i = 0; i < n; i++)
		if(ind < v[i].size())
			hist[v[i][ind]]++;
		else
			hist[' ' - 1]++;

	for (char c = ' ' - 1; c <= 'z'; c++)
		hist[c] += hist[c - 1];

	for (int i = n - 1 ; i >= 0 ; i--)
	{
		if(ind < v[i].size())
		{
			result[hist[ v[i][ind] ] - 1] = v[i];	
			hist[ v[i][ind] ]--;
		}
		else
		{
			result[hist[ ' '-1  ] - 1] = v[i];	
			hist[ ' '-1 ]--;
		}
	}

	for (int i = 0 ; i < n ; i++)
		v[i] = result[i];
}

void RadixSort(vector<string> &v)
{
	int n = v.size();
	int maior = v[0].size();
	for (int i = 1; i < v.size(); i++)
		if (v[i].size() > maior)
			maior = v[i].size();

	for (int ind = maior - 1; ind >= 0; ind--)
		CountSort(v, ind);
}


int main()
{
	string s;
	vector<string> v;
	while(cin >> s)
		v.push_back(s);
    RadixSort(v);
    for(auto i : v)
    	cout << i << endl;

	return 0;
}