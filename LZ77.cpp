#include "LZ77.h"
#include "iostream"
#include <list>
#include <string>

using namespace std;

//Comprime uma string para uma lista de triplas.

//A Tripla contem um dado para guardar o quanto para trás deve andar para achar o melhor caracter,
//outro dado para guardar o quanto de carcteres vão ser comprimidos, e outro do próximo caracter.

LZ77::LZ77() {}
LZ77::~LZ77() {}

list<Tripla> LZ77::codifica (string st)
{
    list<Tripla> lista;
    int tamanhoDicionario = 6;
    int tamanhoBuffer = 4;
    for(int i=0;i< st.size();i++)
    {
        int jump = 0; //O quanto para trás andar
        int size = 0; //Quantos vão ser comprimidos
        int j=0, s=0;

        //Achar o melhor conjunto de caracteres a serem escolhidos no dicionário

        while(i-jump >= 0 && jump <= tamanhoDicionario)
        {
            size = 0;
            while(st[i-jump+size] == st[i+size] && jump != 0)
            {
                size++;
            }
            if(size > s)
            {
                j = jump;
                s = size;
            }
            jump++;
        }

        i += s;
        Tripla temp;
        temp.c = st[i];
        temp.size = s;
        temp.jump = j;
        lista.push_back(temp);
    }
    return lista;
}