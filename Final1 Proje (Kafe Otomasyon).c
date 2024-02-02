#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

//Stok Islemleri Icın | Kullanici Adi : admin | Sifre : admin123

// Olusturulan Struct Yapilari

typedef struct Secenekler
{
    char isim[20];
    double fiyat;
    int adet;
    int secilen_adet;
} Secenek;

typedef struct Gidalar
{
    char turisim[20];
    int cesit;
    double tutar;
    Secenek *Servis;
} Gida;

typedef struct Masalar
{
    int masa_numara;
    char durum[8];
    double guncel_tutar;
    Gida *Servisler;

} Masa;

// Fonksiyonlarin İmzalari

char MusteriIslemleri (char *Msecim);
char KullaniciGiris (char *Ksecim,char *Kullanici,char *Sifre);
char StokIslemleri (char *Ssecim);
int KapasiteAyari (int *YeniSayi,Masa *MasaMasa);
void AdminBilgiDegisiklik (char *Kullanici,char *Sifre);
void SistemDoldurma (int Baslangic,int MasaSayisi,Masa *MasaOturma,int Cesit,int Mcesit);
void MasalarDurum (int MasaSayisi, Masa *MasaMasa,int Mcesit,int Mturcesit);
void MasaSiparisIslemleri (int MasaSayisi, Masa *MasaMasa, int MenuSayisi, int MenuTur);
void MasaTasima (Masa *MasaMasa, int MasaSayisi);
void HesapKesim (int MasaSayisi, Masa *MasaMasa);
void StokKontrol (Masa *MasaMasa);
void StokEkleme (Masa *MasaMasa,int MasaSayisi);
void YeniUrunEkleme (Masa *MasaMasa,int MasaSayisi);
void UrunSilme (Masa *MasaMasa,int MasaSayisi);

// Fonksiyonlar

char MusteriIslemleri (char *Msecim) //
{

    do
    {
        system("cls");
        printf("\t  ---------------------");
        printf("\n----------| MUSTERI ISLEMLERI |----------\n|\t  ---------------------     \t|\n");
        printf("|\t\t\t\t\t|\n");
        printf("|  1-)Masa Durum Izleme\t\t\t|\n");     //
        printf("|  2-)Masa Siparis Islemleri\t\t|\n");
        printf("|  3-)Masa Hesap Kesimi\t\t\t|\n");
        printf("|  4-)Masa Tasima\t\t\t|\n");
        printf("|  5-)Ana Menu\t\t\t\t|\n");
        printf("|  6-)Otomasyondan Cikis\t\t|\n");
        printf("|\t\t\t\t\t|\n");
        printf("-----------------------------------------\n");
        printf("   SECIM YAPINIZ (1/2/3/4/5) : ");
        scanf(" %c",Msecim);
    }
    while (*Msecim != '1' && *Msecim != '2' && *Msecim != '3' && *Msecim != '4' && *Msecim != '5' && *Msecim != '6');
    return *Msecim;
}

char KullaniciGiris (char *Ksecim,char *Kullanici,char *Sifre) // Tamamlandi
{
    char Kullanici_Deneme[20];
    char Sifre_Deneme[20];
    char kontrol;
    int Deneme_Hakki=3;
    do
    {

        system("cls");
        printf("\t     -------------------");
        printf("\n-------------| KULLANICI GIRIS |------------\n\t     -------------------     \t\n");
        printf("Kullanici girisi yapilmak zorunludur.\nYanlis Giris Hakki : %d\n\n",Deneme_Hakki);
        printf("1-) Giris Yap\n2-) Cikis Yap\n\nSECIN YAPINIZ (1/2) : ");
        scanf(" %s",Ksecim);
    }
    while(*Ksecim!='1' && *Ksecim!='2');

    if(*Ksecim=='1')
    {
        while(1)
        {

            system("cls");
            printf("\t     -------------------");
            printf("\n-------------| KULLANICI GIRIS |------------\n\t     -------------------     \t\n");
            printf("Kullanici : ");
            scanf(" %s",&Kullanici_Deneme);
            printf("Sifre : ");
            scanf(" %s",&Sifre_Deneme);
            Deneme_Hakki--;
            if(strcmp(Kullanici_Deneme, Kullanici) == 0 && strcmp(Sifre_Deneme, Sifre) == 0)
            {
                return '1';
            }
            do
            {
                if(Deneme_Hakki<1)
                {
                    return '0';
                }
                system("cls");
                printf("\t     -------------------");
                printf("\n-------------| KULLANICI GIRIS |------------\n\t     -------------------     \t\n");
                printf("Kullanici Girisi veya Sifre Girisi Hatali...\nKalan Deneme Hakki : %d\n",Deneme_Hakki);
                printf("1-) Tekrar Giris Yap\n2-) Cikis Yap\n\nSECIN YAPINIZ (1/2) : ");
                scanf(" %s",&kontrol);
                if(kontrol=='2')
                {
                    return '2';
                }
            }
            while(kontrol != '1' && kontrol != '2');
        }
    }

}

char StokIslemleri (char *Ssecim) // Tamamlandi
{

    do
    {
        system("cls");
        printf("\t    ------------------");
        printf("\n------------| STOK ISLEMLERI |-----------\n|\t    ------------------     \t|\n");
        printf("|\t\t\t\t\t|\n");
        printf("|  1-)Stok Kontrol\t\t\t|\n");
        printf("|  2-)Stok Ekleme\t\t\t|\n");
        printf("|  3-)Yeni Urun Ekleme\t\t\t|\n");
        printf("|  4-)Urun Silme\t\t\t|\n");
        printf("|  5-)Kapasite Ayarlama\t\t\t|\n");
        printf("|  6-)Admin Bilgi Degistirme\t\t|\n");
        printf("|  7-)Ana Menu\t\t\t\t|\n");
        printf("|  8-)Otomasyondan Cikis\t\t|\n");
        printf("|\t\t\t\t\t|\n");
        printf("-----------------------------------------\n");
        printf("   SECIM YAPINIZ (1/2/3/4/5/6/7) : ");
        scanf(" %c",Ssecim);
    }
    while(*Ssecim!='1' && *Ssecim!='2' && *Ssecim!='3' && *Ssecim!='4' && *Ssecim!='5' && *Ssecim!='6' && *Ssecim!='7' && *Ssecim!='8');
    return *Ssecim;
}

