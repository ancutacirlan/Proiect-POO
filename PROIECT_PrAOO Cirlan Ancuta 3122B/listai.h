#ifndef LISTAI_H_INCLUDED
#define LISTAI_H_INCLUDED
#include "data.h"

typedef struct element *ELEMENT;
typedef struct element *LISTA;
//
//----------------------------------
// Metodele (operatiile) TDA
//
LISTA newl();
LISTA ins_in_fata(LISTA l,  DATA x);
LISTA ins_la_urma(LISTA l, DATA x);
LISTA sterge_primul(LISTA l);
LISTA sterge_ultimul(LISTA l);
ELEMENT cauta(LISTA l, DATA k);
DATA primul(LISTA l);
DATA ultimul(LISTA l);
int nrElemente(LISTA l);
LOGIC isEmptyl(LISTA l);
LOGIC isFull(LISTA l);
char *toStringl(LISTA l,char *s);
void Afisare(LISTA l);
LISTA Citire_fisier(char* numeFisier,LISTA l);

// ...
void destroyl(LISTA l);

#endif // LISTAI_H_INCLUDED
