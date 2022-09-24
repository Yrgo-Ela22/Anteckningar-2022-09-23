/********************************************************************************
* repetition.c: Repetitionsuppgift innefattande pekare till arrayer. I detta
*               fall används också en statisk lokal variabel num i funktionen
*               assign för att kunna tilldela olika flyttal till angiven array
*               vid varje funktionsanrop. 
*
*               När variabeln num sätts till statisk så lagras denna i RAM-minnet 
*               i stället för på stacken eller ett CPU-register, vilket medför 
*               att dess livslängd går från att sträcka sig till aktuell 
*               funktion till hela programmet. Det värde som tilldelas till
*               variabeln num kvarstår då mellan funktionsanrop. 
*
*               Genom att variabeln num ökar med 0.5 efter varje tilldelning 
*               så ökar därmed värdet på variabel num kontinuerligt utan att
*               någonsin återställas till 0. Annars om num inte hade satts till
*               statisk så hade denna raderats efter att funktionen assign 
*               avslutas. Vid varje anrop hade då en ny variabel num med 
*               startvärde 0 skapats, som sedan hade raderats när funktionen
*               avslutas.
********************************************************************************/
#include <stdio.h>

/********************************************************************************
* assign: Fyller angiven array till bredden med flyttal, använder stegvärde 0.5.
*         Vid varje anrop tilldelas unika heltal genom att uppräkningsvariabel
*         num sätts till statisk och därmed kvarstår under hela programmet.
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
*        - numbers: Pekare till arrayen vars innehåll skall skrivas ut.
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
* main: Deklarerar en statisk array döpt numbers, som rymmer 20 flyttal.
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