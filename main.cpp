#include <bits/stdc++.h>
#include <list>
#include "No.h"
#include "ArvHuffman.h"
using namespace std;







int main()
{

    ArvHuffman * arv = new ArvHuffman();

    string valor = "banaca bacana";
    string resultadoCompressao = arv->retornaStringComprimida(valor);
    string resultadoDescompressao = arv->descomprime();
    cout<<"Valor: "<<valor<<endl;
    cout<<"Compressao: "<<resultadoCompressao<<endl;
    cout<<"Descompressao: "<<resultadoDescompressao<<endl;
    delete arv;
    return 0;
}