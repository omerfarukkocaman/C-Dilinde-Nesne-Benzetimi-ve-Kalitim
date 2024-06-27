#include "Habitat.h"

habitat habitatOlustur(int canliSayisi, int bitkiSayisi, int bocekSayisi, int sinekSayisi, int pireSayisi) {
    habitat this = (habitat)malloc(sizeof(struct Habitat));
    if (this == NULL) {
        perror("Bellek tahsisi basarisiz");
        exit(EXIT_FAILURE);
    }

    this->canlilar = (canli*)malloc(canliSayisi * sizeof(canli));
    this->bitkiler = (bitki*)malloc(bitkiSayisi * sizeof(bitki));
    this->bocekler = (bocek*)malloc(bocekSayisi * sizeof(bocek));
    this->sinekler = (sinek*)malloc(sinekSayisi * sizeof(sinek));
    this->pireler = (pire*)malloc(pireSayisi * sizeof(pire));

    if (this->canlilar == NULL || this->bitkiler == NULL || this->bocekler == NULL || this->sinekler == NULL || this->pireler == NULL) {
        perror("Bellek tahsisi basarisiz");
        exit(EXIT_FAILURE);
    }

    this->canliSayisi = 0;
    this->bitkiSayisi = 0;
    this->bocekSayisi = 0;
    this->sinekSayisi = 0;
    this->pireSayisi = 0;

    this->Duello = &Duello;
    this->canliEkle = &canliEkle;
    this->Basla = &Basla;
    this->habitatYoket = &habitatYoket;

    return this;
}

//Dosyadan okunan verilerle canli oluşturma fonksiyonu
void canliEkle(const habitat this, int deger, int konumX, int konumY)
{
    if (deger >= 1 && deger <= 9) 
    {
        this->bitkiler[this->bitkiSayisi++] = bitkiOlustur(deger, konumX, konumY, 'B');
        this->canlilar[this->canliSayisi++] = this->bitkiler[this->bitkiSayisi - 1]->super;
    }
    else if (deger >= 10 && deger <= 20) 
    {
        this->bocekler[this->bocekSayisi++] = bocekOlustur(deger, konumX, konumY, 'C');
        this->canlilar[this->canliSayisi++] = this->bocekler[this->bocekSayisi - 1]->super;
    } 
    else if (deger >= 21 && deger <= 50) 
    {
        this->sinekler[this->sinekSayisi++] = sinekOlustur(deger, konumX, konumY, 'S');
        this->canlilar[this->canliSayisi++] = this->sinekler[this->sinekSayisi - 1]->super->super;
    } 
    else if (deger >= 51 && deger <= 99) 
    {
        this->pireler[this->pireSayisi++] = pireOlustur(deger, konumX, konumY, 'P');
        this->canlilar[this->canliSayisi++] = this->pireler[this->pireSayisi - 1]->super->super;
    }
}

//2 canlının karşılaştırması
int Duello(const habitat this, canli canli1, canli canli2)
{
   if(canli1->simge=='B')
   {
        if(canli2->simge=='B')
        {
            if(canli1->deger>canli2->deger)
                return 1;
            else if(canli1->deger<canli2->deger)
                return 2;
            return 3;
        }
        else if(canli2->simge=='C')
        {
            return 2;
        }
        else if(canli2->simge=='S')
        {
            return 1;
        }
        else if(canli2->simge=='P')
        {
            return 1;
        }
   }
   else if(canli1->simge=='C')
   {
        if(canli2->simge=='B')
        {
            return 1;
        }
        else if(canli2->simge=='C')
        {
            if(canli1->deger>canli2->deger)
                return 1;
            else if(canli1->deger<canli2->deger)
                return 2;
            return 3;
        }
        else if(canli2->simge=='S')
        {
            return 2;
        }
        else if(canli2->simge=='P')
        {
            return 1;            
        }
   }
   else if(canli1->simge=='S')
   {
        if(canli2->simge=='B')
        {
            return 2;
        }
        else if(canli2->simge=='C')
        {
            return 1;
        }
        else if(canli2->simge=='S')
        {
            if(canli1->deger>canli2->deger)
                return 1;
            else if(canli1->deger<canli2->deger)
                return 2;
            return 3;
        }
        else if(canli2->simge=='P')
        {
            return 1;
        }
   }
   else if(canli1->simge=='P')
   {
        if(canli2->simge=='B')
        {
            return 2;
        }
        else if(canli2->simge=='C')
        {
            return 2;
        }
        else if(canli2->simge=='S')
        {
            return 2;
        }
        else if(canli2->simge=='P')
        {
            if(canli1->deger>canli2->deger)
                return 1;
            else if(canli1->deger<canli2->deger)
                return 2;
            return 3;
        }
   }
   return 1;
}
//Program boyu gerçekleştirilecek olan savaş
void Basla(const habitat this)
{
    int tur=0;
    int mevcut=0;
    int rakip=1;
    int index=0;
    
    for(int i=0;i<this->canliSayisi-1;i++)
    {
        tur++;   
        printf("\n");
        system("cls");
        int sayac=0;

        /* duello durumu 1
        (kazanan 1.canlı (mevcut))*/
        if(this->Duello(this,this->canlilar[mevcut],this->canlilar[rakip])==1)
        {
            this->canlilar[rakip]->simge='X'; //ölen canlı X olarak işaretleniyor
            rakip++;
        }

        /* duello durumu 2
        (kazanan 2.canlı (rakip))*/
        else if(this->Duello(this,this->canlilar[mevcut],this->canlilar[rakip])==2)
        {
            this->canlilar[mevcut]->simge='X'; //ölen canlı X olarak işaretleniyor
            mevcut=rakip;
            rakip++;
        }

        /* duello durumu 3
        (beraberlik var kazanan sona en yakın olan canlı (rakip))*/
        else if(this->Duello(this,this->canlilar[mevcut],this->canlilar[rakip])==3)
        {
            this->canlilar[rakip]->simge='X'; //Ölen canlı X olarak işaretleniyor
            rakip++;
        }
        for(int i=0;i<this->canliSayisi;i++) //Gerçekleştirilen adım sonrası tüm canlı simgeleri ekrana yazdırılıyor
        {
            if(this->canlilar[i]->konumX>=sayac) //Satır kontrolü
            {
                printf("\n");
                sayac++;
            }
            printf("%c ",this->canlilar[i]->gorunum(this->canlilar[i]));
        }
        printf("\n%d. tur",tur);
    }
    //Oyun bitti kazanan belirlendi
    printf("\n-------------------------------------------------------------\nKazanan: %c : (%d,%d)",this->canlilar[mevcut]->gorunum(this->canlilar[mevcut]),this->canlilar[mevcut]->konumX, this->canlilar[mevcut]->konumY); 
}
void habitatYoket(const habitat this) {
    if (this == NULL) return;

    for (int i = 0; i < this->bitkiSayisi; i++) {
        bitkiYoket(this->bitkiler[i]);
    }
    for (int i = 0; i < this->bocekSayisi; i++) {
        bocekYoket(this->bocekler[i]);
    }
    for (int i = 0; i < this->pireSayisi; i++) {
        pireYoket(this->pireler[i]);
    }
    for (int i = 0; i < this->sinekSayisi; i++) {
        sinekYoket(this->sinekler[i]);
    }

    free(this->canlilar);
    free(this->bitkiler);
    free(this->bocekler);
    free(this->sinekler);
    free(this->pireler);
    free(this);
}