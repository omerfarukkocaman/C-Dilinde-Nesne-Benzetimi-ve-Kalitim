#ifndef BITKI_H
#define BITKI_H

#include "Canli.h"


struct Bitki
{
    canli super;
    void (*bitkiYoket)(struct Bitki*);
};

typedef struct Bitki* bitki;

char bGorunum(const canli);
bitki bitkiOlustur(int deger,int X,int Y,char simge);
void bitkiYoket(const bitki);

#endif