#include <bits/stdc++.h>
using namespace std;

int main()
{
    // S1 eh a string original e S2 eh a string que verificaremos se eh subsequencia de S1
    string s1,s2;

    cout << "Entre com a string original: ";
    getline(cin,s1);
    cout <<  "Entre com uma string para verificar se eh substring da original: ";
    getline(cin,s2);

    //Para verificar se s2 eh subsequencia de s1, basta varrer a string s1 da esquerda para direita
    //procurando os caracteres em ordem da string s2. Caso um caractere seja encontrado, incrementar
    //o indice da string s2.
    for(int indice1 = 0, indice2 = 0; indice1 < s1.size(); ++indice1)
    {
        if(s2[indice2] == s1[indice1])
            indice2++;

        if(indice2 == s2.size())
        {
            cout << s2 << " eh subsequencia de " << s1 << endl;
            return 0;
        }
    }
    cout << s2 << " nao eh subsequencia de " << s1 << endl;

    return 0;
}
