//
// Created by vinic on 21/06/2018.
//

#ifndef TRABALHOED2_PARTE3_NO_H
#define TRABALHOED2_PARTE3_NO_H


class No
{
private:
    char caracter;
    int freq;
    No * esq;
    No * dir;

public:
    No(char caracter, int freq);
    char getCaracter();
    int getFrequencia();
    No * getEsq();
    No * getDir();
    void setEsq(No * esq);
    void setDir(No * dir);
    void setFreq(int freq);
    void setCaracter(char caracter);
};


#endif //TRABALHOED2_PARTE3_NO_H
