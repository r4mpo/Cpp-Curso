#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;

string palavra_secreta = "Programacao";
map<char, bool> chutou_letra;
vector<char> chutes_errados;

bool contem_letra(char letra)
{
    bool contem_letra = false;

    /* Esta é a versão de como tradicionalmente verificaríamos
    a existência de uma letra dentro de uma string:
    for (int i = 0; i < palavra_secreta.size(); i++)
    {
        if (letra == palavra_secreta[i])
        {
            contem_letra = true;
        }
    } */

    // Esta é a versão aprimorada, trazida pelo c++ em sua versão 11:
    for (char letra_atual : palavra_secreta)
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
    for (char letra : palavra_secreta)
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

    for (char letra : palavra_secreta)
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

vector<string> visualiza_arquivo()
{
    // input, file, stream
    ifstream arquivo;
    arquivo.open("palavras.txt");

    if (arquivo.is_open())
    {
        int qtd_palavras;
        vector<string> palavras_arquivo;

        arquivo >> qtd_palavras;

        for (int i = 0; i < qtd_palavras; i++)
        {
            string palavra_lida;
            arquivo >> palavra_lida;
            palavras_arquivo.push_back(palavra_lida);
        }

        arquivo.close();
        return palavras_arquivo;
    }

    else
    {
        cout << "Impossivel acessar o arquivo de palavras...";
        exit(0);
    }
}

void sorteia_palavra()
{
    vector<string> palavras = visualiza_arquivo();
    srand(time(NULL));
    int indice_sorteado = rand() % palavras.size();
    palavra_secreta = palavras[indice_sorteado];
}

void salva_arquivo(vector<string> nova_lista)
{
    // output, file, stream
    ofstream arquivo;
    arquivo.open("palavras.txt");

    if (arquivo.is_open())
    {
        // escrevendo em um arquivo
        arquivo << nova_lista.size() << endl;

        for (string palavra : nova_lista)
        {
            arquivo << palavra << endl;
        }

        arquivo.close();
    }

    else
    {
        cout << "Impossivel acessar o arquivo de palavras...";
        exit(0);
    }
}

void adiciona_palavra()
{
    cout << "Digita a nova palavra: ";
    string nova_palavra;
    cin >> nova_palavra;

    vector<string> lista_palavras = visualiza_arquivo();
    lista_palavras.push_back(nova_palavra);

    salva_arquivo(lista_palavras);
}

int main()
{
    sorteia_palavra();
    imprime_cabecalho();

    cout << endl;

    while (nao_acertou() && nao_enforcou())
    {

        imprime_chutes_errados();

        imprime_palavra_secreta();

        cout << endl
             << endl;

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

    if (nao_acertou())
    {
        cout << "Fim de Jogo! Aparentemente o jogador perdeu!";
    }

    else if (nao_enforcou())
    {
        cout << "Fim de Jogo! Aparentemente o jogador venceu!" << endl;
        cout << "Deseja adicionar uma nova palavra ao banco?" << endl;
        char resposta;
        cin >> resposta;

        if (resposta == 'S')
        {
            adiciona_palavra();
        }
    }
}