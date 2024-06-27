#include "Bocek.h"


bocek bocekOlustur(int deger,int X, int Y,char simge){
    bocek this;
    this = (bocek)malloc(sizeof(struct Bocek));
    this->super = canliOlustur(deger,X,Y,simge);
    this->super->gorunum=&cGorunum;
    this->bocekYoket = &bocekYoket;
    return this;
}
char cGorunum(const canli this)
{
    return this->simge;
}
void bocekYoket(const bocek this){
    if(this==NULL) return;
    this->super->canliYoket(this->super);
    free(this);
}