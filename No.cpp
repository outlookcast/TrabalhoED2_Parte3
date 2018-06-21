#include "No.h"
#include <iostream>

using namespace std;

No::No(char caracter, int freq)
{
    this->esq = NULL;
    this->dir = NULL;
    this->caracter = caracter;
    this->freq = freq;
}

char No::getCaracter()
{
    return this->caracter;
}

int No::getFrequencia()
{
    return this->freq;
}

No * No::getEsq()
{
    return this->esq;
}

No * No::getDir()
{
    return this->dir;
}

void No::setEsq(No * esq)
{
    this->esq = esq;
}

void No::setDir(No * dir)

{
    this->dir = dir;
}

void No::setFreq(int freq)
{
    this->freq = freq;
}

void No::setCaracter(char caracter)
{
    this->caracter = caracter;
}