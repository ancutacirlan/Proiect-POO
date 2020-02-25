#include "Persoana.h"
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
char* Persoana::Nume()
{
    char *s=new char[40];
    sprintf(s, "%s %s", nume, prenume);
    return s;
}


Persoana::~Persoana()
{
    //dtor
}
