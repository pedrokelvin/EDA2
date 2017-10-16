#include <bits/stdc++.h>
using namespace std;

int main()
{
  cout << "Digite a quantidade de jobs: ";
  int q_jobs;
  cin >> q_jobs;
  vector<int> pi(q_jobs); 
  vector<pair<int, int>> fi(q_jobs);

  for(int i = 0 ; i < q_jobs ; i++)
  {
    int tempo;
    cout << "Digite quanto tempo o job " << i << " demora no supercomputador: ";
    cin >> tempo;
    pi.push_back(tempo);
    cout << "Digite quanto tempo o job " << i << " demora no PC: ";
    cin >> tempo;
    fi.push_back(make_pair(-tempo, i));
  }

  //como os tempos nos PCs sao rodados em paralelos, convem por o tempo mais rapido que roda no PC por ultimo,
  //o segundo mais rapido no penultimo e assim sucessivamente. Logo, para minimizar o tempo
  //total, basta ordenar os tempos do fi em ordem decrescente.
  sort(fi.begin(), fi.end());
  cout << "Ordem dos jobs que minimiza a tarefa: ";
  for(int i = 0 ; i < q_jobs ; i++)
    cout << fi[i].second << ",\n"[i == q_jobs-1];

  return 0;
}
