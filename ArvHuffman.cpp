#include "ArvHuffman.h"
#include <iostream>
#include <list>
#include <iterator>

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

//desaloca memoria da arvore
void ArvHuffman::desaloca(NoHuffman * no)
{
    if(no!= NULL)
    {
        NoHuffman * auxEsq = no->getEsq();
        NoHuffman * auxDir = no->getDir();
        delete no;
        this->desaloca(auxEsq);
        this->desaloca(auxDir);
    }
}

void ArvHuffman::montaArvore(vector<Caracter> vetorDeCaracter)
{
    //Cria heap auxiliar para posicionar os valores
    priority_queue<NoHuffman, vector<NoHuffman*>,comparador> heap;

    //Armazena os valores
    for (int i = 0; i < vetorDeCaracter.size(); ++i)
    {
        NoHuffman * novoNo = new NoHuffman();
        novoNo->setCaracter(vetorDeCaracter[i].caracter);
        novoNo->setFreq(vetorDeCaracter[i].frequencia);
        novoNo->setChave(true);
        heap.push(novoNo);
    }

    //Vai remontando a heap, até restar somente uma árvore dentro da heap
    while (heap.size() > 1)
    {
        //Pega o menor elemento atual
        NoHuffman * esq = heap.top();
        heap.pop();

        //Pega segundo menor elemento atual
        NoHuffman * dir  = heap.top();
        heap.pop();

        /*Cria um nó sem caracter (insere 0, que na tabela ASCII é NULL)para servir como raiz pros dois atuais existentes
         * Seta os filhos e depois insere novamente na heap, até restar somente uma arvore dentro da heap
        */

        NoHuffman * raizAux = new NoHuffman();
        raizAux->setChave(false);
        raizAux->setFreq(esq->getFrequencia()+dir->getFrequencia());
        raizAux->setEsq(esq);
        raizAux->setDir(dir);
        heap.push(raizAux);
    }
    //Guarda o valor da raiz na nova Heap
    this->raiz = heap.top();

    this->auxGeraCodigo(this->raiz,"");
}

//Cria dicionario para converter string para codigo de huffman
void ArvHuffman::auxGeraCodigo(NoHuffman* no, string caminho)
{
    if(no != NULL)
    {
        if (no->eChave())
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

//Calcula frequencia dos caracteres de uma string
void ArvHuffman::calculaFrequencia(string frase)
{
    list<Caracter> listaDeCaracteres;
    for(int i=0; i<frase.size(); i++)
    {
        bool verifica = false;
        for( list<Caracter>::iterator iter= listaDeCaracteres.begin(); iter != listaDeCaracteres.end(); iter++ )
        {
            //se o caracter já está na string nós incrementamos +1 em sua frequência
            if(iter->caracter == frase[i])
            {
                verifica = true;
                iter->frequencia++;
                break;
            }
        }
        //Se não nós adicionamos o mesmo com frequência 1
        if(verifica == false)
        {
            Caracter car;
            car.caracter = frase[i];
            car.frequencia = 1;
            listaDeCaracteres.push_back(car);
        }

    }
    //Converte std::list para std::vector
    std::vector<Caracter> vetorDeCaracter{ std::begin(listaDeCaracteres), std::end(listaDeCaracteres) };
    this->montaArvore(vetorDeCaracter);
}
//retorna string comprimida (de 1's e 0's)
string ArvHuffman::retornaStringComprimida(string frase)
{
    this->stringOriginal = frase;
    this->calculaFrequencia(frase);
    string stringComprimida = "";
    //Navega na string original
    for(int i=0;i<frase.size();i++)
    {
        //Navega na lista de codigos a fim de procurar o codigo do caracter e ir armazenando numa string
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
    //Verifica se já houve compressao
    if(this->stringComprimida != "")
    {
        NoHuffman * p = this->raiz;
        for(int i=0;i<this->stringComprimida.size();i++)
        {
            /*
             * Se o caracter atual é 0 ele verifica se o no não tem filhos (esq = dir = NULL)
             * porque na árvore de huffman todos os nós que possuem caracter (que não são nós auxiliares)
             * possuem os filhos igual a NULL, ou seja, eles são folhas.
             *  Sendo assim, se os filhos não forem NULL, a busca deve continuar.
            */
            if(this->stringComprimida[i]=='0')
            {
                if(p->getEsq() != NULL)
                    p = p->getEsq();
                else if(p->eChave() && p->getEsq() == NULL && p->getDir() == NULL)
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
                else if(p->eChave() && p->getEsq() == NULL && p->getDir() == NULL)
                {
                    final += p->getCaracter();
                    p = this->raiz;
                    i--;
                }
            }
        }
        return final;
    }
}
