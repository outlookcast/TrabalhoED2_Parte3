#include "LZW.h"

LZW::LZW() = default;

LZW::~LZW() = default;

// Comprime uma string para uma lista de simbolos de saida.
// O resultadoado sera escrito no iterador de retorn
// Comecando em "resultadoado"; o ultimo iterador eh retornado.
std::vector<int> LZW::compressao(const std::string &naoComprimido, std::vector<int> resultado)
{
    // Monta o dicionario
    int tamDic = 256;

    std::map<std::string, int> dicionario;
    for (int i = 0; i < 256; i++)
    {
        dicionario[std::string(1, i)] = i;
    }

    std::string w;
    for (std::string::const_iterator it = naoComprimido.begin(); it!=naoComprimido.end(); ++it)
    {
        char c = *it;
        std::string wc = w + c;
        if (dicionario.count(wc))
        {
            w = wc;
        }
        else
        {
            resultado.push_back(dicionario[w]);

            // Adiciona wc ao dicionario.
            dicionario[wc] = tamDic++;
            w = std::string(1, c);
        }
    }

    // saida do código para w
    if (!w.empty())
    {
        resultado.push_back(dicionario[w]);
    }
    return resultado;
}

// Descomprime uma lista de saida ks para uma string
// "inicio" e "fim" devem formar um intervalo valido de inteiros
std::string LZW::descompressao(std::vector<int>::iterator inicio, std::vector<int>::iterator fim)
{
    // Monta o dicionario.
    int tamDic = 256;
    std::map<int, std::string> dicionario;
    for (int i = 0; i < 256; i++)
    {
        dicionario[i] = std::string(1, i);
    }

    std::string w(1, *inicio++);
    std::string resultado = w;
    std::string entrada;
    for (; inicio!=fim; inicio++)
    {
        int k = *inicio;
        if (dicionario.count(k))
        {
            entrada = dicionario[k];
        }
        else if (k==tamDic)
        {
            entrada = w + w[0];
        }
        else
        {
            throw "k mal comprimido";
        }

        resultado += entrada;

        // Adiciona w+entrada[0] ao dicionario.
        dicionario[tamDic++] = w + entrada[0];

        w = entrada;
    }
    return resultado;
}
