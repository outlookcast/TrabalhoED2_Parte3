#ifndef TRABALHOED2_PARTE3_ARVHUFFMAN_H
#define TRABALHOED2_PARTE3_ARVHUFFMAN_H
#include "No.h"
#include <bits/stdc++.h>
#include <list>

using  namespace std;

//Usado como dicionário para poder comprimir a string original
struct Codigo
{
    string codigo;
    char caracter;
};

//Usado para gerar a lsita de frequencias
struct Caracter
{
    char caracter;
    int frequencia;
};

//Usado para poder comparar dois objetos usando uma propiedade dele
struct comparador
{
    bool operator()(No* esq, No* dir)
    {
        return (esq->getFrequencia() > dir->getFrequencia());
    }
};

class ArvHuffman
{
private:

    string stringOriginal;
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
