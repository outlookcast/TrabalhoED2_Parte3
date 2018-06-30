#include <bits/stdc++.h>
#include "LZ78.h"
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
    LZW *arv = new LZW();//instancia algoritmo de compressao LZW
    std::vector<int> comprimido;//vetor de inteiros para armazenar dados comprimidos

    std::string dado;//variavel para armazenar o dado a ser comprimido
    //dado = "SEROUNAOSERSEROUNAOSER"; //EXEMPLO 1
    dado = "banaca bacana"; //EXEMPLO 2
    cout << "String a ser comprimida|descomprimida: " << dado << endl;
    comprimido = arv->compressao(dado, comprimido);//chama o algoritmo de compressao e armazena o resultado na variavel comprimido
    cout << "Codigo de compressao: ";
    copy(comprimido.begin(), comprimido.end(), std::ostream_iterator<int>(std::cout, ", "));//imprime a compressao

    std::string resultado; // intancia variavel para receber a concatenacao de inteiros transformados em string
    for (std::vector<int>::iterator i = comprimido.begin(); i!=comprimido.end(); i++)//itera sobre o vetor de inteiro
    {
        resultado += to_string(i.operator*()) + ", "; // transforma inteiro no indice i em string
    }
    cout << "\nString 'resultado': " << resultado;
    std::cout << std::endl;

    cout << "Descompressao: ";
    std::string decomprimido = arv->descompressao(comprimido.begin(), comprimido.end());//chama o algoritmo de descompressao
    std::cout << decomprimido << std::endl;//imprime string

    /**************
    * TESTE LZ-78 *
    ***************/
    /*
    LZ78 *arv = new LZ78(); //instancia objeto
    std::string dado, resultado; //intancia variavel que conterá o dado a ser comprimido e a variavel que receberá a compressao
    dado = "SEROUNAOSERSEROUNAOSER"; //EXEMPLO 1
    //dado = "banaca bacana"; //EXEMPLO 2

    cout << "String a ser comprimida|descomprimida: " << dado << endl;
    resultado = arv->compressao(dado);//chama o algoritmo de compressao
    cout << "Codigo de compressao: ";
    cout << resultado;//imprime a compressao
    std::cout << std::endl;

    cout << "Descompressao: ";
    std::string decomprimido = arv->descompressao(resultado);//chama o algoritmo de descompressao
    std::cout << decomprimido << std::endl;//imprime string
    */
    return 0;
}