int KapasiteAyari (int *YeniSayi, Masa* MasaMasa) // Tamamlandi
{
    do
    {
        system("cls");
        printf("\t     ------------------");
        printf("\n-------------| KAPASITE AYARI |------------\n\t     ------------------     \t\n");
        printf("\nGeri gelmek icin '0' yaziniz.\n\nYeni Kapasiteyi Giriniz : ");

        while (scanf("%d", &YeniSayi) != 1 || YeniSayi < 0)
        {
            system("cls");
            printf("\t     ------------------");
            printf("\n-------------| KAPASITE AYARI |------------\n\t     ------------------     \t\n");
            printf("\nLutfen Gecerli Bir Sayi Giriniz : ");
            (scanf(" %d", &YeniSayi) != 1);
        }
    }
    while (YeniSayi < 0);
    return YeniSayi;
}

void AdminBilgiDegisiklik (char *Kullanici,char *Sifre) // Tamamlandi
{

    char kontrol,kontrol2,kontrol3;
    char Yeni_Kullanici[20];
    char Yeni_Sifre[20];
    int kullanici_sayi,sifre_sayi;


    do
    {

        system("cls");
        printf("\t     --------------------");
        printf("\n-------------| ADMIN DEGISIKLIK |------------\n\t     --------------------     \t\n\n");
        printf("Yeni kullanici ismi : ");
        scanf("%s",&Yeni_Kullanici);
        printf("Yeni sifre : ");
        scanf("%s",&Yeni_Sifre);
        kullanici_sayi=printf("%s",Yeni_Kullanici);
        sifre_sayi=printf("%s",Yeni_Sifre);
        do
        {
            system("cls");
            printf("\t     --------------------");
            printf("\n-------------| ADMIN DEGISIKLIK |------------\n\t     --------------------     \t\n\n");
            printf("Yazilan yeni kullanici ismi : %s\t| %d Karakter Girildi.\n",Yeni_Kullanici,kullanici_sayi);
            printf("Yaziln yeni sifre : %s\t\t| %d Karakter Girildi.\n\n",Yeni_Sifre,sifre_sayi);
            printf("Onayliyor musunuz ? (E/H) : ");
            scanf(" %c",&kontrol);
        }
        while(toupper(kontrol) != 'E' && toupper(kontrol) != 'H');


        if(toupper(kontrol)=='E')
        {
            strcpy(Kullanici,Yeni_Kullanici);
            strcpy(Sifre,Yeni_Sifre);
            return 0;
        }
        kontrol='0';
        do
        {
            system("cls");
            printf("\t     ----------------");
            printf("\n-------------| ADMIN DEGISIKLIK |------------\n\t     --------------------     \t\n\n");
            printf("Ana menuye donmek ister misiniz ? (E/H) : ");
            scanf("%c",&kontrol2);
        }
        while(toupper(kontrol2) != 'E' && toupper(kontrol2) != 'H');

        if(toupper(kontrol2)=='E')
        {

            return 0;
        }

        kontrol2='0';


    }
    while(toupper(kontrol) != 'E' && toupper(kontrol) != 'H');

}

