#include <bits/stdc++.h>
using namespace std;

int main()
{
  cout << "Digite a quantidade de jobs: ";
  int q_jobs, t, w;
  cin >> q_jobs;
  vector<pair<double, int>> schedule(q_jobs);

  for(int i = 0 ; i < q_jobs ; i++)
  {
    cout << "Digite quanto tempo o job " << i << " demora na maquina: ";
    cin >> t;
    cout << "Digite o peso do job " << i << ": ";
    cin >> w;
    schedule[i] = make_pair((double) - w / t, i);
  }

  //para encontrar a ordem que minimiza a soma, basta ordenar o vetor "schedule" em ordem decrescente
  //O vetor "schedule" eh tal que schedule[i] = w[i] / t[i]
  //Para mostrar que isso funcione, suponha uma schedule qualquer. Entao, caso pegassemos 2 jobs seguidos i, j (com j = i+1),
  //vamos calcular a soma com peso trocando eles de posicao. Fazendo isso, a soma dos outros elementos nao se alteram:
  //Originalmente:       w[i]*t[i] + w[j]*(t[i]+t[j])
  //Trocando de posicao: w[j]*t[j] + w[i]*(t[j]+t[i])
  //Diferenca entre eles: w[j]*t[j] + w[i]*(t[j]+t[i]) - (w[i]*t[i] + w[j]*(t[i]+t[j])) = w[i]*t[j] - w[j]*t[i]
  //Como queiramos que a soma seja a menor possivel, eh necessario que w[i]*t[j] >  w[j]*t[i] -> w[i]/t[i] > w[j]/t[j]
  //Logo, fazendo os swaps tal que w[i]/t[i] > w[j]/t[j] minimiza a weighted sum
  sort(schedule.begin(), schedule.end());
  cout << "Ordem dos jobs que minimiza a soma com peso dos tempos: ";
  for(int i = 0 ; i < q_jobs ; i++)
    cout << schedule[i].second << ",\n"[i == q_jobs-1];
  return 0;
}
