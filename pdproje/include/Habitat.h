#ifndef HABITAT_H
#define HABITAT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>
#include "Canli.h"
#include "Sinek.h"
#include "Pire.h"
#include "bitki.h"

struct Habitat
{
    canli *canlilar;
    bitki *bitkiler;
    bocek *bocekler;
    sinek *sinekler;
    pire *pireler;
    int canliSayisi;
    int bitkiSayisi;
    int bocekSayisi;
    int sinekSayisi;
    int pireSayisi;
    int (*Duello)(struct Habitat*,canli,canli);
    void (*canliEkle)(struct Habitat*,int,int,int);
    void (*Basla)(struct Habitat*);
    void (*habitatYoket)(struct Habitat*);
};

typedef struct Habitat* habitat;

habitat habitatOlustur(int canliSayisi,int bitkiSayisi,int bocekSayisi,int sinekSayisi,int pireSayisi);
int Duello(const habitat,canli,canli);
void canliEkle(const habitat,int deger,int konumX,int konumY);
void Basla(const habitat);
void habitatYoket(const habitat);



#endif