void SistemDoldurma (int Baslangic,int MasaSayisi,Masa *MasaOturma,int Cesit,int Mcesit) // Demo olarak bilgi girisi
{
    // MASALARA DEMO OLARAK MENULER EKLENDI

    int i,j,k;

    for(i=Baslangic; i<MasaSayisi; i++)
    {
        (MasaOturma+i)->Servisler=malloc(sizeof(Gida)*3);
        strcpy((MasaOturma+i)->durum,"BOS");
        (MasaOturma+i)->guncel_tutar=0;
        (MasaOturma+i)->masa_numara=i+1;

        // MENU CESITLERI GIRILDI

        strcpy((MasaOturma+i)->Servisler->turisim,"YEMEKLER");
        (MasaOturma+i)->Servisler->tutar=0;
        strcpy(((MasaOturma+i)->Servisler+1)->turisim,"ICECEKLER");
        ((MasaOturma+i)->Servisler+1)->tutar=0;
        strcpy(((MasaOturma+i)->Servisler+2)->turisim,"TATLILAR");
        ((MasaOturma+i)->Servisler+2)->tutar=0;

        for(j=0; j<3; j++)
        {
            ((MasaOturma+i)->Servisler+j)->cesit=6;
            ((MasaOturma+i)->Servisler+j)->Servis = calloc(((MasaOturma+i)->Servisler->cesit),sizeof(Secenek));
        }

        /////////// YEMEK ///////////

        strcpy(((MasaOturma+i)->Servisler)->Servis->isim,"Tavuklu-Makarna");
        (MasaOturma+i)->Servisler->Servis->fiyat=45.50;
        (MasaOturma+i)->Servisler->Servis->adet=50;
        (MasaOturma+i)->Servisler->Servis->secilen_adet=0;

        strcpy((((MasaOturma+i)->Servisler)->Servis+1)->isim,"Korili-Makarna");
        (((MasaOturma+i)->Servisler)->Servis+1)->fiyat=37.50;
        (((MasaOturma+i)->Servisler)->Servis+1)->adet=50;
        (((MasaOturma+i)->Servisler)->Servis+1)->secilen_adet=0;

        strcpy((((MasaOturma+i)->Servisler)->Servis+2)->isim,"Servis-Kofte");
        (((MasaOturma+i)->Servisler)->Servis+2)->fiyat=95.75;
        (((MasaOturma+i)->Servisler)->Servis+2)->adet=30;
        (((MasaOturma+i)->Servisler)->Servis+2)->secilen_adet=0;

        strcpy((((MasaOturma+i)->Servisler)->Servis+3)->isim,"Tavuk-Sote");
        (((MasaOturma+i)->Servisler)->Servis+3)->fiyat=105.50;
        (((MasaOturma+i)->Servisler)->Servis+3)->adet=15;
        (((MasaOturma+i)->Servisler)->Servis+3)->secilen_adet=0;

        strcpy((((MasaOturma+i)->Servisler)->Servis+4)->isim,"Tavuk-Doner");
        (((MasaOturma+i)->Servisler)->Servis+4)->fiyat=50.75;
        (((MasaOturma+i)->Servisler)->Servis+4)->adet=10;
        (((MasaOturma+i)->Servisler)->Servis+4)->secilen_adet=0;

        strcpy((((MasaOturma+i)->Servisler)->Servis+5)->isim,"Et-Doner");
        (((MasaOturma+i)->Servisler)->Servis+5)->fiyat=98.75;
        (((MasaOturma+i)->Servisler)->Servis+5)->adet=10;
        (((MasaOturma+i)->Servisler)->Servis+5)->secilen_adet=0;

        /////////// ICECEK ///////////

        strcpy(((MasaOturma+i)->Servisler+1)->Servis->isim,"Cay");
        ((MasaOturma+i)->Servisler+1)->Servis->fiyat=15.00;
        ((MasaOturma+i)->Servisler+1)->Servis->adet=20;
        (((MasaOturma+i)->Servisler+1)->Servis)->secilen_adet=0;

        strcpy((((MasaOturma+i)->Servisler+1)->Servis+1)->isim,"Kahve");
        (((MasaOturma+i)->Servisler+1)->Servis+1)->fiyat=45.25;
        (((MasaOturma+i)->Servisler+1)->Servis+1)->adet=20;
        (((MasaOturma+i)->Servisler+1)->Servis+1)->secilen_adet=0;

        strcpy((((MasaOturma+i)->Servisler+1)->Servis+2)->isim,"Limonata");
        (((MasaOturma+i)->Servisler+1)->Servis+2)->fiyat=22.50;
        (((MasaOturma+i)->Servisler+1)->Servis+2)->adet=25;
        (((MasaOturma+i)->Servisler+1)->Servis+2)->secilen_adet=0;

        strcpy((((MasaOturma+i)->Servisler+1)->Servis+3)->isim,"Coca-Cola");
        (((MasaOturma+i)->Servisler+1)->Servis+3)->fiyat=35.25;
        (((MasaOturma+i)->Servisler+1)->Servis+3)->adet=15;
        (((MasaOturma+i)->Servisler+1)->Servis+3)->secilen_adet=0;

        strcpy((((MasaOturma+i)->Servisler+1)->Servis+4)->isim,"Sprite");
        (((MasaOturma+i)->Servisler+1)->Servis+4)->fiyat=32.50;
        (((MasaOturma+i)->Servisler+1)->Servis+4)->adet=10;
        (((MasaOturma+i)->Servisler+1)->Servis+4)->secilen_adet=0;

        strcpy((((MasaOturma+i)->Servisler+1)->Servis+5)->isim,"Fanta");
        (((MasaOturma+i)->Servisler+1)->Servis+5)->fiyat=28.75;
        (((MasaOturma+i)->Servisler+1)->Servis+5)->adet=10;
        (((MasaOturma+i)->Servisler+1)->Servis+5)->secilen_adet=0;


        /////////// TATLI ///////////

        strcpy((((MasaOturma+i)->Servisler+2)->Servis)->isim,"Sutlac Tatlisi");
        ((MasaOturma+i)->Servisler+2)->Servis->fiyat=48.50;
        ((MasaOturma+i)->Servisler+2)->Servis->adet=20;
        ((MasaOturma+i)->Servisler+2)->Servis->secilen_adet=0;

        strcpy((((MasaOturma+i)->Servisler+2)->Servis+1)->isim,"Kazandibi Tatlisi");
        (((MasaOturma+i)->Servisler+2)->Servis+1)->fiyat=45.00;
        (((MasaOturma+i)->Servisler+2)->Servis+1)->adet=20;
        (((MasaOturma+i)->Servisler+2)->Servis+1)->secilen_adet=0;

        strcpy((((MasaOturma+i)->Servisler+2)->Servis+2)->isim,"Revani Tatlisi");
        (((MasaOturma+i)->Servisler+2)->Servis+2)->fiyat=35.25;
        (((MasaOturma+i)->Servisler+2)->Servis+2)->adet=10;
        (((MasaOturma+i)->Servisler+2)->Servis+2)->secilen_adet=0;

        strcpy((((MasaOturma+i)->Servisler+2)->Servis+3)->isim,"Profiterol Tatlisi");
        (((MasaOturma+i)->Servisler+2)->Servis+3)->fiyat=50.75;
        (((MasaOturma+i)->Servisler+2)->Servis+3)->adet=10;
        (((MasaOturma+i)->Servisler+2)->Servis+3)->secilen_adet=0;

        strcpy((((MasaOturma+i)->Servisler+2)->Servis+4)->isim,"Baklava Tatlisi");
        (((MasaOturma+i)->Servisler+2)->Servis+4)->fiyat=55.50;
        (((MasaOturma+i)->Servisler+2)->Servis+4)->adet=10;
        (((MasaOturma+i)->Servisler+2)->Servis+4)->secilen_adet=0;

        strcpy((((MasaOturma+i)->Servisler+2)->Servis+5)->isim,"Gullac Tatlisi");
        (((MasaOturma+i)->Servisler+2)->Servis+5)->fiyat=49.50;
        (((MasaOturma+i)->Servisler+2)->Servis+5)->adet=40;
        (((MasaOturma+i)->Servisler+2)->Servis+5)->secilen_adet=0;

    }
}

