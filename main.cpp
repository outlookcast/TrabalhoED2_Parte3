#include <bits/stdc++.h>
#include "LZW.h"

using namespace std;

int main()
{
    /*****************
     * TESTE HUFFMAN *
     *****************/

    /*
   ArvHuffman * arv = new ArvHuffman();

   string valor = "banaca bacana";
   string resultadoCompressao = arv->retornaStringComprimida(valor);
   string resultadoDescompressao = arv->descomprime();
   cout<<"Valor: "<<valor<<endl;
   cout<<"Compressao: "<<resultadoCompressao<<endl;
   cout<<"Descompressao: "<<resultadoDescompressao<<endl;
   delete arv;
    */

    /*************
     * TESTE LZW *
     *************/

    auto *arv = new LZW();//constroi a classe com os algoritmo;

    std::vector<int> comprimido;//vetor de inteiros para dados comprimidos

    std::string dado;
    //dado = "TOBEORNOTTOBEORTOBEORNOT"; //EXEMPLO 1
    dado = "banaca bacana"; //EXEMPLO 2

    cout << "String a ser comprimida|descomprimida: " << dado << endl;
    comprimido = arv->compressao(dado, comprimido);//chama o algoritmo de compressao
    cout << "Codigo de compressao: ";
    copy(comprimido.begin(), comprimido.end(), std::ostream_iterator<int>(std::cout, ", "));//imprime a compressao
    std::cout << std::endl;

    cout << "Descompressao: ";
    std::string decomprimido = arv->descompressao(comprimido.begin(), comprimido.end());//chama o algoritmo de descompressao
    std::cout << decomprimido << std::endl;//imprime string

    return 0;
}