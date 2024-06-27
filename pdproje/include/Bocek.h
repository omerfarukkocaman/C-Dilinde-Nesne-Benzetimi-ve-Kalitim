#ifndef BOCEK_H
#define BOCEK_H

#include "canli.h"


struct Bocek
{
    canli super;
    void (*bocekYoket)(struct Bocek*);
};

typedef struct Bocek* bocek;
char cGorunum();
bocek bocekOlustur(int deger,int X,int Y,char simge);
void bocekYoket(const bocek);

#endif