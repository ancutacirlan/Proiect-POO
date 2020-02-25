#ifndef CONT_H
#define CONT_H
#include "Persoana.h"
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
class Cont
{
public:
    Cont ()
    {

    }


    void setCont( char *_user, char *_PIN);
    void logareCont();
    long soldCont();
    void setSold(long x);
    void retBani(long val);
    //void afisareFisier(ofstream&);

    char* Nume()
    {
        char *s=new char[40];
        sprintf(s, "%s %s", user,PIN);
        return s;
    }
    char* retUser();
    ~Cont();

protected:
    char user[30];
    char PIN[4];
    long baniCont;

private:
};

#endif // CONT_H
