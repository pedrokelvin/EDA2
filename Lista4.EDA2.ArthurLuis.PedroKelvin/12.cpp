#include <bits/stdc++.h>
using namespace std;

//a) Afirmacao: existe um schedule valido se e somente se cada stream i satisfaz b_i < r*t_i
//A afirmacao eh falsa. Um contra-exemplo possivel eh fazendo r = 2, t1 = t2 = 1, b1 = 3, b2 = 1
//Eh possivel enviar o stream 2 seguido pelo stream 1 sem violar as condicoes (1+3) <= 2*(1+3)
//mesmo o stream 1 violando a afirmacao (b_1 < r*t_1 -> 3 < 2 * 1 -> falso)

int main()
{
  int n, b, t, r;
  cout << "Digite a quantidade de streams: ";
  cin >> n;
  cout << "Digite o parametro r: ";
  cin >> r;
  
  long long sum_b = 0, sum_t = 0;

  for(int i = 0 ; i < n ; i++)
  {
    cout << "Digite a quantidade de bits do stream " << i << ": ";
    cin >> b;
    cout << "Digite a duracao do stream " << i << ": ";
    cin >> t;
    sum_b += b;
    sum_t += t;
  }

  //O problema pergunta se existe um schedule possivel. Basta, portanto, 
  //verificar se a soma da quantidade de bytes nao exceda a soma dos tempos
  //multiplicado pelo parametro r, ja que eh preciso enviar sum_b bytes no
  //tempo total sum_t em qualquer ordem.

  if(sum_b <= r * sum_t)
    cout << "Sim, existe um schedule possivel" << endl;
  else
    cout << "Nao, nao existe um schedule possivel" << endl;

  return 0;
}
