#ifndef TRABALHOED2_PARTE3_ARVHUFFMAN_H
#define TRABALHOED2_PARTE3_ARVHUFFMAN_H
#include "No.h"
#include <bits/stdc++.h>
#include <list>

using  namespace std;

struct Codigo
{
    string codigo;
    char caracter;
};

struct Caracter
{
    char caracter;
    int frequencia;
};

class ArvHuffman
{
    class comparador
    {
    public:
        bool operator()(No* esq, No* dir)
        {
            return (esq->getFrequencia() > dir->getFrequencia());
        }
    };

private:

    list<Codigo> listaDeCodigos;
    No * raiz;
    string stringComprimida;

    void desaloca(No * no);
    void montaArvore(vector<Caracter> vetorDeCaracter);
    void auxGeraCodigo(No* no, string caminho);
    void calculaFrequencia(string frase);

public:

    ArvHuffman();
    ~ArvHuffman();
    list<Codigo> getListaDeCodigos();
    string retornaStringComprimida(string frase);
    string descomprime();
};


#endif //TRABALHOED2_PARTE3_ARVHUFFMAN_H