void MasalarDurum (int MasaSayisi, Masa *MasaMasa,int Mcesit,int Mturcesit) // Tamamlandi
{
    char donus_kontrol;
    do
    {
        int kontrol,i,j;

        do
        {
            system("cls");
            int i,j;
            for(i=0; i<MasaSayisi; i+=2)
            {
                if(i==MasaSayisi-1 && i%2==0)
                {
                    printf("\n-----------| MASA-%d |-----------\n",(MasaMasa+MasaSayisi-1)->masa_numara);
                    printf("|\t\t\t\t|\n");
                    printf("| Durum : %s \t\t\t|\n",(MasaMasa+MasaSayisi+1)->durum);
                    for(j=0; j<Mcesit; j++)
                    {
                        printf("| %s : %.2lf \t\t|\n",((MasaMasa+MasaSayisi-1)->Servisler+j)->turisim,((MasaMasa+MasaSayisi-1)->Servisler+j)->tutar);
                    }
                    printf("---------------------------------\n\n\n");
                    break;
                }
                printf("\n-----------| MASA-%d |-----------\t\t\t-----------| MASA-%d |-----------\n",(MasaMasa+i)->masa_numara,(MasaMasa+i+1)->masa_numara);
                printf("|\t\t\t\t|\t\t\t|\t\t\t\t|\n");
                printf("| Durum : %s \t\t\t|\t\t\t| Durum : %s \t\t\t|\n",(MasaMasa+i)->durum,(MasaMasa+(i+1))->durum);
                for(j=0; j<Mcesit; j++)
                {
                    printf("| %s : %.2lf \t\t|\t\t\t| %s : %.2lf \t\t|\n",((MasaMasa+i)->Servisler+j)->turisim,((MasaMasa+i)->Servisler+j)->tutar,((MasaMasa+i+1)->Servisler+j)->turisim,((MasaMasa+i+1)->Servisler+j)->tutar);
                }
                printf("---------------------------------\t\t\t---------------------------------\n\n\n");

            }



            printf("Detayli Bakmak Istediginiz Masa Numarasini Girebilirsiniz. \nCikis icin 0 Yaziniz.\n\n Giriniz : ");
            scanf("%d",&kontrol);
        }
        while(kontrol>MasaSayisi || kontrol<0);

        if(kontrol==0)
        {
            return 0;
        }
        system("cls");
        printf("\n---------------------------| MASA-%d |---------------------------\n\n",(MasaMasa+kontrol-1)->masa_numara);
        printf(" Durum : %s\n Guncel Hesap : %.2lf\n",(MasaMasa+kontrol-1)->durum,(MasaMasa+kontrol-1)->guncel_tutar);
        for(i=0; i<Mcesit; i++)
        {

            if(((MasaMasa+kontrol-1)->Servisler+i)->tutar == 0)
            {
                continue;
            }
            printf("\n\n Secilen Adet     Birim Fiyati\t           %s\n--------------   --------------     -------------------------\n",(MasaMasa->Servisler+i)->turisim);
            for(j=0; j<MasaMasa->Servisler->cesit; j++)
            {
                if((((MasaMasa+kontrol-1)->Servisler+i)->Servis+j)->secilen_adet==0)
                {
                    continue;
                }
                printf("      %d\t\t     %.2lf  \t\t%s\n",(((MasaMasa+kontrol-1)->Servisler+i)->Servis+j)->secilen_adet,(((MasaMasa+kontrol-1)->Servisler+i)->Servis+j)->fiyat,(((MasaMasa+kontrol-1)->Servisler+i)->Servis+j)->isim);
            }
        }
        printf("\n\nBaska bir masaya bakmak ister misiniz ? (E/H) : ");
        scanf(" %s",&donus_kontrol);
        if(toupper(donus_kontrol)=='H')
        {
            return 0;
        }

    }
    while(toupper(donus_kontrol)!='E' || toupper(donus_kontrol)!='H');
}

