#include "Bitki.h"



 bitki bitkiOlustur(int deger,int X, int Y,char simge){
    bitki this;
    this = (bitki)malloc(sizeof(struct Bitki));
    this->super = canliOlustur(deger,X,Y,simge);
    this->super->gorunum=&bGorunum;
    this->bitkiYoket = &bitkiYoket;
    return this;
}
char bGorunum(const canli this)
{
    return this->simge;
}
void bitkiYoket(const bitki this)
{
    if(this==NULL) return;
    this->super->canliYoket(this->super);
    free(this);
}