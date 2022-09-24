/********************************************************************************
* repetition.c: Repetitionsuppgift innefattande pekare till arrayer. I detta
*               fall anv�nds ocks� en statisk lokal variabel num i funktionen
*               assign f�r att kunna tilldela olika flyttal till angiven array
*               vid varje funktionsanrop. 
*
*               N�r variabeln num s�tts till statisk s� lagras denna i RAM-minnet 
*               i st�llet f�r p� stacken eller ett CPU-register, vilket medf�r 
*               att dess livsl�ngd g�r fr�n att str�cka sig till aktuell 
*               funktion till hela programmet. Det v�rde som tilldelas till
*               variabeln num kvarst�r d� mellan funktionsanrop. 
*
*               Genom att variabeln num �kar med 0.5 efter varje tilldelning 
*               s� �kar d�rmed v�rdet p� variabel num kontinuerligt utan att
*               n�gonsin �terst�llas till 0. Annars om num inte hade satts till
*               statisk s� hade denna raderats efter att funktionen assign 
*               avslutas. Vid varje anrop hade d� en ny variabel num med 
*               startv�rde 0 skapats, som sedan hade raderats n�r funktionen
*               avslutas.
********************************************************************************/
#include <stdio.h>

/********************************************************************************
* assign: Fyller angiven array till bredden med flyttal, anv�nder stegv�rde 0.5.
*         Vid varje anrop tilldelas unika heltal genom att uppr�kningsvariabel
*         num s�tts till statisk och d�rmed kvarst�r under hela programmet.
* 
*         - numbers: Pekare till arrayen som skall tilldelas.
*         - size   : Arrayens storlek, dvs. antalet flyttal den rymmer.
********************************************************************************/
void assign(double* numbers,
            const int size)
{
   static double num = 0;

   for (int i = 0; i < size; ++i)
   {
      numbers[i] = num;
      num += 0.5; 
   }

   return;
}

/********************************************************************************
* print: Skriver ut flyttal lagrat i angiven array.
* 
*        - numbers: Pekare till arrayen vars inneh�ll skall skrivas ut.
*        - size   : Arrayens storlek, dvs. antalet flyttal den rymmer.
********************************************************************************/
void print(const double* numbers,
           const int size)
{
   printf("--------------------------------------------------------------------------------\n");

   for (int i = 0; i < size; ++i)
   {
      printf("%lg\n", numbers[i]);
   }

   printf("--------------------------------------------------------------------------------\n\n");
   return;
}

/********************************************************************************
* main: Deklarerar en statisk array d�pt numbers, som rymmer 20 flyttal.
*       Arrayen fylls till bredden med nya flyttal mellan varje anrop.
********************************************************************************/
int main(void)
{
   double numbers[20];
   
   for (int i = 0; i < 5; ++i)
   {
      assign(numbers, 20);
      print(numbers, 20);
   }

   return 0;
}