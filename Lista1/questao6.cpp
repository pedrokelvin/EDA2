#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << fixed << #x << " is " << x << endl;

void Primos(vector<int> &Primos, int N)
{
	vector<bool> prime(N+1, 1);
	for(int i = 2 ; i <= N ; i++)
		if(prime[i])
		{
			Primos.push_back(i);
			for(int j = 2*i ; j <= N ; j+=i)
				prime[j] = 0;
		}
}

int comp;

int BuscaBinaria(vector<int> v, int key)
{
	for(int left = 0, right = v.size() - 1 ; left < right - 1 ; )
	{
		int mid = (left + right) / 2;
		if(v[mid] < key)
			left = mid;
		else if(v[mid] > key)
			right = mid;
		else 
			return mid;
		comp++;

	}
	return -1;
}

int BuscaInterpolacao(vector<int> v, int key)
{
	for(int left = 0, count = 0, right = v.size() - 1 ; left < right - 1 && count < 6 ; count++)
	{
		int mid = (int) floor((double) (key * (right - left) + left * v[right] - right * v[left])/(v[right] - v[left])  );

		if(v[mid] < key)
			left = mid;
		else if(v[mid] > key)
			right = mid;
		else 
			return mid;

		if(mid == left)
			left++;
		else if(mid == right)
			right--;
		comp++;
	}
	return -1;
}

int main()
{
	vector<int> primos;
	Primos(primos, 1000000);
	comp = 0;
	cout << "Interpolacao: " << BuscaInterpolacao(primos, 331);
	cout << " comp = " << comp << endl;
	comp = 0;
	cout << "BuscaBinaria: " << BuscaBinaria(primos, 331);
	cout << " comp = " << comp << endl;
	return 0;
}
/*

*/