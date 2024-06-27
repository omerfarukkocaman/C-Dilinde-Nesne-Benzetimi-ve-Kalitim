#include "Pire.h"




pire pireOlustur(int deger,int X,int Y,char simge){
    pire this;
    this = (pire)malloc(sizeof(struct Pire));
    this->super = bocekOlustur(deger,X,Y,simge);
    this->super->super->gorunum=&pGorunum;
    this->pireYoket = &pireYoket;
    return this;
}
char pGorunum(const canli this)
{
    return this->simge;
}
void pireYoket(const pire this){
    if(this==NULL) return;
    this->super->bocekYoket(this->super);
    free(this);
    
}
