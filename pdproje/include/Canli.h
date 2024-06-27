#ifndef URETIM_H
#define URETIM_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Canli
{
    int deger;
    bool durum;
    char simge;
    char simge2;
    int konumX;
    int konumY;
    char (*gorunum)();
    void (*canliYoket)(struct Canli*);
};

typedef struct Canli* canli;


canli canliOlustur(int deger,int X,int Y,char simge);
void canliYoket(const canli);




#endif