#include <bits/stdc++.h>
#include "LZ78.h"
#include "LZ77.h"


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
    /*
  auto *arv = new LZW();//constroi a classe com os algoritmo;

  std::vector<int> comprimido;//vetor de inteiros para dados comprimidos

  std::string dado;
  //dado = "SEROUNAOSERSEROUNAOSER"; //EXEMPLO 1
  dado = "banaca bacana"; //EXEMPLO 2

  cout << "String a ser comprimida|descomprimida: " << dado << endl;
  comprimido = arv->compressao(dado, comprimido);//chama o algoritmo de compressao
  cout << "Codigo de compressao: ";
  copy(comprimido.begin(), comprimido.end(), std::ostream_iterator<int>(std::cout, ", "));//imprime a compressao
  std::cout << std::endl;

  cout << "Descompressao: ";
  std::string decomprimido = arv->descompressao(comprimido.begin(), comprimido.end());//chama o algoritmo de descompressao
  std::cout << decomprimido << std::endl;//imprime string
  */

    /**************
    * TESTE LZ-78 *
    ***************/

    /*
    auto *arv = new LZ78();
    std::string dado, resultado;
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
    /**************
    * TESTE LZ-77 *
    ***************/

    cout<<"String para compressao:"<<endl;
    string st = "BANANABACANA";
    //  string st = "bananabanabofana";
    //  string st = "aaaaaaaaaaaaaaaaaaaaaa";
    cout<<st<<endl;
    cout<<"Codigo compressao:"<<endl;
    auto *lz = new LZ77();

    string saida = "";
    list<Tripla> lista;
    lista = lz->codifica(st);
    for (std::list<Tripla>::iterator it = lista.begin() ; it != lista.end(); ++it)
    {
        cout<<"<"<<it->jump<<","<<it->size<<","<<it->c<<">";
    }
    cout<<saida;
    delete lz;
    return 0;
}