#include <bits/stdc++.h>
using namespace std;
#define MAX 20 //quantidade de tamanhos de vetores a serem testados

int it;

int BuscaInterpolacao(vector<int> v, int key)
{
	int left = 0, right = v.size() - 1;
	while(v[right] != v[left] && key >= v[left] && key <= v[right])
	{
		int mid = left + (long long)(right - left) * (key - v[left])/(v[right] - v[left]);

		if(v[mid] < key)
			left = mid + 1;
		else if(v[mid] > key)
			right = mid - 1;
		else 
			return mid;
		it++;
		
	}
	if(v[left] == key)
		return left;
	return -1;
}

int BinarySearch(vector<int> v, int key)
{
	int l = 0, r = v.size() - 1;
	while(l <= r)
	{
		int m = (l+r)/2;
		if(v[m] < key)
			l = m + 1;
		else if(v[m] > key)
			r = m - 1;
		else
			return m;
		it++;
	}
	return -1;
}

int main()
{
	int tam[MAX+1];//vetor dos tamanhos com tam[x] = 2^x
	tam[0] = 1;
	for(int i = 1 ; i <= MAX ; i++)
		tam[i] = 2 * tam[i-1];

	for(int i = 0 ; i <= MAX ; i++)
	{
		vector<int> v; //vetor gerado aleatoriamente
		std::default_random_engine generator; //usando gerador de numeros aleatorios
  		std::uniform_int_distribution<int> distribution(0,tam[i]); //distribuidos aleatoriamente
		for(int j = 0 ; j < tam[i] ; j++)
			v.push_back(distribution(generator));
		sort(v.begin(), v.end()); //ordenar o vetor para comecar as buscas

		it = 0; //zera as iteracoes para contar no loop

		auto begin = chrono::high_resolution_clock::now(); //comeca o clock
		for(int j = 0 ; j < 100000 ; j++)
			int x = BuscaInterpolacao(v, rand() % tam[i]); //busca uma chave aleatoria
		auto end = chrono::high_resolution_clock::now();//termina o clock
		cout << tam[i] << " elementos (Interpolacao): " << (long double)chrono::duration_cast<chrono::nanoseconds>(end-begin).count()/1000000000 << " s e " << it << " iteracoes" << endl;

		it = 0;

		begin = chrono::high_resolution_clock::now();
		for(int j = 0 ; j < 100000 ; j++)
			int x = BinarySearch(v, rand() % tam[i]);
		end = chrono::high_resolution_clock::now();
		cout << tam[i] << " elementos (Binaria):      " << (long double)chrono::duration_cast<chrono::nanoseconds>(end-begin).count()/1000000000 << " s e " << it << " iteracoes" << endl << endl;
	}

	return 0;
}
