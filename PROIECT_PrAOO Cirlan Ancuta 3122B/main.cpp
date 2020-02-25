#include <iostream>
#include <conio.h>
#include "bancomat.h"
#include "listai.h"
#include "cont.h"
#include "Persoana.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <fstream>
using namespace std;

int main()
{

    ofstream g;
    char opt;
    cout<<"Bine ati venit!\n";
    long x;
    bancomat b1;
    Persoana p("Cirlan", "Ancuta"),p1("Popescu","Andreea"),p2("Maria","Alexandra");
    Cont c,c1,c2;
    c.setCont(p.Nume(),"2222");
    c.setSold(230);
    c1.setCont(p1.Nume(),"1111");
    c1.setSold(900);
    c2.setCont(p2.Nume(),"3333");
    c2.setSold(1000);
    Cont con[10];
    con[0]=c;
    con[1]=c1;
    con[2]=c2;

    char *s=new char[20];
    int i;
    int ok=0;
    cout<<"\n---Logare---\n";
    do
    {
        cout<<"\nIntroduceti user name: ";
        cin.getline(s,20, '\n');
        for(i=0; i<10; i++)
        {
            if(strcmp(con[i].retUser(),s)==0)
            {
                ok=1;
                break;
            }

        }
        if(ok==0)
            cout<<"\nNu aveti nici un cont cu acest user, reintroduceti sau parasiti programul: ";
    }
    while(ok!=1);
    con[i].logareCont();
    do
    {
        try
        {

            system("cls");
            cout<<"\n\t\t\t\t\t\tMENU";
            cout<<"\n***********************************************************************************************************************";
            cout<<"\n**R. Retragere numerar                                                                                               **";
            cout<<"\n**I. Interogare sold                                                                                                 **";
            cout<<"\n**D. Depunere numerar                                                                                                **";
            cout<<"\n**X. Delogare[renuntare]                                                                                             **";
            cout<<"\n***********************************************************************************************************************";

            cout<<"\n Dati optiunea : ";
            cin>>opt;
            switch(opt)
            {

            case 'R':
                ///cout<<"Contul are: "<<con[i].soldCont()<<endl;
                b1.retragereSuma(con[i]);
                getch();
                break;
            case 'I':
                cout<<"Sold Cont: "<<endl<<b1.interogareSold(con[i])<<endl;
                getch();
                break;
            case 'D':
                b1.depunereBancomat(con[i]);
                getch();
                break;
            case 'X':
                int x;

                cout<<"Doriti chitanta?"<<endl<<endl;
                cout<<"1.DA"<<endl;
                cout<<"2.NU"<<endl;
                cin>>x;
                if(x==1)
                {
                    b1.afisareFisier(g,con[i]);
                    cout<<"Chitanta a fost tiparita!"<<endl;
                    cout<<"La revedere!"<<endl;
                }

                if(x==2)
                    cout<<"La revedere!"<<endl;
                getch();
                return 0;

            default:
                cout<<"\nOptiune inexistenta!";

                break;

            }
        }

        catch(bancomat::SumaIndiponibilaC)
        {
            cout<<"Suma indisponibila in cont.";
            getch();
            break;
        }
        catch (bancomat::SumaIndisponibilaB)
        {
            cout<<"Suma indisponibila in bancomat.";
            getch();
            break;
        }
        catch (bancomat::EroareFisier)
        {
            cout<<"Eroare la deschiderea fisierului.";
            getch();
            break;
        }

    }
    while(1);


    return 0;
}
