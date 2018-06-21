#include "ArvHuffman.h"
#include <iostream>


using  namespace std;

ArvHuffman::ArvHuffman()
{
    this->raiz = NULL;
    this->stringComprimida = "";
}

ArvHuffman::~ArvHuffman()
{
    this->desaloca(this->raiz);
}

void ArvHuffman::desaloca(No * no)
{
    if(no!= NULL)
    {
        No * auxEsq = no->getEsq();
        No * auxDir = no->getDir();
        delete no;
        this->desaloca(auxEsq);
        this->desaloca(auxDir);
    }
}

void ArvHuffman::montaArvore(vector<Caracter> vetorDeCaracter)
{
    priority_queue<No*, vector<No*>, comparador> minHeap;

    for (int i = 0; i < vetorDeCaracter.size(); ++i)
    {
        minHeap.push(new No(vetorDeCaracter[i].caracter, vetorDeCaracter[i].frequencia));
    }

    while (minHeap.size() != 1)
    {
        No * esq;
        esq = minHeap.top();
        minHeap.pop();

        No * dir;
        dir = minHeap.top();
        minHeap.pop();

        No * top;
        top = new No(NULL, esq->getFrequencia() + dir->getFrequencia());
        top->setEsq(esq);
        top->setDir(dir);

        minHeap.push(top);
    }

    this->raiz = minHeap.top();

    this->auxGeraCodigo(this->raiz,"");
}

void ArvHuffman::auxGeraCodigo(No* no, string caminho)
{

    if(no != NULL)
    {
        if (no->getCaracter() != NULL)
        {
            Codigo a;
            a.caracter = no->getCaracter();
            a.codigo = caminho;
            this->listaDeCodigos.push_back(a);
        }
        auxGeraCodigo(no->getEsq(), caminho + "0");
        auxGeraCodigo(no->getDir(), caminho + "1");
    }
}


list<Codigo> ArvHuffman::getListaDeCodigos()
{
    return this->listaDeCodigos;
}

void ArvHuffman::calculaFrequencia(string frase)
{
    list<Caracter> listaDeCaracteres;
    for(int i=0; i<frase.size(); i++)
    {
        bool verifica = false;
        for( list<Caracter>::iterator iter= listaDeCaracteres.begin(); iter != listaDeCaracteres.end(); iter++ )
        {
            if(iter->caracter == frase[i])
            {
                verifica = true;
                iter->frequencia++;
                break;
            }
        }
        if(verifica == false)
        {
            Caracter car;
            car.caracter = frase[i];
            car.frequencia = 1;
            listaDeCaracteres.push_back(car);
        }

    }
    char vetorDeCaracteres[listaDeCaracteres.size()];
    int vetorDeFrequencias[listaDeCaracteres.size()];
    vector<Caracter> vetorDeCaracter;
    for( list<Caracter>::iterator iter= listaDeCaracteres.begin(); iter != listaDeCaracteres.end(); iter++ )
    {
        ///cout<<iter->caracter<<" "<<iter->frequencia<<endl; ///Para fins de debugar :)
        Caracter caracter;
        caracter.caracter = iter->caracter;
        caracter.frequencia = iter->frequencia;
        vetorDeCaracter.push_back(caracter);
    }
    this->montaArvore(vetorDeCaracter);
}

string ArvHuffman::retornaStringComprimida(string frase)
{
    this->calculaFrequencia(frase);
    string stringComprimida = "";
    for(int i=0;i<frase.size();i++)
    {
        for(list<Codigo>::iterator iter= this->listaDeCodigos.begin(); iter != this->listaDeCodigos.end(); iter++ )
        {
            if(frase[i] == iter->caracter)
            {
                stringComprimida += iter->codigo;
                break;
            }
        }
    }
    this->stringComprimida = stringComprimida;
    return stringComprimida;
}


string ArvHuffman::descomprime()
{
    string final = "";
    if(this->stringComprimida != "")
    {
        No * p = this->raiz;
        for(int i=0;i<this->stringComprimida.size();i++)
        {
            if(this->stringComprimida[i]=='0')
            {
                if(p->getEsq() != NULL)
                    p = p->getEsq();
                else if(p->getCaracter() != NULL && p->getEsq() == NULL && p->getDir() == NULL)
                {
                    final += p->getCaracter();
                    p = this->raiz;
                    i--;
                }
            }
            else if(this->stringComprimida[i]=='1')
            {
                if(p->getDir() != NULL)
                    p = p->getDir();
                else if(p->getCaracter() != NULL && p->getEsq() == NULL && p->getDir() == NULL)
                {
                    final += p->getCaracter();
                    p = this->raiz;
                    i--;
                }
            }
        }
        return final+'\0';
    }
}