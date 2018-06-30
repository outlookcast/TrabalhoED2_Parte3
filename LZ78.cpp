#include <utility> 
#include <vector>
#include <sstream>
#include "LZ78.h"

using namespace std;

struct NoLZ78
{
    int indice;
    string dados;
    NoLZ78 *proximo;
};

void st_NoLZ78(NoLZ78 *cabeca, int indice, string dados)
{
    cabeca->indice = indice;
    cabeca->dados = std::move(dados);
    cabeca->proximo = NULL;
}

void insereNo(NoLZ78 *cabeca, int indice, string dados)
{
    NoLZ78 *novoNoLZ78 = new NoLZ78;
    novoNoLZ78->indice = indice;
    novoNoLZ78->dados = dados;
    novoNoLZ78->proximo = NULL;

    NoLZ78 *atual = cabeca;
    while (atual!=NULL)
    {
        if (atual->proximo==NULL)
        {
            atual->proximo = novoNoLZ78;
            return;
        }
        atual = atual->proximo;
    }
}

NoLZ78 *buscaNo(NoLZ78 *cabeca, string dados)
{
    NoLZ78 *atual = cabeca;
    while (atual!=NULL)
    {
        if (dados.compare(atual->dados)==0)
        {
            return atual;
        }
        else
        {
            atual = atual->proximo;
        }
    }

    return NULL;
}

NoLZ78 *buscaNo(NoLZ78 *cabeca, int indice)
{
    NoLZ78 *atual = cabeca;
    while (atual!=NULL)
    {
        if (indice==atual->indice)
        {
            return atual;
        }
        else
        {
            atual = atual->proximo;
        }
    }
    return NULL;
}

bool deletaNo(NoLZ78 *cabeca, NoLZ78 *NoAExcluir)
{
    if (NoAExcluir==NULL)
    {
        return false;
    }
    else if (NoAExcluir==cabeca)
    {
        cabeca = NoAExcluir->proximo;
        delete NoAExcluir;
        return true;
    }
    else
    {
        NoLZ78 *atual = cabeca;
        while (atual)
        {
            if (atual->proximo==NoAExcluir)
            {
                atual->proximo = NoAExcluir->proximo;
                delete NoAExcluir;
                return true;
            }
            atual = atual->proximo;
        }
        return false;
    }
}

vector <string> cisao(string str, char delimitador)
{
    vector <string> interno;
    stringstream ss(str); // Turn the string into a stream.
    string simbolo;

    while (getline(ss, simbolo, delimitador))
    {
        interno.push_back(simbolo);
    }

    return interno;
}

LZ78::LZ78() = default;
LZ78::~LZ78() = default;

std::string LZ78::compressao(std::string entrada)
{
    NoLZ78 *dicionario = new NoLZ78;
    string palavra, resultado;
    int comprimento, ultimoVisto, indice = 1;

    comprimento = (int) entrada.length();
    palavra = entrada[0];
    st_NoLZ78(dicionario, 1, palavra);
    resultado += "0," + palavra;

    for (int i = 1; i < comprimento; i++)
    {
        string dados;
        dados = entrada[i];

        rechecar:
        NoLZ78 *busca = buscaNo(dicionario, dados);

        if (busca)
        {
            i++;
            dados += entrada[i];
            ultimoVisto = busca->indice;
            goto rechecar;
        }
        else
        {
            char zero;
            if (entrada[i]==' ')
            {
                zero = '0';
            }
            else
            {
                zero = entrada[i];
            }

            if ((int) dados.length() < 2)
            {
                resultado += " " + to_string(0) + "," + zero;
            }
            else
            {
                resultado += " " + to_string(ultimoVisto) + "," + zero;
            }

            indice++;
            if (i!=comprimento)
            {
                insereNo(dicionario, indice, dados);
            }
        }
    }

    return resultado;
}
std::string LZ78::descompressao(std::string entrada)
{
    NoLZ78 *dicionario = new NoLZ78;
    string resultado;

    vector <string> s_entrada = cisao(entrada, ' ');
    int zz = 2;
    for (int i = 0; i < s_entrada.size(); i++)
    {
        vector <string> ss_entrada = cisao(s_entrada[i], ',');

        if (i==0)
        {
            st_NoLZ78(dicionario, 1, ss_entrada[1]);
            resultado += ss_entrada[1];
        }
        else
        {
            NoLZ78 *pesquisado;
            string busca = ss_entrada[1];
            pesquisado = buscaNo(dicionario, stoi(ss_entrada[0]));
            if (pesquisado)
            {
                resultado += pesquisado->dados + busca;
                busca = pesquisado->dados + cisao(s_entrada[i], ',')[1];
                insereNo(dicionario, zz, busca);
            }
            else
            {
                if (stoi(ss_entrada[0])==0)
                {
                    insereNo(dicionario, zz, busca);
                }
                else
                {
                    insereNo(dicionario, zz, busca);
                }
                resultado += busca;
            }
            zz++;
        }
    }

    if (resultado[(int) resultado.length() - 1]=='0')
    {
        resultado = resultado.substr(0, resultado.size() - 1);
    }
    return resultado;
}
