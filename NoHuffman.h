#ifndef TRABALHOED2_PARTE3_NOHUFFMAN_H
#define TRABALHOED2_PARTE3_NOHUFFMAN_H


class NoHuffman
{
private:
    char caracter;
    int freq;
    NoHuffman * esq;
    NoHuffman * dir;
    bool verificador;

public:
    NoHuffman();
    char getCaracter();
    int getFrequencia();
    NoHuffman * getEsq();
    NoHuffman * getDir();
    void setEsq(NoHuffman * esq);
    void setDir(NoHuffman * dir);
    void setFreq(int freq);
    void setCaracter(char caracter);
    bool eChave();
    void setChave(bool chave);
};


#endif //TRABALHOED2_PARTE3_NOHUFFMAN_H
