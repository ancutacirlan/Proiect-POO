#include "Exceptie.h"
Exceptie::Exceptie(char _catEx[],char _tipEx[])
{
    strcpy(catEx,_catEx);
    strcpy(tipEx,_tipEx);
}
void Exceptie::Print(void)
{
    cerr<<"exceptie["<<catEx<<"]"<<tipEx<<endl;
}
