//
// Created by caveira on 6/24/18.
//

#ifndef TRABALHOED2_PARTE3_LZ78_H
#define TRABALHOED2_PARTE3_LZ78_H

#include <string>
class LZ78
{
public:
    LZ78();
    std::string compressao(std::string entrada);
    std::string descompressao(std::string entrada);
    virtual ~LZ78();
};

#endif //TRABALHOED2_PARTE3_LZ78_H
