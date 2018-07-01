#ifndef CONTROLAARQUIVO_H
#define CONTROLAARQUIVO_H
#include "question.h"

class controlaArquivo
{
     public:
        controlaArquivo();
        virtual ~controlaArquivo();
        question* importaQuestoes(int numQuestoes);
        int* importaIds (int numQuestoes);
        void imprimeSaida (string nome, int tamanho, double tempoGasto);
        string* vetorDeBodys(int numQuestoes);
        void imprimeBodys (string* vetorDeBodys, int tamanho, string nomeDoArquivo);
    protected:
    private:
        int converteEmNumero(string texto);
        string isolaConteudo(char buffer[], int i);
};

#endif // CONTROLAARQUIVO_H
