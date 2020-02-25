#ifndef PERSOANA_H
#define PERSOANA_H
#include <string.h>
#include <fstream>

class Persoana
{
public:
    Persoana(char _name[]=" ndef", char _pre[]=" ndef")
    {
        strcpy(nume, _name);
        strcpy(prenume, _pre);
    }
    ~Persoana();
    virtual char* Nume();

protected:
    char nume[20];
    char prenume[20];
private:
};


#endif // PERSOANA_H
