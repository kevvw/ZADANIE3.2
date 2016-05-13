#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>



void zasady()
{
printf("Czolem!! \n");
printf("Jest to gra w ktorej grac musi sie wykazac znajomoscia logiki i logicznego myslenia.\n");
printf(" W grze chodzi o to by podac dwie wartosci takie ze zaleznie od ich wyniku, glowna logiczne zdanie bylo prawdziwe.");
printf("W grze powinno sie podawac liczby calkowite, kazda inna wartosc wpisana zostanie uznana jako wartosc nieokreslona.\n");
printf("Cala gra sklada sie z 10 rund zatem maksymalnie mozna zdobyc 10pkt.\n");
printf("jesli zle uzgodnisz zdanie logiczne to automatycznie przegrywasz, natomiast za rozwiazanie zdanie logicznego w sposob niejednoznaczny,");
printf("Twoja liczba punktow zostanie zmniejszona o odpowiednia czesc (1/16, 1/8 , 1/4 , 1/2 , 1)");
printf(" zatem widoczne jest ze za podanie 5 niejednoznaczych odpowiedzi takze sie przegrywa.\n");
printf("Mam nadzieje ze zrozumiana jest gra,teraz zapraszam do gryy!!! \n\n\n");
}


void glowny_motyw(int a,int b,int c,int x)
{

   if(a == 1) printf("~ ");
     printf("A");

   if(b == 0)printf(" ^ ");
   else if(b == 1)printf(" v ");
   else if(b == 2)printf(" => ");

   if(c == 1) printf("~ ");
   printf("B");

   if(x == 1) printf("  Prawda \n\n");
   else if(x == 0) printf("  Falsz \n\n");
}


void zadanie(int znak,int liczba,int ktore_pytanie)
{
   if(ktore_pytanie == 0)printf("A - Podaj liczbe za x w nierownosci: ");
   else printf("B - Podaj liczbe za y w nierownosci:  ");



   printf("%d",liczba);

   if(znak == 0) printf(" < ");
   else if(znak == 1) printf(" <= ");
   else if(znak == 2) printf(" > ");
   else printf(" >= ");

   if(ktore_pytanie == 0)
   printf("x\n");
   else
   printf("y\n");
}


char odp_na_zad(int znak, int liczba,int ktore_pytanie)
{
   char odp[100];
int i,wynik,dlugosc;

  if(ktore_pytanie == 0)printf("A: x = ");
   else printf("B: y = ");

scanf("%s",odp);

wynik = atoi(odp);
i = 0;
dlugosc = strlen(odp);
while(i < dlugosc)
{
    if( (i != 0 || odp[i] != '-' || dlugosc < 2) &&  (odp[i] > 57 || odp[i] < 48))
    return 'x';

  i++;
}

  if(znak == 0 && liczba < wynik) return '1';
    else if(znak == 1 && liczba <= wynik) return '1';
    else if(znak == 2 && liczba > wynik) return '1';
    else if(znak == 3 && liczba >= wynik) return '1';
    else return '0';

}


