#include "controlaArquivo.h"
#include "question.h"
#include <iostream>// std::cout
#include <fstream>//manipulacao de arquivo
#include <string>// std::string, std::stoi

controlaArquivo::controlaArquivo()
{
    //ctor
}

controlaArquivo::~controlaArquivo()
{
    //dtor
}

int controlaArquivo::converteEmNumero(string texto)
{
    int i = 0, num = 0;
    bool negativo = false;
    while (texto[i] != '\0')
    {
        if (texto[i] == 45){
            negativo = true;
            i++;
        }
        else
        {
            num = num*10 + (texto[i]-48);
            i++;
        }
    }
    if (negativo)
    {
        num = num*(-1);
    }
    return num;
}

//essa função separa um elemento "entre vírgulas", considerando apenas as vírgulas válidas
string controlaArquivo::isolaConteudo(char buffer[], int i)
{
    string elemento = "";
    //caso base: o elemento não começa com uma aspas, portando basta deslocar até a próxima vírgula
    if (buffer[i] != '"')
    {
        while (buffer[i] != ',' && buffer[i] != '\n' && buffer[i] != '\0')
        {
            elemento = elemento + buffer[i];
            i++;
        }
    }
    else
    {
        //caso complicado: caso o elemento comece com uma aspas
        elemento = '"';
        i++;                //coloca a primeira aspas no elemento e anda pra frente, pra não parar de imediato.
        bool flag = true;   //flag que determina que devemos continuar lendo.
        while (flag)
        {
            elemento = elemento + buffer[i];
            if (buffer[i] == '"')
            {
                //se o char guardado for uma aspas
                if (buffer[i+1] == '"')
                {
                    //se o próximo também for uma aspas, guarda ela também e adiante
                    elemento = elemento + buffer[i+1];
                    i++;    //nesse caso há um incremento adicional para que a segunda aspas não seja lida no próximo loop
                }
                else if (buffer[i+1] == ',' || buffer[i+1] == '\n' || buffer[i+1] == '\0')
                {
                    flag = false;               //se houver apenas uma aspas e for o final, pode parar que encontramos o fim do elemento
                }
                else throw "Ops, parece que o arquivo está fora do padrão especificado.";
            }
            i++;
        }
    }
    return elemento;
}

question* controlaArquivo::importaQuestoes(int numQuestoes)  //importa as questoes como objetos da classe question
{
    question* vetorQuestoes = new question[numQuestoes];
    int n = 0;          //contador de questões lidas
    string elemento;    //onde ele vai colocar cada elemento do csv antes de inserir no objeto question

    ifstream arquivo ("Questions.csv");
    if (arquivo.is_open())
    {
        //medindo o tamanho do arquivo
        arquivo.seekg(0, arquivo.end);
        int tamanho = arquivo.tellg();
        arquivo.seekg(0, arquivo.beg);

        //criando um vetor de char com todo o arquivo dentro
        char* buffer = new char[tamanho];
        arquivo.read(buffer, tamanho);
        int i = 45; //considerando o arquivo com cabeçalho.

        //separando os elementos e criando as questoes
        while (n < numQuestoes)
        {

            elemento = isolaConteudo(buffer, i);
            vetorQuestoes[n].setId(converteEmNumero(elemento));     //peguei o ID
            i = i + elemento.length() +1;

            elemento = isolaConteudo(buffer, i);
            if (elemento == "NA")   //existem usuários que não tem identificação
            {
                vetorQuestoes[n].setUser(0);
            }
            else vetorQuestoes[n].setUser(converteEmNumero('0' + elemento));     //peguei o UserID}
            i = i + elemento.length() +1;

            elemento = isolaConteudo(buffer, i);
            vetorQuestoes[n].setDate(elemento);         //peguei a data
            i = i + elemento.length() +1;

            elemento = isolaConteudo(buffer, i);
            vetorQuestoes[n].setScore(converteEmNumero(elemento));  //peguei o score
            i = i + elemento.length() +1;

            elemento = isolaConteudo(buffer, i);
            vetorQuestoes[n].setTitle(elemento);        //peguei o Title
            i = i + elemento.length() +1;

            elemento = isolaConteudo(buffer, i);
            vetorQuestoes[n].setBody(elemento);         //peguei o Body
            i = i + elemento.length() +1;

            //cout << q << " " << vetorQuestoes[q].getId() << endl; //descomente para acompanhar a importação
            n++;
        }
        delete buffer;

    }
    else (cout << "Nao consegui abrir o arquivo.");
    cout << "importacao concluida" << endl;
    return vetorQuestoes;
}

int* controlaArquivo::importaIds (int numQuestoes)
{
    //importa somente os IDs das questoes como INT
    int* ids = new int[numQuestoes];                             //vetor para retornar
    question* vetorQuestoes = importaQuestoes(numQuestoes);      //chama a outra função
    int q = 0;                                                   //pega só os IDs
    for (q; q<numQuestoes; q++)
    {
        ids[q] = vetorQuestoes[q].getId();
        //cout << q << " " << ids[q] << endl;                    //descomente para acompanhar a importação
    }
    delete vetorQuestoes;
    return ids;
}

string* controlaArquivo::vetorDeBodys (int numQuestoes)
{
    //importa somente os IDs das questoes como INT
    string* bodys = new string[numQuestoes];                     //vetor para retornar
    question* vetorQuestoes = importaQuestoes(numQuestoes);      //chama a outra função
    int q = 0;                                                   //pega só os IDs
    for (q; q<numQuestoes; q++)
    {
        bodys[q] = vetorQuestoes[q].getBody();
        //cout << q << " " << ids[q] << endl;                    //descomente para acompanhar a importação
    }
    delete vetorQuestoes;
    return bodys;
}

void controlaArquivo::imprimeSaida (string nome, int tamanho, double tempoGasto)
{
    fstream saida;
    saida.open("saida.txt");
    if (saida.is_open())
    {
        saida.seekg(0, saida.end);
        int lugar = saida.tellg();
        saida.seekp(lugar);
        saida << nome << " comprimiu " << tamanho <<" strings em " << tempoGasto << " milisegundos." << endl;
        saida.close();
    } else cout << "Nao consegui abrir o arquivo saida.txt";
}

void controlaArquivo::imprimeBodys (string* vetorDeBodys, int tamanho, string nomeDoArquivo)
{
    fstream arquivo;
    arquivo.open(nomeDoArquivo);
    if (arquivo.is_open())
    {
        arquivo << "Compressão de body de " << tamanho << " questões:" << endl;
        int i = 0;
        while (i < tamanho)
        {
            arquivo << vetorDeBodys[i] << endl;
            i++;
        }
        arquivo.close();
    } else cout << "Não consegui abrir o arquivo " << nomeDoArquivo;
}
