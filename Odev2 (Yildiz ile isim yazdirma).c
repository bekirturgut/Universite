#include <stdio.h>
#include <stdlib.h>

int main()
{
    int boyut;
    printf("----------| YILDIZ ILE ISIM YAZDIRMA |----------\n\n\n");
    printf("Boyut giriniz : ");
    scanf("%d",&boyut);
    printf("\n\n///////////////////////////////////////////////////////////////////\n\n\n");
    int i,j;

// B HARFI

    for(i=1;i<=boyut;i++)
    {
        for(j=1;j<=boyut;j++)
        {
            if(j==1 || i==1 && j<boyut-(boyut/4) || i==boyut && j<boyut-(boyut/4) || i==(boyut+1)/2 && j<boyut-(boyut/4)) printf("*");
            else if(i==boyut && j<boyut-(boyut/4) || j+i==boyut+(boyut/4)+1 && i<boyut/2+1) printf("*");
            else if(j-i==boyut-(boyut/4) || j-i ==boyut-(boyut*3)/4 && i>boyut/2 || j+i==boyut*2-(boyut/4)) printf("*");
            else printf(" ");
        }
        printf("\n");
    }
printf("\n\n");

// E HARFI

    for(i=1;i<=boyut;i++)
    {
        for(j=1;j<=boyut;j++)
        {
            if(j==1 || i==1 || i==boyut || i==boyut/2+1) printf("*");
            else printf(" ");
        }
        printf("\n");
    }
printf("\n\n");

// K HARFI

    for(i=1;i<=boyut;i++)
    {
        for(j=1;j<=boyut;j++)
        {
            if(j==1 || i==boyut/2+1 && j<boyut/2+1 || j+i==boyut+1 && i<boyut/2+2 || j==i && i>boyut/2) printf("*");
            else printf(" ");
        }
        printf("\n");
    }
printf("\n\n");

// I HARFI

    for(i=1;i<=boyut;i++)
    {
        for(j=1;j<=boyut;j++)
        {
            if(j== boyut/2-1 && i<boyut/4+2 || j==boyut/2+1 && i<boyut/4+2 || j==boyut/2 && i==1 || j==boyut/2 && i==boyut/4+1) printf("*");
            else if(j==boyut/2 && i>boyut/4+2) printf("*");
            else printf(" ");
        }
        printf("\n");
    }
printf("\n");

// R HARFI

    for(i=1;i<=boyut;i++)
    {
        for(j=1;j<=boyut;j++)
        {
            if(j==1 || i==1 && j<boyut-(boyut/4) || j-i==boyut-(boyut/4)-1 || i==boyut/2+1 && j<boyut-(boyut/4)) printf("*");
            else if(i+j==boyut+boyut/3 && i<boyut/2+1 || j-i==boyut/4 && i>boyut/2+1 || j==boyut && i>boyut-boyut/4) printf("*");
            else printf(" ");
        }
        printf("\n");
    }
printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

// T HARFI

    for(i=1;i<=boyut;i++)
    {
        for(j=1;j<=boyut;j++)
        {
            if(j==boyut/2+1 || i==1 || i==2 && j==1 || i==2 && j==boyut) printf("*");
            else printf(" ");
        }
        printf("\n");
    }
printf("\n\n");

// U HARFI

    for(i=1;i<=boyut;i++)
    {
        for(j=1;j<=boyut;j++)
        {
            if(i-j==boyut*3/4 || j+i==boyut*2-(boyut/4) || i==boyut && j>boyut/4+1 && j<boyut-(boyut/4) || j==1 && i<boyut-(boyut/4) || j==boyut && i<boyut-(boyut/4)) printf("*");
            else if(0) printf("*");
            else printf(" ");
        }
        printf("\n");
    }
printf("\n\n");

// R HARFI

    for(i=1;i<=boyut;i++)
    {
        for(j=1;j<=boyut;j++)
        {
            if(j==1 || i==1 && j<boyut-(boyut/4) || j-i==boyut-(boyut/4)-1 || i==boyut/2+1 && j<boyut-(boyut/4)) printf("*");
            else if(i+j==boyut+boyut/3 && i<boyut/2+1 || j-i==boyut/4 && i>boyut/2+1 || j==boyut && i>boyut-boyut/4) printf("*");
            else printf(" ");
        }
        printf("\n");
    }
printf("\n\n");

// G HARFI

    for(i=1;i<=boyut;i++)
    {
        for(j=1;j<=boyut;j++)
        {
            if(j-i==boyut-(boyut/4) || i+j==boyut-(boyut*3/4) || i==1 && j>boyut/4 && j<boyut-(boyut/5) || j==1 && i>boyut/4 && i<(boyut-(boyut/4)+1)) printf("*");
            else if(i-j==boyut-(boyut/4) || i==boyut && j>boyut/4 && j<boyut-(boyut/4)+3 || i+j==boyut*2-(boyut/5) || j==boyut && i<boyut-(boyut/5) && i>boyut/2+1) printf("*");
            else if(i==boyut/2+1 && j>boyut/2-1) printf("*");
            else printf(" ");
        }
        printf("\n");
    }
printf("\n\n");

// U HARFI

    for(i=1;i<=boyut;i++)
    {
        for(j=1;j<=boyut;j++)
        {
            if(i-j==boyut*3/4 || j+i==boyut*2-(boyut/4) || i==boyut && j>boyut/4+1 && j<boyut-(boyut/4) || j==1 && i<boyut-(boyut/4) || j==boyut && i<boyut-(boyut/4)) printf("*");
            else if(0) printf("*");
            else printf(" ");
        }
        printf("\n");
    }
printf("\n\n");

// T HARFI

    for(i=1;i<=boyut;i++)
    {
        for(j=1;j<=boyut;j++)
        {
            if(j==boyut/2+1 || i==1 || i==2 && j==1 || i==2 && j==boyut) printf("*");
            else printf(" ");
        }
        printf("\n");
    }
printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

// B HARFI

    for(i=1;i<=boyut;i++)
    {
        for(j=1;j<=boyut;j++)
        {
            if(j==1 || i==1 && j<boyut-(boyut/4) || i==boyut && j<boyut-(boyut/4) || i==(boyut+1)/2 && j<boyut-(boyut/4)) printf("*");
            else if(i==boyut && j<boyut-(boyut/4) || j+i==boyut+(boyut/4)+1 && i<boyut/2+1) printf("*");
            else if(j-i==boyut-(boyut/4) || j-i ==boyut-(boyut*3)/4 && i>boyut/2 || j+i==boyut*2-(boyut/4)) printf("*");
            else printf(" ");
        }
        printf("\n");
    }
printf("\n\n");

// A HARFI

    for(i=1;i<=boyut;i++)
    {
        for(j=1;j<=boyut;j++)
        {
            if(i+j==boyut/3 || j-i==boyut-(boyut/3) || i==1 && j<boyut-(boyut/4+1) && j>boyut/4+1) printf("*");
            else if(j==1 && i>boyut/3-1 || j==boyut && i>boyut/3 || i==boyut/2) printf("*");
            else printf(" ");
        }
        printf("\n");
    }
printf("\n\n");

//Y HARFI

    for(i=1;i<=boyut;i++)
    {
        for(j=1;j<=boyut;j++)
        {
            if(i==j && i<boyut/2+1 || i+j==boyut+1 && i<boyut/2+1 || j==((boyut+1)/2) && i>=boyut/2) printf("*");
            else printf(" ");
        }
        printf("\n");
    }
printf("\n\n");

// B HARFI

    for(i=1;i<=boyut;i++)
    {
        for(j=1;j<=boyut;j++)
        {
            if(j==1 || i==1 && j<boyut-(boyut/4) || i==boyut && j<boyut-(boyut/4) || i==(boyut+1)/2 && j<boyut-(boyut/4)) printf("*");
            else if(i==boyut && j<boyut-(boyut/4) || j+i==boyut+(boyut/4)+1 && i<boyut/2+1) printf("*");
            else if(j-i==boyut-(boyut/4) || j-i ==boyut-(boyut*3)/4 && i>boyut/2 || j+i==boyut*2-(boyut/4)) printf("*");
            else printf(" ");
        }
        printf("\n");
    }
printf("\n\n");

// U HARFI

    for(i=1;i<=boyut;i++)
    {
        for(j=1;j<=boyut;j++)
        {
            if(i-j==boyut*3/4 || j+i==boyut*2-(boyut/4) || i==boyut && j>boyut/4+1 && j<boyut-(boyut/4) || j==1 && i<boyut-(boyut/4) || j==boyut && i<boyut-(boyut/4)) printf("*");
            else if(0) printf("*");
            else printf(" ");
        }
        printf("\n");
    }
printf("\n\n");

// R HARFI

    for(i=1;i<=boyut;i++)
    {
        for(j=1;j<=boyut;j++)
        {
            if(j==1 || i==1 && j<boyut-(boyut/4) || j-i==boyut-(boyut/4)-1 || i==boyut/2+1 && j<boyut-(boyut/4)) printf("*");
            else if(i+j==boyut+boyut/3 && i<boyut/2+1 || j-i==boyut/4 && i>boyut/2+1 || j==boyut && i>boyut-boyut/4) printf("*");
            else printf(" ");
        }
        printf("\n");
    }
printf("\n\n");

// T HARFI

    for(i=1;i<=boyut;i++)
    {
        for(j=1;j<=boyut;j++)
        {
            if(j==boyut/2+1 || i==1 || i==2 && j==1 || i==2 && j==boyut) printf("*");
            else printf(" ");
        }
        printf("\n");
    }
printf("\n\n\n");
    return 0;
}
