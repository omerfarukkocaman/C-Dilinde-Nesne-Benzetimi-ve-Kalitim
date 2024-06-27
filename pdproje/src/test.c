
#include <stdio.h>
#include <stdlib.h>
#include "Sinek.h"
#include "Pire.h"
#include "Habitat.h"
#include <string.h>

int main()
{
    int bitkiSayisi=0;
    int bocekSayisi=0;
    int sinekSayisi=0;
    int pireSayisi=0;
    int satirSayisi=0;
    int sutunSayisi=0;
    int *sayiPtr=NULL;
    int elemanSayisi=0;
    int boyut=100;
    const char* dosyaAdi = "src/Veri.txt";

    //Veri.txt dosyasını açma
    FILE *dosya = fopen(dosyaAdi, "r");
    if (dosya == NULL) {
        perror("Dosya acma hatasi");
        exit(EXIT_FAILURE);
    }
    sayiPtr = (int *) malloc(boyut * sizeof(int)); //Dosyadan okunan sayıları yerleştirmek için bir int dizisi
    int sayi;
    char satir[10000];

    //satır satır okuma
    while (fgets(satir, sizeof(satir), dosya) != NULL) 
    {
        satirSayisi++;
        char *sayi = strtok(satir, " "); // Boşluklara göre satırı bölme
        while (sayi != NULL) 
        {   
            sayiPtr[elemanSayisi] = atoi(sayi); // Stringi int' e çevirme
            
            if (sayiPtr[elemanSayisi] >= 1 && sayiPtr[elemanSayisi] <= 9) 
            {
                bitkiSayisi++;
            } 
            else if (sayiPtr[elemanSayisi] >= 10 && sayiPtr[elemanSayisi] <= 20) 
            {
                bocekSayisi++;
            } 
            else if (sayiPtr[elemanSayisi] >= 21 && sayiPtr[elemanSayisi] <= 50) 
            {
                sinekSayisi++;
            } 
            else if (sayiPtr[elemanSayisi] >= 51 && sayiPtr[elemanSayisi] <= 99) 
            {
                pireSayisi++;
            }
            else
            {
                printf("Hatali veri girisi var");
                return 0;
            }
            elemanSayisi++;
            if(elemanSayisi>=boyut)
            {
                boyut=boyut+10;
                sayiPtr = (int *) realloc(sayiPtr, boyut * sizeof(int));
            }
            sayi = strtok(NULL, " ");
        }
    }
    fclose(dosya);
    sutunSayisi=elemanSayisi/satirSayisi;
    habitat Arena;

    //Savaş habitatı oluşturma
    Arena = habitatOlustur(elemanSayisi, bitkiSayisi, bocekSayisi, sinekSayisi, pireSayisi);
    int index=0;
    for (int i = 0; i < satirSayisi; i++)
    {
        for (int j = 0; j < sutunSayisi; j++)
        {
            //Habitata canlıları ekleme
            Arena->canliEkle(Arena,sayiPtr[index],i,j);
            index++;
        }
    }
    
    //Program giriş ekranı yazdırma
    system("cls");
    printf("Giris:\n-------------------------------------------------------------");
    index=0;
    char basla;
    for(int i=0;i<Arena->canliSayisi;i++) //Başlangıç durumu yazdırma
    {
        if(Arena->canlilar[i]->konumX>=index)
        {
            printf("\n");
            index++;
        }
        printf("%c ",Arena->canlilar[i]->gorunum(Arena->canlilar[i]));
    }
    printf("\n-------------------------------------------------------------\nBaslamak icin enter basiniz...");
    scanf("%c",&basla);
    Arena->Basla(Arena); //Savaşı başlatma
    Arena->habitatYoket(Arena); //Oluşturulan habitatı silme
    free(sayiPtr);
    return 0;
}