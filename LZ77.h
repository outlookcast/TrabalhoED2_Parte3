#ifndef TRABALHOED2_PARTE3_LZ77_H
#define TRABALHOED2_PARTE3_LZ77_H

#include <string>
#include <list>

using namespace std;

struct Tripla
{
    char c;
    int jump;
    int size;
};

class LZ77 {
    public:
        list<Tripla> codifica(string st);
};


#endif //TRABALHOED2_PARTE3_LZ77_H
