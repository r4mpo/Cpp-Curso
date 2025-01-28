#include <iostream>
#include <regex>

using namespace std;

bool only_numbers(string s)
{
    regex re("^[0-9]+$");
    smatch match;
    return (regex_search(s, match, re) ? true : false);
}

int main()
{
    cout << "**********************************************************" << endl;
    cout << "#-- SEJA BEM-VINDO AO JOGO DE ADVINHACAO FEITO COM C++ --#" << endl;
    cout << "**********************************************************" << endl;

    string valor_digitado;
    bool pendente = true;
    const int VALOR_SECRETO = 7;

    while (pendente)
    {
        cout << endl << "Digite um numero: ";

        cin >> valor_digitado;

        if (!only_numbers(valor_digitado))
        {
            cout << "Ops! Parece que voce nao digitou um valor numerico valido...";
        }

        else
        {

            // stoi = converte std::string para um int
            bool usuario_acertou = stoi(valor_digitado) == VALOR_SECRETO;

            if (usuario_acertou)
            {
                cout << "Boa! Voce acertou o numero secreto!" << endl;
                cout << "Numero Digitado: " << valor_digitado << endl
                     << "Numero Secreto: " << VALOR_SECRETO;

                pendente = false;
            }

            else
            {
                cout << "Ops! Parece que voce nao acertou o valor." << endl;

                bool valor_digitado_maior = stoi(valor_digitado) > VALOR_SECRETO;

                if (valor_digitado_maior)
                {
                    cout << "Seu palpite foi maior que o numero secreto.";
                }

                else
                {
                    cout << "Seu palpite foi menor que o numero secreto.";
                }
            }
        }
    }
}