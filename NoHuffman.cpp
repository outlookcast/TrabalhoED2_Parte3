#include "NoHuffman.h"
#include <iostream>

using namespace std;

NoHuffman::NoHuffman()
{
    this->esq = NULL;
    this->dir = NULL;
    this->verificador = false;
}

char NoHuffman::getCaracter()
{
    return this->caracter;
}

int NoHuffman::getFrequencia()
{
    return this->freq;
}

NoHuffman * NoHuffman::getEsq()
{
    return this->esq;
}

NoHuffman * NoHuffman::getDir()
{
    return this->dir;
}

void NoHuffman::setEsq(NoHuffman * esq)
{
    this->esq = esq;
}

void NoHuffman::setDir(NoHuffman * dir)

{
    this->dir = dir;
}

void NoHuffman::setFreq(int freq)
{
    this->freq = freq;
}

void NoHuffman::setCaracter(char caracter)
{
    this->caracter = caracter;
}

bool NoHuffman::eChave()
{
    return this->verificador;
}

void NoHuffman::setChave(bool chave)
{
    this->verificador = chave;
}
