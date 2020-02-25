#include "Cont.h"
#include <string.h>
#include <iostream>
#include <stdio.h>
using namespace std;

Cont::~Cont()
{
    //dtor
}
void Cont::setCont( char *_user, char *_PIN)
{
    strcpy(user, _user);
    strcpy(PIN, _PIN);
    baniCont=0;

}

void Cont::retBani(long val)
{
    baniCont=baniCont-val;
}


void Cont::logareCont()
{
    int ok=0;
    char u[30],pin[4];
    do
    {
        cout<<"Introduceti numele utilizatorului: ";
        cin.getline(u,30,'\n');
        if(strcmp(user,u)==0)
        {
            break;
        }
    }
    while(1);

    do
    {
        cout<<"Introduceti PIN-ul: ";
        ///cin.getline(pin,4,'\n');
        gets(pin);
        if( strcmp(PIN,pin)==0)
        {
            break;
        }
    }
    while(1);
    cout<<"Logare reusita!"<<endl;
}

long Cont::soldCont()
{
    return baniCont;
}
void Cont::setSold(long x)
{
    baniCont=baniCont+x;
}
char* Cont::retUser()
{
    return user;
}


