#include <iostream>
using namespace std;

const string PALAVRA_SECRETA = "Programacao";

bool contem_letra(char letra)
{
    bool contem_letra = false;

    /* Esta é a versão de como tradicionalmente verificaríamos
    a existência de uma letra dentro de uma string:
    for (int i = 0; i < PALAVRA_SECRETA.size(); i++)
    {
        if (letra == PALAVRA_SECRETA[i])
        {
            contem_letra = true;
        }
    } */

    // Esta é a versão aprimorada, trazida pelo c++ em sua versão 11:
    for (char letra_atual : PALAVRA_SECRETA)
    {
        if (letra == letra_atual)
        {
            contem_letra = true;
        }
    }

    return contem_letra;
}

int main()
{
    bool nao_acertou = true;
    bool nao_enforcou = true;

    while (nao_acertou && nao_enforcou)
    {
        char chute;
        cin >> chute;

        if (contem_letra(chute))
        {
            cout << "Letra esta presente na palavra";
        }

        else
        {
            cout << "Letra nao esta presente na palavra";
        }
    }
}