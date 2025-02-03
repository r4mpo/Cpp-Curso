#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

const string PALAVRA_SECRETA = "Programacao";
map<char, bool> chutou_letra;
vector<char> chutes_errados;

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

bool nao_acertou()
{
    for (char letra : PALAVRA_SECRETA)
    {
        if (!chutou_letra[letra])
        {
            return true;
        }
    }

    return false;
}

bool nao_enforcou()
{
    return chutes_errados.size() < 5;
}

void imprime_cabecalho()
{
    cout << "***************************************************" << endl;
    cout << "** SEJA BEM-VINDO AO JOGO DA FORCA FEITO COM C++ **" << endl;
    cout << "***************************************************" << endl;
}

void imprime_chutes_errados()
{
    cout << "Chutes errados: ";

    for (char letra : chutes_errados)
    {
        cout << letra << " ";
    }
}

void imprime_palavra_secreta()
{
    cout << endl
         << "Palavra secreta: ";

    for (char letra : PALAVRA_SECRETA)
    {
        char letra_individual;

        if (chutou_letra[letra])
        {
            letra_individual = letra;
        }
        else
        {
            letra_individual = '_';
        }

        cout << letra_individual << " ";
    }
}

int main()
{
    imprime_cabecalho();

    cout << endl;

    while (nao_acertou() && nao_enforcou())
    {

        imprime_chutes_errados();

        imprime_palavra_secreta();

        cout << endl
             << endl;
        ;

        char chute;

        cout << "Digite seu chute: ";

        cin >> chute;

        chutou_letra[chute] = true;

        if (contem_letra(chute))
        {
            cout << "O Chute - " << chute << " - foi contabilizado como acerto." << endl;
        }

        else
        {
            cout << "O Chute - " << chute << " - foi contabilizado como erro." << endl;
            chutes_errados.push_back(chute);
        }

        cout << endl;
    }
}