void MasaSiparisIslemleri (int MasaSayisi, Masa *MasaMasa, int MenuSayisi, int MenuTur) // Tamamlandi
{

    int i,j,k;
    int MenuSecim,secilen_masa,adet_secim;
    char Islem_Secim;

    do
    {
        system("cls");
        printf("\t     ---------------------");
        printf("\n-------------| SIPARIS ISLEMLERI |------------\n\t     ---------------------     \t\n\n");
        for(i=0; i<MasaSayisi; i+=2)
        {
            printf("Masa-%d\t: %s \t\tMasa-%d\t: %s\n",(MasaMasa+i)->masa_numara,(MasaMasa+i)->durum,(MasaMasa+i+1)->masa_numara,(MasaMasa+i+1)->durum);
        }
        printf("\n\nGeri gitmek icin '0' Yaziniz.\n\nMasa Seciniz : ");
        scanf("%d",&secilen_masa);
        if(secilen_masa==0)
        {
            return 0;
        }
    }
    while(secilen_masa>=MasaSayisi+1 || secilen_masa<=0);

    do
    {
        system("cls");
        printf("\t     ---------------------");
        printf("\n-------------| SIPARIS ISLEMLERI |------------\n\t     ---------------------     \t\n\n");
        printf("  1-) Siparis Ekleme\n  2-) Siparis Silme\n  3-) Menuden Cikis\n\n  SECINIZ : ");
        scanf("%c",&Islem_Secim);
        if(Islem_Secim== '3')
        {
            return 0;
        }
    }
    while(Islem_Secim!='1' && Islem_Secim!='2' && Islem_Secim!='3');

    switch(Islem_Secim)
    {
    case '1':
    {
        for(i=0; i<MenuSayisi; i++)
        {

            system("cls");
            printf("\n-------------|  %s  |------------\n\t\t\n\n",((MasaMasa+secilen_masa-1)->Servisler+i)->turisim);
            for(j=0; j<((MasaMasa+secilen_masa-1)->Servisler+i)->cesit; j++)
            {
                printf("%d-) %.2lf TL\t==  %s\n",j+1,(((MasaMasa+secilen_masa-1)->Servisler+i)->Servis+j)->fiyat,(((MasaMasa+secilen_masa-1)->Servisler+i)->Servis+j)->isim);
            }
            printf("%d-)     0 TL\t==  Hicbiri",(((MasaMasa+secilen_masa-1)->Servisler+i)->cesit)+1);
            do
            {
                printf("\n\n Seciniz : ");
                scanf("%d",&MenuSecim);
            }
            while(MenuSecim<=0);
            if(MenuSecim == (((MasaMasa+secilen_masa-1)->Servisler+i)->cesit)+1)
            {
                continue;
            }
            if(MenuSecim>(((MasaMasa+secilen_masa-1)->Servisler+i)->cesit)+1)
            {
                i--;
                continue;
            }
            else if(MenuSecim==(((MasaMasa+secilen_masa-1)->Servisler+i)->cesit)+1)
            {
                continue;
            }
            printf("\nStogumuz '%d' | Adet Seciniz : ",(((MasaMasa+secilen_masa-1)->Servisler+i)->Servis+MenuSecim-1)->adet);
            scanf("%d",&adet_secim);
            while(adet_secim > (((MasaMasa+secilen_masa-1)->Servisler+i)->Servis+MenuSecim-1)->adet)
            {
                printf("\n Maalesef stogumuz '%d' kadardir.\n Stoga gore talep ederseniz seviniriz : ",(((MasaMasa+secilen_masa-1)->Servisler+i)->Servis+MenuSecim-1)->adet);
                scanf("%d",&adet_secim);
            }
            (((MasaMasa+secilen_masa-1)->Servisler+i)->Servis+MenuSecim-1)->adet+=1;
            (((MasaMasa+secilen_masa-1)->Servisler+i)->Servis+MenuSecim-1)->secilen_adet +=adet_secim;
            ((MasaMasa+secilen_masa-1)->Servisler+i)->tutar += ((((MasaMasa+secilen_masa-1)->Servisler+i)->Servis+MenuSecim-1)->fiyat) * (double)adet_secim;
            (MasaMasa+secilen_masa-1)->guncel_tutar += ((MasaMasa+secilen_masa-1)->Servisler+i)->tutar ;
            strcpy((MasaMasa+secilen_masa-1)->durum,"DOLU");
            for(j=0; j<MasaSayisi; j++)
            {
                for(k=0; k<MenuSayisi; k++)
                {
                    (((MasaMasa+j)->Servisler+k)->Servis+MenuSecim-1)->adet -= adet_secim;
                }
            }


        }
        break;
    }
    case '2':
    {
        if((MasaMasa+secilen_masa-1)->guncel_tutar <= 0)
        {
            break;
        }
        int silme_secim,silme_adet;
        system("cls");
        printf("\t\t\t      ----------");
        printf("\n------------------------------| Masa-%d |-----------------------------\n\t\t\t      ----------     \t\n\n",secilen_masa);
        printf(" Hesap : %.2lf\n",(MasaMasa+secilen_masa-1)->guncel_tutar);
        for(i=0; i<3; i++)
        {
            if(((MasaMasa+secilen_masa-1)->Servisler+i)->tutar == 0)
            {
                continue;
            }

            printf("\n\n\t Secilen Adet     Birim Fiyati\t           %s\n\t--------------   --------------     -------------------------\n",(MasaMasa->Servisler+i)->turisim);

            for(j=0; j<MasaMasa->Servisler->cesit; j++)
            {
                if((((MasaMasa+secilen_masa-1)->Servisler+i)->Servis+j)->secilen_adet==0)
                {
                    continue;
                }
                printf("%d---->\t     %d\t\t     %.2lf  \t\t%s\n",j+1,((MasaMasa->Servisler+i)->Servis+j)->secilen_adet,((MasaMasa->Servisler+i)->Servis+j)->fiyat,((MasaMasa->Servisler+i)->Servis+j)->isim);
            }

            printf("\n Islem yapacagin urun bu listede degil ise '0' yaziniz.\n Islem yapmak istedigin urunun numarasini yaziniz : ");
            scanf("%d",&silme_secim);

            if(silme_secim == 0)
            {
                continue;
            }
            printf("\n Silmek istedigin urun adeti giriniz : ");
            scanf("%d",&silme_adet);
            if(silme_adet >= (((MasaMasa+secilen_masa-1)->Servisler+i)->Servis+silme_secim-1)->secilen_adet)
            {
                silme_adet == (((MasaMasa+secilen_masa-1)->Servisler+i)->Servis+silme_secim-1)->secilen_adet;
            }
            (((MasaMasa+secilen_masa-1)->Servisler+i)->Servis+silme_secim-1)->secilen_adet -= silme_adet;
            ((MasaMasa+secilen_masa-1)->Servisler+i)->tutar -= (((MasaMasa+secilen_masa-1)->Servisler+i)->Servis+silme_secim-1)->fiyat * (double)silme_adet ;
            (MasaMasa+secilen_masa-1)->guncel_tutar -= (((MasaMasa+secilen_masa-1)->Servisler+i)->Servis+silme_secim-1)->fiyat * (double)silme_adet;
            if((MasaMasa+secilen_masa-1)->guncel_tutar == 0)
            {
                strcpy((MasaMasa+secilen_masa-1)->durum,"BOS");
            }
        }
    }
    }
}

void MasaTasima (Masa *MasaMasa,int MasaSayisi) // Tamamlandi
{
    double tutucu_guncel_tutar,tutucu_tutar;
    char tutucu_durum[8];
    int tutucu_adet;


    int i,j,secilen_masa,gidilen_masa;
    do
    {
        system("cls");
        printf("\t     ------------------");
        printf("\n-------------| MASA ISLEMLERI |------------\n\t     ------------------     \t\n\n");
        for(i=0; i<MasaSayisi; i+=2)
        {
            printf("Masa-%d\t: %s \t\tMasa-%d\t: %s\n",(MasaMasa+i)->masa_numara,(MasaMasa+i)->durum,(MasaMasa+i+1)->masa_numara,(MasaMasa+i+1)->durum);
        }
        printf("\n\nGeri gitmek icin '0' Yaziniz.\n\nTasimak istediginiz masayi seciniz : ");
        scanf("%d",&secilen_masa);
        if(secilen_masa==0)
        {
            return 0;
        }
    }
    while(secilen_masa>=MasaSayisi+1 || secilen_masa<=0);

    do
    {
        system("cls");
        printf("\t     ------------------");
        printf("\n-------------| MASA ISLEMLERI |------------\n\t     ------------------     \t\n\n");
        for(i=0; i<MasaSayisi; i+=2)
        {
            printf("Masa-%d\t: %s \t\tMasa-%d\t: %s\n",(MasaMasa+i)->masa_numara,(MasaMasa+i)->durum,(MasaMasa+i+1)->masa_numara,(MasaMasa+i+1)->durum);
        }

        printf("\n\nGeri gitmek icin '0' Yaziniz.\n\nNereye tasimak istediginizi yaziniz : ");
        scanf("%d",&gidilen_masa);

        if(gidilen_masa==0)
        {
            return 0;
        }
    }
    while(secilen_masa>=MasaSayisi+1 || secilen_masa<=0);

    tutucu_guncel_tutar = (MasaMasa+gidilen_masa-1)->guncel_tutar;
    (MasaMasa+gidilen_masa-1)->guncel_tutar = (MasaMasa+secilen_masa-1)->guncel_tutar;
    (MasaMasa+secilen_masa-1)->guncel_tutar = tutucu_guncel_tutar;

    strcpy(tutucu_durum,(MasaMasa+gidilen_masa-1)->durum);
    strcpy((MasaMasa+gidilen_masa-1)->durum,(MasaMasa+secilen_masa-1)->durum);
    strcpy((MasaMasa+secilen_masa-1)->durum,tutucu_durum);

    for(i=0; i<3; i++)
    {
        tutucu_tutar = ((MasaMasa+gidilen_masa-1)->Servisler+i)->tutar;
        ((MasaMasa+gidilen_masa-1)->Servisler+i)->tutar = ((MasaMasa+secilen_masa-1)->Servisler+i)->tutar;
        ((MasaMasa+secilen_masa-1)->Servisler+i)->tutar = tutucu_tutar;

        for(j=0; j<((MasaMasa+secilen_masa-1)->Servisler+i)->cesit; j++)
        {
            if((((MasaMasa+secilen_masa-1)->Servisler+i)->Servis+j)->secilen_adet = 0)
            {
                continue;
            }
            tutucu_adet = (((MasaMasa+gidilen_masa-1)->Servisler+i)->Servis+j)->secilen_adet;
            (((MasaMasa+gidilen_masa-1)->Servisler+i)->Servis+j)->secilen_adet = (((MasaMasa+secilen_masa-1)->Servisler+i)->Servis+j)->secilen_adet;
            (((MasaMasa+secilen_masa-1)->Servisler+i)->Servis+j)->secilen_adet = tutucu_adet;
        }

    }
}