int main(int argc, char **argv)
{
    const int N = 9, M = 6;
    int liczba_rund = 10;
    FILE *AND1,*OR1,*IMPL1,*NOT1;
    char zp;
    int i,j,n = 0;
    char *zaprzeczenieP="not.txt",*implikacjaP="impl.txt",*koniunkcjaP="and.txt",*alternatywaP="or.txt";
    char *zaprzeczenie="--NOT",*implikacja="--IMPL",*koniunkcja="--AND",*alternatywa="--OR";
    char OR[9][6],AND[9][6],NOT[3][4],IMPL[9][6];
    int znak1,znak2,liczba1,liczba2;
    char odpowiedz1,odpowiedz2;
    char result = 'x';
    float obciecie = 0,licznik = 0;

    int zarodek = time(NULL);
    srand(zarodek);
    int  FczyP,znak,pierwszy,drugi;

//*************************************************

if(argc != 9)
{
    printf("podano zla liczbe argumentow,ma ich byc 8\n");
    printf("W komendzie prosze wpisac ./game --AND and.txt --OR or.txt --IMPL impl.txt --NOT not.txt");
    return 0;
}
int cmp1,cmp2;
n = 1;
cmp1 = strcmp(koniunkcja, argv[1]);
cmp2 = strcmp(koniunkcjaP,argv[2]);

    if(cmp1 == 0 && cmp2 == 0)
        AND1 = fopen(argv[2],"r");
    else
    {
        printf("argument 1 lub 2 jest niepoprawny ma byc ... --AND and.txt ... \n");
        return 0;
    }



    if(AND1 == NULL)
    {
        printf("plik and.txt jest pusty, lub nie istnieje");
        return 0;
    }


    for(i = 0; i < N; i++)
        for(j = 0; j < M; j++)
        {
            zp = getc(AND1);
            AND[i][j] = zp;

        }

    fclose(AND1);


n = 3;

     cmp1 = strcmp(alternatywa, argv[n]);
cmp2 = strcmp(alternatywaP,argv[n+1]);

    if(cmp1 == 0 && cmp2 == 0)
        OR1 = fopen(argv[n + 1],"r");
    else
    {
        printf("argument 3 lub 4 jest niepoprawny ma byc ... --OR or.txt ... \n");
        return 0;
    }
    if(OR1 == NULL)
    {
        printf("plik or.txt jest pusty, lub nie istnieje");
        return 0;
    }


    for(i = 0; i < N; i++)
        for(j = 0; j < M; j++)
        {
            zp = getc(OR1);
            OR[i][j] = zp;

        }

    fclose(OR1);
    n += 2;

    cmp1 = strcmp(implikacja, argv[n]);
    cmp2 = strcmp(implikacjaP,argv[n+1]);

    if(cmp1 == 0 && cmp2 == 0)
        IMPL1 = fopen(argv[n + 1],"r");
    else
    {   printf("argument 5 lub 6 jest niepoprawny ma byc ... --IMPL impl.txt ... \n");
        return 0;
    }

    if(IMPL1 == NULL)
    {
        printf("plik impl.txt jest pusty, lub nie istnieje");
        return 0;
    }


    for(i = 0; i < N; i++)
        for(j = 0; j < M; j++)
        {
            zp = getc(IMPL1);
            IMPL[i][j] = zp;
        }

    fclose(IMPL1);
    n += 2;

    cmp1 = strcmp(zaprzeczenie, argv[n]);
    cmp2 = strcmp(zaprzeczenieP,argv[n+1]);

    if(cmp1 == 0 && cmp2 == 0)
        NOT1 = fopen(argv[n + 1],"r");
    else
    {
        printf("argument 7 lub 8 jest niepoprawny ma byc ... --NOT not.txt \n");
        return 0;
    }

    if(NOT1 == NULL)
    {
        printf("plik not.txt jest pusty, lub nie istnieje");
        return 0;
    }

    for(i = 0; i < 3; i++)
        for(j = 0; j < 4; j++)
        {
            zp = getc(NOT1);
            NOT[i][j] = zp;
        }

    fclose(NOT1);

    zasady();


 for(j = 1; j < liczba_rund; j++)
 {
    printf("\nrunda %i: \n",j);



//******************************************************

    znak = rand()%3;      // 0 to ^ , 1 to v, 2 to =>
    pierwszy = rand()%2;  // czy pierwszy jest zaprzeczony czy nie 1 to ~
    drugi = rand()%2;    //czy drugi jest zaprzeczony czy nie 1 to ~
    FczyP = rand()%2;    // czy wynik ma byc prawdziwy czy falszywy
    glowny_motyw(pierwszy,znak,drugi,FczyP);


//********************************************************


    znak1 = rand()%4;     //znak w pierwszej nierownosci
    liczba1 = rand()%100;
    zadanie(znak1,liczba1,0);

    znak2 = rand()%4;   //znak w drugiej nierowwnosci
    liczba2 = rand()%100;
    zadanie(znak2,liczba2,1);

    odpowiedz1 = odp_na_zad(znak1,liczba1,0);
    odpowiedz2 = odp_na_zad(znak2,liczba2,1);


//************************************************


    if(pierwszy == 1)
    {
        for(i = 0; i < 3; i++)
        {
            if(NOT[i][0] == odpowiedz1)
            {   odpowiedz1 = NOT[i][2];
                i = 3;
            }
        }
    }
    if(drugi == 1)
    {
        for(i = 0; i < 3; i++)
        {
            if(NOT[i][0] == odpowiedz2)
            {   odpowiedz2 = NOT[i][2];
                i = 4;
            }
        }
    }


//********************************************


    if(znak == 0)
    {
        for(i = 0; i < 9; i++)
            if(AND[i][0] == odpowiedz1 && AND[i][2] == odpowiedz2)
            {
                result = AND[i][4];
                i = 9;
            }
    }
    else if(znak == 1)
    {
        for(i = 0; i < 9; i++)
            if(OR[i][0] == odpowiedz1 && OR[i][2] == odpowiedz2)
            {
                result = OR[i][4];
                i= 9;
            }
    }
    else if(znak == 2)
    {
        for(i = 0; i < 9; i++)
            if(IMPL[i][0] == odpowiedz1 && IMPL[i][2] == odpowiedz2)
            {
                result = IMPL[i][4];
                i = 9;
            }
    }


//*********************************************


    if((result == '1' && FczyP == 1) || (result == '0' && FczyP == 0))
    {
        printf("Poprawna Odpowiedz\n");
        licznik += 1;
    }
    else if(result == 'x')
    {
        if(obciecie == 0)
            obciecie += 0.0625;
        else if(obciecie < 1 && obciecie != 0)
            obciecie *= 2;
        if(obciecie < 1)
            printf("wynik niejednoznaczny zatem wspolczynnik obciecia jest rowny %f \n",obciecie);
        else
        {
            printf("Piata niejednoznaczna odpowiedz, koniec gry!!\n");
            j = liczba_rund;
        }
    }
    else
    {
        printf("Zla odpowiedz, koniec gry!!\n");
        j = liczba_rund;
    }


}

printf("wynik koncowy %f\n",licznik - licznik*obciecie);

return 0;
}
