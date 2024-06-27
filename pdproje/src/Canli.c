#include "Canli.h"


canli canliOlustur(int deger,int X,int Y,char simge){
    canli this;
    this = (canli)malloc(sizeof(struct Canli));
    this->deger=deger;
    this->konumY=Y;
    this->konumX=X;
    this->simge=simge;
    this->simge2=simge;
    this->durum=true;
    this->canliYoket = &canliYoket;
    return this;
}

void canliYoket(const canli this){
    if(this == NULL) return;
    free(this);
}