void HesapKesim (int MasaSayisi, Masa *MasaMasa)  // Tamamlandi
{
    int i,j,secilen_masa;
    system("cls");
    printf("\t     ----------------");
    printf("\n-------------| MASA KAPATMA |------------\n\t     ----------------     \t\n\n");
    for(i=0; i<MasaSayisi; i++)
    {
        printf("Masa-%d\t: %s\tHesap : %.2lf TL\n",i+1,(MasaMasa+i)->durum,(MasaMasa+i)->guncel_tutar);
    }
    printf("\nGeri Gitmek icin '0' Yaziniz.\n\nMasa Seciniz : ");
    scanf("%d",&secilen_masa);
    while(secilen_masa>MasaSayisi || secilen_masa<=0)
    {
        if(secilen_masa==0)
        {
            return 0;
        }
        printf("\nLutfen Gecerli Bir Masa Giriniz : ");
        scanf("%d",&secilen_masa);
    }
    strcpy((MasaMasa+secilen_masa-1)->durum,"BOS");
    (MasaMasa+secilen_masa-1)->guncel_tutar = 0;
    for(i=0; i<3; i++)
    {
        ((MasaMasa+secilen_masa-1)->Servisler+i)->tutar = 0;
        for(j=0; j<((MasaMasa+secilen_masa-1)->Servisler+i)->cesit; j++)
        {
            (((MasaMasa+secilen_masa-1)->Servisler+i)->Servis+j)->secilen_adet = 0;
        }
    }
}

void StokKontrol (Masa *MasaMasa) // Tamamlandi
{
    int i,j;
    system("cls");
    printf("\t     ------------------");
    printf("\n-------------| STOK ISLEMLERI |------------\n\t     ------------------     \t");
    for(i=0; i<3; i++)
    {
        printf("\n\n\t Stok Adet     Birim Fiyati\t           %s\n\t-----------   --------------   \t   -------------------------\n",(MasaMasa->Servisler+i)->turisim);

        for(j=0; j<(MasaMasa->Servisler+i)->cesit; j++)
        {
            printf("\t     %d\t\t  %.2lf    \t\t%s\n",((MasaMasa->Servisler+i)->Servis+j)->adet,((MasaMasa->Servisler+i)->Servis+j)->fiyat,((MasaMasa->Servisler+i)->Servis+j)->isim);
        }
    }
    printf("\nCikis icin bir sayi yaziniz : ");
    scanf("%d");
}

void StokEkleme (Masa *MasaMasa,int MasaSayisi) // Tamamlandi
{
    int i,j,k,stok_secim,eklenecek_miktar;
    for(i=0; i<3; i++)
    {
        system("cls");
        printf("\t     ------------------");
        printf("\n-------------| STOK ISLEMLERI |------------\n\t     ------------------     \t");
        printf("\n\n\t Stok Adet     Birim Fiyati\t           %s\n\t-----------   --------------   \t   -------------------------\n",(MasaMasa->Servisler+i)->turisim);

        for(j=0; j<MasaMasa->Servisler->cesit; j++)
        {
            printf("%d---->\t     %d\t\t  %.2lf    \t\t%s\n",j+1,((MasaMasa->Servisler+i)->Servis+j)->adet,((MasaMasa->Servisler+i)->Servis+j)->fiyat,((MasaMasa->Servisler+i)->Servis+j)->isim);
        }
        printf("\nIstediginiz stok urunu burda degilse '0' yazip sonraki stoga gecebilirsiniz.\n\nSeciniz : ");
        scanf("%d",&stok_secim);
        if(stok_secim == 0)
        {
            continue;
        }
        while(stok_secim > (MasaMasa->Servisler+i)->cesit || stok_secim < 0)
        {
            printf("Lutfen gecerli deger giriniz : ");
            scanf("%d",stok_secim);
        }
        printf("Stoga eklemek istediginiz miktari giriniz : ");
        scanf("%d",&eklenecek_miktar);
        for(k=0; k<MasaSayisi; k++)
        {
            (((MasaMasa+k)->Servisler+i)->Servis+stok_secim-1)->adet += eklenecek_miktar;
        }

    }
}

