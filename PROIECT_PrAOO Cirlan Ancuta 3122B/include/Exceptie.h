#ifndef EXCEPTIE_H
#define EXCEPTIE_H
#include <string.h>
#include <iostream>
using namespace std;
class Exceptie
{
    char catEx[50],tipEx[50];
public:
    Exceptie(char _catEx[],char _tipEx[]);
    void Print(void);


};
#endif // EXCEPTIE_H
