#include <bits/stdc++.h>
using namespace std;

int main()
{
  vector<bool> rodovia;
  vector<int> pos;
  int postes = 0, tam;

  cout << "Digite o tamanho da rodovia: ";
  cin >> tam;
  for(int i = 0; i < tam ; ++i)
  {
      bool val;
      cout << "Digite 1 ou 0 para indicar se ha uma casa na posicao " << i << ": ";
      cin >> val;
      rodovia.push_back(val);
  }

  // O programa se baseia em considerar que a distancia minima entre duas casas eh sempre de um metro.
  // Foi utilizado um vetor booleano para representar a quantidade de casas na rodovia. Cada posicao do
  // vetor que esta com o valor 1 eh considerada uma casa que esta presente naquela determinada posicao.
  // Dessa forma, a rodovia tem o tamanho do size do nosso vetor.

  for(int j = 0; j < rodovia.size(); ++j)
  {
      if(rodovia[j])
      {
          int count = 0;

          while((j != rodovia.size() - 1) && (count != 4))
          {
              j++;
              count++;
          }
          pos.push_back(j);
          postes++;
          j += 4;
      }
  }

  cout << "A quantidade de postes necessaria sera: " << postes << endl;
  cout << "Nas posicoes: ";

  for(int i = 0 ; i < pos.size() ; i++)
      cout << pos[i] << ",\n"[i == pos.size() - 1];

return 0;
}