void YeniUrunEkleme (Masa *MasaMasa,int MasaSayisi) // Tamamlandi
{
    int tur_secim,yeni_tur_isim[15],yeni_tur_adet,i,j;
    double yeni_tur_fiyat;
    do
    {
        system("cls");
        printf("\t     ------------------");
        printf("\n-------------| STOK ISLEMLERI |------------\n\t     ------------------     \t");
        printf("\n\n1-) %s\n2-) %s\n3-) %s\n4-) Menuden cikis\n\nSECINIZ : ",MasaMasa->Servisler->turisim,(MasaMasa->Servisler+1)->turisim,(MasaMasa->Servisler+2)->turisim);
        scanf("%d",&tur_secim);
    }
    while(tur_secim<=0 || tur_secim >4);
    if(tur_secim==4)
    {
        return 0;
    }
    system("cls");
    printf("\t     ------------------");
    printf("\n-------------| STOK ISLEMLERI |------------\n\t     ------------------     \t");
    printf("\n\nYeni urun ismini giriniz : ");
    scanf("%s",&yeni_tur_isim);
    printf("Yeni urun fiyatini giriniz : ");
    scanf("%lf",&yeni_tur_fiyat);
    printf("Yeni urun stok adetini giriniz : ");
    scanf("%d",&yeni_tur_adet);

    int cesit = ((MasaMasa+i)->Servisler+tur_secim-1)->cesit;
    for(i=0; i<MasaSayisi; i++)
    {
        ((MasaMasa+i)->Servisler+tur_secim-1)->cesit += 1;
        ((MasaMasa+i)->Servisler+tur_secim-1)->Servis = realloc(((MasaMasa+i)->Servisler+tur_secim-1)->Servis,sizeof(Secenek)*((MasaMasa+i)->Servisler+tur_secim-1)->cesit);
        strcpy((((MasaMasa+i)->Servisler+tur_secim-1)->Servis+cesit)->isim,yeni_tur_isim);
        (((MasaMasa+i)->Servisler+tur_secim-1)->Servis+cesit)->fiyat = yeni_tur_fiyat;
        (((MasaMasa+i)->Servisler+tur_secim-1)->Servis+cesit)->adet = yeni_tur_adet;
        (((MasaMasa+i)->Servisler+tur_secim-1)->Servis+cesit)->secilen_adet = 0;
    }
}

void UrunSilme (Masa *MasaMasa,int MasaSayisi) // Tamamlandi
{
    int tur_secim,i,urun_secim,Mcesit;
    do
    {
        system("cls");
        printf("\t     ------------------");
        printf("\n-------------| STOK ISLEMLERI |------------\n\t     ------------------     \t");
        printf("\n\n1-) %s\n2-) %s\n3-) %s\n4-) Menuden cikis\n\nSECINIZ : ",MasaMasa->Servisler->turisim,(MasaMasa->Servisler+1)->turisim,(MasaMasa->Servisler+2)->turisim);
        scanf("%d",&tur_secim);
    }
    while(tur_secim<=0 || tur_secim >4);

    Mcesit = (MasaMasa->Servisler+tur_secim-1)->cesit;
    Mcesit--;

    do
    {
        system("cls");
        printf("\t     ------------------");
        printf("\n-------------| STOK ISLEMLERI |------------\n\t     ------------------     \t");
        printf("\n\n\t Stok Adet     Birim Fiyati\t           %s\n\t-----------   --------------   \t   -------------------------\n",(MasaMasa->Servisler+tur_secim-1)->turisim);
        for(i=0; i<(MasaMasa->Servisler+tur_secim-1)->cesit; i++)
        {
            printf("%d---->\t     %d\t\t  %.2lf    \t\t%s\n",i+1,((MasaMasa->Servisler+tur_secim-1)->Servis+i)->adet,((MasaMasa->Servisler+tur_secim-1)->Servis+i)->fiyat,((MasaMasa->Servisler+tur_secim-1)->Servis+i)->isim);
        }
        printf("\nGeri donmek icin '0' yaziniz.\n\nSilmek istediginiz urun kodunu yaziniz : ");
        scanf("%d",&urun_secim);
        if(urun_secim==0)
        {
            return 0;
        }
    }
    while(urun_secim<0 || urun_secim > (MasaMasa->Servisler+tur_secim-1)->cesit);

    if(urun_secim==(MasaMasa->Servisler+tur_secim-1)->cesit)
    {
        for(i=0; i<MasaSayisi; i++)
        {
            ((MasaMasa+i)->Servisler+tur_secim-1)->cesit--;
            ((MasaMasa+i)->Servisler+tur_secim-1)->Servis = realloc(((MasaMasa+i)->Servisler+tur_secim-1)->Servis,sizeof(Secenek)*((MasaMasa+i)->Servisler+tur_secim-1)->cesit);
        }
    }
    else
    {
        for(i=0; i<MasaSayisi; i++)
        {
            strcpy((((MasaMasa+i)->Servisler+tur_secim-1)->Servis+urun_secim-1)->isim,(((MasaMasa+i)->Servisler+tur_secim-1)->Servis+Mcesit)->isim);
            (((MasaMasa+i)->Servisler+tur_secim-1)->Servis+urun_secim-1)->fiyat =  (((MasaMasa+i)->Servisler+tur_secim-1)->Servis+Mcesit)->fiyat;
            (((MasaMasa+i)->Servisler+tur_secim-1)->Servis+urun_secim-1)->adet =  (((MasaMasa+i)->Servisler+tur_secim-1)->Servis+Mcesit)->adet;
            (((MasaMasa+i)->Servisler+tur_secim-1)->Servis+urun_secim-1)->secilen_adet =  (((MasaMasa+i)->Servisler+tur_secim-1)->Servis+Mcesit)->secilen_adet;
            ((MasaMasa+i)->Servisler+tur_secim-1)->cesit--;
            ((MasaMasa+i)->Servisler+tur_secim-1)->Servis = realloc(((MasaMasa+i)->Servisler+tur_secim-1)->Servis,sizeof(Secenek)*((MasaMasa+i)->Servisler+tur_secim-1)->cesit);
        }
    }
}

