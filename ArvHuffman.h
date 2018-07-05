#ifndef TRABALHOED2_PARTE3_ARVHUFFMAN_H
#define TRABALHOED2_PARTE3_ARVHUFFMAN_H
#include "NoHuffman.h"
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
    bool operator()(NoHuffman* esq, NoHuffman* dir)
    {
        return (esq->getFrequencia() > dir->getFrequencia());
    }
};

class ArvHuffman
{
private:

    string stringOriginal;
    list<Codigo> listaDeCodigos;
    NoHuffman * raiz;
    string stringComprimida;

    void desaloca(NoHuffman * no);
    void montaArvore(vector<Caracter> vetorDeCaracter);
    void auxGeraCodigo(NoHuffman* no, string caminho);
    void calculaFrequencia(string frase);

public:

    ArvHuffman();
    ~ArvHuffman();
    list<Codigo> getListaDeCodigos();
    string retornaStringComprimida(string frase);
    string descomprime();
};

#endif //TRABALHOED2_PARTE3_ARVHUFFMAN_H
