#include "Sinek.h"



sinek sinekOlustur(int deger,int X,int Y,char simge){
    sinek this;
    this = (sinek)malloc(sizeof(struct Sinek));
    this->super = bocekOlustur(deger,X,Y,simge);
    this->super->super->gorunum=&sGorunum;
    this->sinekYoket = &sinekYoket;
    return this;
}
char sGorunum(const canli this)
{
    return this->simge;
}

void sinekYoket(const sinek this){
    if(this == NULL) return;
    this->super->bocekYoket(this->super);
    free(this);
}