int main()
{
    Masa *Oturma;

    char Ana_Menu_Secim;

    char Musteri_Islemleri_Secim,Stok_Islemleri_Secim;
    char *pMusteri_Islemleri_Secim,*pStok_Islemleri_Secim;
    char Kullanici_Giris_Secim,*pKullanici_Giris_Secim;
    char KullaniciAdi[]= "admin";
    char KullaniciSifre[]= "admin123";
    char *pKullaniciAdi,*pKullaniciSifre;
    // Pointer ile islem yapilmasi icin ilk tanımlamalar
    int Masa_Sayisi=12,*pMasa_Sayisi;
    int Menu_Cesidi=3,*pMenu_Cesidi;
    int Menutur_Cesit=6,*pMenutur_Cesit;
    int Yeni_Masa_Sayisi,*pYeni_Masa_Sayisi;

    pMasa_Sayisi=&Masa_Sayisi;
    pMenutur_Cesit=&Menutur_Cesit;
    pMenu_Cesidi=&Menu_Cesidi;
    pYeni_Masa_Sayisi=&Yeni_Masa_Sayisi;
    // Adres atamaları
    pMusteri_Islemleri_Secim=&Musteri_Islemleri_Secim;
    pStok_Islemleri_Secim=&Stok_Islemleri_Secim;
    pKullanici_Giris_Secim=&Kullanici_Giris_Secim;
    pKullaniciAdi=&KullaniciAdi;
    pKullaniciSifre=&KullaniciSifre;

    Oturma = malloc(sizeof(Masa)*Masa_Sayisi);      // Baslangic icin demo olarak masa sayisi belirleme

    SistemDoldurma(0,Masa_Sayisi,Oturma,Menu_Cesidi,Menutur_Cesit);     // Demo olarak sistemi doldurma yoksa tek tek ugrasilmaz

    while(1)
    {
        do
        {
            system("cls");
            printf("\t     ----------------");
            printf("\n-------------| BEKOFASTFOOD |------------\n|\t     ----------------     \t|\n");
            printf("|\t     KAPASITE %d MASA\t\t|\n",*pMasa_Sayisi);
            printf("|\t\t\t\t\t|\n");                                                                       // Ana Menu (Sadece bu menu main icinde)
            printf("|  1-)Musteri Islemleri\t\t\t|\n");
            printf("|  2-)Stok Islemleri\t\t\t|\n");
            printf("|  3-)Otomasyondan Cikis\t\t|\n");
            printf("|\t\t\t\t\t|\n-----------------------------------------\n");
            printf("   SECIM YAPINIZ (1/2/3) : ");
            scanf(" %c",&Ana_Menu_Secim);
        }
        while(Ana_Menu_Secim != '1' && Ana_Menu_Secim != '2' && Ana_Menu_Secim != '3');

        switch(Ana_Menu_Secim)
        {
        case '1':  // Musteri Islemleri Menusu
        {
            do
            {
                *pMusteri_Islemleri_Secim=MusteriIslemleri(pMusteri_Islemleri_Secim);
                switch(Musteri_Islemleri_Secim)
                {
                case '1':  // Masa Durum Ogrenme
                {
                    MasalarDurum(Masa_Sayisi,Oturma,Menu_Cesidi,Menutur_Cesit);
                    break;
                }
                case '2':  // Masa Siparis Sistemi
                {
                    MasaSiparisIslemleri(Masa_Sayisi,Oturma,Menu_Cesidi,pMenutur_Cesit);
                    break;
                }
                case '3':  // Masa Hesap Kesimi
                {
                    HesapKesim(Masa_Sayisi,Oturma);
                    break;
                }
                case '4':  // Masa Tasima
                {
                    MasaTasima(Oturma,Masa_Sayisi);
                    break;
                }
                case '5':  // Ana Menuye Donme
                {
                    break;
                }
                case '6':  // Otomasyondan Cikis
                {
                    system("cls");
                    printf("\n\nKULLANDIGINIZ ICIN TESEKKUR EDERIM...\n\n");
                    return 0;
                }
                }
            }
            while(Musteri_Islemleri_Secim!='5' && Musteri_Islemleri_Secim!='6');
            break;
        }
        case '2':  // Stok Islemleri Menusu
        {

            *pKullanici_Giris_Secim=KullaniciGiris(pKullanici_Giris_Secim,pKullaniciAdi,KullaniciSifre);  // Giris Dogrulamasi
            if(Kullanici_Giris_Secim=='1')
            {
                do
                {
                    *pStok_Islemleri_Secim=StokIslemleri(pStok_Islemleri_Secim);
                    switch(Stok_Islemleri_Secim)
                    {
                    case '1':  // Stok Kontrol
                    {
                        StokKontrol(Oturma);
                        break;
                    }
                    case '2': // Stok Arttırma Yada Azaltma
                    {
                        StokEkleme(Oturma,Masa_Sayisi);
                        break;
                    }
                    case '3': // Yeni Urun Ekleme
                    {
                        YeniUrunEkleme(Oturma,Masa_Sayisi);
                        break;
                    }
                    case '4': // Urun Silme
                    {
                        UrunSilme(Oturma,Masa_Sayisi);
                        break;
                    }
                    case '5':  // Kapasite Ayarlama
                    {
                        Yeni_Masa_Sayisi=KapasiteAyari(pMasa_Sayisi,Oturma);
                        if(Yeni_Masa_Sayisi==0)
                        {
                            break;
                        }                                                                   // Duzenlenen bilgiler ile sistem guncellemesi yapma
                        Oturma = realloc (Oturma,sizeof(Masa)*Yeni_Masa_Sayisi);
                        SistemDoldurma(Masa_Sayisi,Yeni_Masa_Sayisi,Oturma,Menu_Cesidi,Menutur_Cesit);
                        Masa_Sayisi= Yeni_Masa_Sayisi;

                        break;
                    }
                    case '6':  // Admin Bilgi Degisikligi
                    {
                        AdminBilgiDegisiklik(pKullaniciAdi,pKullaniciSifre);
                        break;
                    }
                    case '7':  // Ana Menuye Donme
                    {
                        break;
                    }
                    case '8': // Otomasyondan Cikis
                    {
                        system("cls");
                        printf("\n\nKULLANDIGINIZ ICIN TESEKKUR EDERIM...\n\n");
                        return 0;
                    }
                    }
                }
                while(Stok_Islemleri_Secim!='6' && Stok_Islemleri_Secim!='7');
            }

            break;
        }
        case '3': // Otomasyondan cikis
        {
            system("cls");
            printf("\n\nKULLANDIGINIZ ICIN TESEKKUR EDERIM...\n\n");
            return 0;
        }
        }
    }
    return 0;
}
