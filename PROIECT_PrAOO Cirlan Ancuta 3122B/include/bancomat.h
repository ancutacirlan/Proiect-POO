#ifndef BANCOMAT_H
#define BANCOMAT_H
#include<string.h>
#include"Persoana.h"
#include <iostream>
#include "Cont.h"
#include<fstream>
using namespace std;


class bancomat:public Cont
{
public:
    bancomat();
    void retragereSuma(Cont &a);
    long interogareSold(Cont &a);
    void depunereBancomat(Cont &a);
    void afisareFisier(ofstream&g, Cont &a);
    class SumaIndisponibilaB {};
    class SumaIndiponibilaC {};
    class EroareFisier {};
    friend ostream& operator<<(ostream&,const bancomat &);


protected:
    long stareBancomat;

private:
};

#endif // BANCOMAT_H
