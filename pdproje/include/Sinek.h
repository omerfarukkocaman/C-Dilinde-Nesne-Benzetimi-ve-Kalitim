#ifndef SINEK_H
#define SINEK_H

#include "Bocek.h"

struct Sinek
{
    bocek super;
    void (*sinekYoket)(struct Sinek*);
};

typedef struct Sinek* sinek;



char sGorunum();
sinek sinekOlustur(int deger,int X,int Y,char simge);
void sinekYoket(const sinek);







#endif