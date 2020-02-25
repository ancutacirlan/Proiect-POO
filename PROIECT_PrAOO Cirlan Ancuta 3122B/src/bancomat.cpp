#include "bancomat.h"
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <fstream>

using namespace std;

bancomat::bancomat()
{
    stareBancomat=60000;

}



ostream& operator<<(ostream&c,const bancomat &p)
{
    cout<<endl<<"Bancomatul contine suma: "<<p.stareBancomat;
}






void bancomat:: retragereSuma( Cont &a)
{
    if (stareBancomat>0)
    {
        long x;
        cout<<"Suma retragere: ";
        cin>>x;
        if(x<=a.soldCont())
        {
            if (x<=stareBancomat)
            {
                cout<<"Suma a fost retrasa din contul tau!"<<endl;
                stareBancomat=stareBancomat-x;
                a.retBani(x);
            }

            else
                throw SumaIndisponibilaB();

        }
        else

            throw SumaIndiponibilaC();
    }

    else
        throw SumaIndisponibilaB();
}

void bancomat::depunereBancomat(Cont&a)
{
    if (stareBancomat<80000)
    {
        long x;
        cout<<"Suma depusa: ";
        cin>>x;

        if (x+stareBancomat<80000)
        {
            cout<<"Suma a fost depusa in contul dumneavoastra!"<<endl;
            stareBancomat=stareBancomat+x;
            a.setSold(x);
        }

        else
            cout<<"Bancomat plin!";

    }

    else
        cout<<"Bancomat plin";


}

long bancomat::interogareSold(Cont &a)
{
    return a.soldCont();
}

void bancomat::afisareFisier(ofstream&g,Cont &a)
{
    int ac=0;
    char h[100];
    g.open("date.txt");

    if(g.is_open())
    {
        g<<"  \b";
        if(ac==0)
        {
            g<<"Numele utilizatorului: ";
            ac++;
        }

        g<<a.retUser()<<endl<<"Sold cont: ";
        g<<a.soldCont();
    }

    else
        throw EroareFisier();
    g.close();
}
