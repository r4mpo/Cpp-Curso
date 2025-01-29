#include <iostream>
#include <regex>
#include <cstdlib> // importando bibliotecas de C
#include <ctime> // importando biblioteca de C relacionada a tempo

using namespace std;

bool verifica_valor_numerico(string s)
{
    regex re("^[0-9]+$");
    smatch match;
    return (regex_search(s, match, re) ? true : false);
}

int calcula_pontuacao(int valor_digitado, int valor_secreto, double pontuacao)
{
    // abs = considera o valor absoluto. por exemplo, se o resultado da subtração for -10, ele considerará 10.
    double pontos_perdidos = abs(valor_digitado - valor_secreto) / 2.0;
    return pontuacao - pontos_perdidos;
}

int main()
{
    cout << "**********************************************************" << endl;
    cout << "** SEJA BEM-VINDO AO JOGO DE ADVINHACAO FEITO COM C++ **" << endl;
    cout << "**********************************************************" << endl;

    char nivel_dificuldade;
    int tentativas_disponiveis;

    cout << "Escolha um nivel de dificuldade:" << endl;
    cout << "Facil (F), Medio (M) ou Dificil (D)" << endl;

    cin >> nivel_dificuldade;

    if (nivel_dificuldade == 'F')
    {
        tentativas_disponiveis = 15;
    }

    else if (nivel_dificuldade == 'M')
    {
        tentativas_disponiveis = 10;
    }

    else
    {
        tentativas_disponiveis = 5;
    }

    bool pendente = true;
    string valor_digitado;
    double pontuacao = 1000.0;

    srand(time(NULL));
    const int VALOR_SECRETO = rand() % 100;

    while (pendente)
    {
        for (int numero_tentativas = 1; numero_tentativas <= tentativas_disponiveis; numero_tentativas++)
        {
            cout << endl
                 << "Digite um numero: ";

            cin >> valor_digitado;

            // stoi = converte std::string para um int.
            pontuacao = calcula_pontuacao(stoi(valor_digitado), VALOR_SECRETO, pontuacao);

            bool valor_numerico = verifica_valor_numerico(valor_digitado);

            if (!valor_numerico)
            {
                cout << "Ops! Parece que voce nao digitou um valor numerico valido...";
            }

            else
            {

                bool usuario_acertou = stoi(valor_digitado) == VALOR_SECRETO;

                if (usuario_acertou)
                {
                    cout << "Boa! Voce acertou o numero secreto!" << endl;
                    cout << "Numero Digitado: " << valor_digitado << "." << endl
                         << "Numero Secreto: " << VALOR_SECRETO << "." << endl;

                    pendente = false;
                }

                else
                {
                    cout << "Ops! Parece que voce nao acertou o valor." << endl;

                    bool valor_digitado_maior = stoi(valor_digitado) > VALOR_SECRETO;

                    if (valor_digitado_maior)
                    {
                        cout << "Seu palpite foi maior que o numero secreto." << endl;
                    }

                    else
                    {
                        cout << "Seu palpite foi menor que o numero secreto." << endl;
                    }
                }
            }

            cout
                << "**********************************************************" << endl;

            if (!pendente)
            {
                cout << "Qtd. de tentativas: " << numero_tentativas << "." << endl;
                cout.precision(2); // colocando vírgula no resultado.
                cout << fixed;     // colocando vírgula no resultado.
                cout << "Pontuacao: " << pontuacao << " pontos." << endl;
                break;
            }

            else if (numero_tentativas == tentativas_disponiveis)
            {
                cout << "Fim de Jogo!" << endl
                     << "Voce perdeu!" << endl
                     << "Tente novamente!" << endl;
            }

            cout
                << "**********************************************************";
        }

        return 0;
    }
}