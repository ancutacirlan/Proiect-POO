#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct element
{
    DATA info;
    struct element *urm;
};
typedef struct element Element;

LISTA newl()
{
    return NULL;
}
static ELEMENT creareElement(DATA x, ELEMENT urmator)
{
    ELEMENT w= (ELEMENT) malloc( sizeof(Element) );
    if(w!=NULL)
    {
        w->info = x;
        w->urm  = urmator;
    }
    return w;
}
LISTA ins_in_fata(LISTA l, DATA x)
{
    if(isFull(l)) return l;
    ELEMENT w = creareElement(x, l);
    return w!=NULL ? w : l;
}
LISTA ins_la_urma(LISTA l, DATA x)
{
    if(isFull(l)) return l;
    ELEMENT w = creareElement(x, NULL);
    if(w!=NULL)
    {
        if(isEmptyl(l))
        {
            return w;
        }
        else
        {
            ELEMENT p;
            for(p=l; p->urm!=NULL; p = p->urm) ;
            p->urm = w;
        }
    }
    return l;
}
LISTA sterge_ultimul(LISTA l)
{
    if(!isEmptyl(l))
    {
        if(l->urm == NULL)   //este unicul element
        {
            free(l);
            return NULL;
        }
        else               // sunt cel putin 2 elemente
        {
            ELEMENT p;
            for(p=l; p->urm->urm!=NULL; p = p->urm) ;
            // p adresa penultimului element
            free(p->urm);  // elimina ultimul
            p->urm = NULL; // penultimul devine ultimul
        }
    }
    return l;
}
LISTA sterge_primul(LISTA l)
{
    if(!isEmptyl(l))
    {
        ELEMENT p = l->urm;
        free(l);
        return p;
    }
    return l;
}
ELEMENT cauta(LISTA l, DATA k)
{
    if(!isEmptyl(l))
    {
        ELEMENT p;
        for(p=l; p!=NULL; p = p->urm)
        {
            if(p->info == k) return p;
        }
    }
    return NULL;
}
DATA primul(LISTA l)
{
    return isEmptyl(l) ? DATA() : l->info;
}
DATA ultimul(LISTA l)
{
    if(isEmptyl(l)) return DATA();
    for( ; l->urm!=NULL; l=l->urm);
    return l->info;

}

int nrElemente(LISTA l)
{
    int n=0;
    for( ; l!=NULL; l=l->urm) n++;
    return n;
}
LOGIC isEmptyl(LISTA l)
{
    return l==NULL;
}
LOGIC isFull(LISTA l)
{
    return FALS;
}
char *toStringl(LISTA l,char *s)
{
    /*char buf[100];
    sprintf(s, "l(%p) ={", l);
    if(isEmptyl(l))
    {
        strcat(s, "vida}");
    }
    else
    {
        ELEMENT p;
        for(p=l; p!=NULL; p = p->urm)
        {
            sprintf(buf, "\n%p: {"FORMAT", %p}%c", p, p->info, p->urm,
                    p->urm==NULL?'}' : ',');
            strcat(s, buf);
        }
    }
    return s;*/
}
LISTA Citire_fisier(char* numeFisier,LISTA l)
{
    ifstream f(numeFisier);
    char _nume[20];
    char _prenume[20];
    char _cnp[13],c[20];
    int n;
    f>>n;
    for(int i=1;i<=n;i++)
    {
        f>>_nume;
        f>>_prenume;
        strcpy(c,_prenume);
        f>>_cnp;
        Persoana p(_nume,c,_cnp);

        f>>_nume;
        f>>_prenume;

        float x = atof(_nume);
        float y = atof(_prenume);
        Salariu s(x,y);
        f>>_nume;
        Departament d(_nume);
        Angajat a(p,s,d);
        l = ins_la_urma(l,a);
    }
}
void Afisare(LISTA l)
{
    if(isEmptyl(l))
    {
        cout<<"nu exista angajati"<<endl;
    }
    else{
        ELEMENT p;
        for(p=1;p!=Null;p = p->urm)
        {
            cout<<p->info<<endl;
        }
    }
}
// ...
void destroyl(LISTA l)
{
    ELEMENT p;
    while(l!=NULL)
    {
        p=l;
        l = l->urm;
        free(p);
    }
}
