#include <stdio.h>
#include <stdlib.h>

int main()
{
    int Film_Secim,Seans_Secim,Ogr_18,Gun,Boyut_Secim,Dublaj_Secim;
    float Fiyat,Film_Fiyat;
    printf("Bekir Turgut HAPOGLU 22100011036\n\n");
//Film Secimi
    printf("FILM SECIMI\n\n");
    printf("1-) Venom : Zehirli Ofke => 100TL\n2-) Assassins Creed      => 125TL\n3-) Inception            => 150TL \n\n");
    printf("Izlemek istediginiz filmi seciniz (1/2/3) : ");
    scanf("%d",&Film_Secim);

    if(Film_Secim == 1) Fiyat=100;
    else if(Film_Secim == 2) Fiyat=125;
    else Fiyat=150;
    Film_Fiyat=Fiyat;


    printf("\nGuncel Tutar : %.2lf\n",Fiyat);
    printf("-----------------------------------------------\n");

// Dublaj Secimi
    printf("DUBLAJ SECIMI\n\n");
    printf("1-)Turkce Dublaj + %%10 TL \n2-)Orijinal \n\nSeciniz (1/2) :");
    scanf("%d",&Dublaj_Secim);

    if(Dublaj_Secim == 1) Fiyat=Fiyat + (Film_Fiyat*0.10);

    printf("\nGuncel Tutar : %.2lf\n",Fiyat);
    printf("-----------------------------------------------\n");

//Goruntu Boyutu Secimi
    printf("GORUNTU BOYUTU SECIMI\n\n");
    printf("1-)3D Boyut + %%15 TL \n2-)2D Boyut \n\nSeciniz(1/2) :");
    scanf("%d",&Boyut_Secim);

    if(Boyut_Secim == 1) Fiyat=Fiyat + (Film_Fiyat*0.15);

    printf("\nGuncel Tutar : %.2lf\n",Fiyat);
    printf("-----------------------------------------------\n");

//Seans Secimi
    printf("SEANS SECIMI\n\n");
    printf("1-)Sabah seans %%5 Indirim\n2-)Oglen seans \n3-)Aksam seans \nSeciniz (1/2) : ");
    scanf("%d",&Seans_Secim);

    if(Seans_Secim == 1)Fiyat=Fiyat - (Film_Fiyat*0.05);

    printf("\nGuncel Tutar : %.2lf\n",Fiyat);
    printf("-----------------------------------------------\n");

//Durum Secimi
    printf("DURUM SECIMI\n\n");
    printf("1-)Ogrenci %%20 Indirim \n2-)18 yas alti %%50 Indirim \n3-)Hicbiri \nSeciniz (1/2/3) : ");
    scanf("%d",&Ogr_18);

    if(Ogr_18 == 1) Fiyat=Fiyat*(0.80);
    else if(Ogr_18 == 2) Fiyat=Fiyat*(0.50);

    printf("\nGuncel Tutar : %.2lf\n",Fiyat);
    printf("-----------------------------------------------\n");

//Gun Secimi
    printf("GUN SECIMI\n\n");
    printf("1-)Pazartesi %%30 Indirim \n2-)Sali \n3-)Carsamba \n4-)Persembe \n5-)Cuma \n6-)Cumartesi \n7-)Pazar \n\nGun seciniz (1/2/3/4/5/6/7) : ");
    scanf("%d",&Gun);

    if(Gun == 1) Fiyat=Fiyat*(0.70);

    printf("\n-----------------------------------------------\n");
    printf("Bilet Fiyatiniz : %.2lf \n\n",Fiyat);
    printf("IYI SEYIRLER DILERIZ...\n\n");
    return 0;
}
