#ifndef PIRE_H
#define PIRE_H

#include "Bocek.h"

struct Pire
{
    bocek super;
    void (*pireYoket)(struct Pire*);
};

typedef struct Pire* pire;



char pGorunum();
pire pireOlustur(int deger,int X,int Y,char simge);
void pireYoket(const pire);


#endif