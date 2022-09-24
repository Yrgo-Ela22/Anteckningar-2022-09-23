/********************************************************************************
* file.h: Definitioner av externa funktioner f�r filhantering.
********************************************************************************/
#include "file.h"

/********************************************************************************
* file_write: Skriver ett textstycke till angiven fils�kv�g.
*
*             - filepath: Pekare till fils�kv�gen dit skrivning skall ske.
*             - s       : Pekare till textstycket som skall skrivas.
********************************************************************************/
void file_write(const char* filepath,
                const char* s)
{
   FILE* ostream = fopen(filepath, "w"); 

   if (!ostream) 
   {
      fprintf(stderr, "Could not open file at path %s!\n\n", filepath);
   }
   else 
   {
      fprintf(ostream, "%s\n", s);
      fclose(ostream); 
   }

   return;
}

/********************************************************************************
* file_append: Bifogar ett textstycke till angiven fils�kv�g.
*              Det nya textstycket l�ggs till l�ngst ned i filen.
*
*             - filepath: Pekare till fils�kv�gen dit befogning skall ske.
*             - s       : Pekare till textstycket som skall skrivas.
********************************************************************************/
void file_append(const char* filepath,
                 const char* s)
{
   FILE* ostream = fopen(filepath, "a");

   if (!ostream)
   {
      fprintf(stderr, "Could not open file at path %s!\n\n", filepath);
   }
   else
   {
      fprintf(ostream, "%s\n", s);
      fclose(ostream);
   }

   return;
}

/********************************************************************************
* file_print_double: Skriver flyttal lagrad i en array via angiven utstr�m,
*                    d�r standardutenheten anv�nds som default f�r utskrift
*                    i terminalen.
*
*                    - numbers: Pekare till arrayen inneh�llande flyttalen.
*                    - size   : Arrayens storlek, dvs. antalet flyttal.
*                    - ostream: Pekare till angiven utstr�m (default = stdout).
********************************************************************************/
void file_print_double(const double* numbers,
                       const int size,
                       FILE* ostream)
{
   if (!ostream)
   {
      ostream = stdout;
   }

   fprintf(ostream, "--------------------------------------------------------------------------------\n");
   
   for (int i = 0; i < size; ++i)
   {
      fprintf(ostream, "%lg\n", numbers[i]);
   }

   fprintf(ostream, "--------------------------------------------------------------------------------\n");
   return;
}

/********************************************************************************
* file_read: L�ser inneh�llet fr�n angiven fils�kv�g rad f�r rad och skriver
*            ut i terminalen.
*
*            - filepath: Pekare till fils�kv�gen d�r l�sning skall ske.
********************************************************************************/
void file_read(const char* filepath)
{
   FILE* istream = fopen(filepath, "r");

   if (!istream)
   {
      fprintf(stderr, "Could not open file at path %s!\n\n", filepath);
   }
   else
   {
      char s[100] = { '\0' };
      
      while (fgets(s, (int)sizeof(s), istream))
      {
         printf("%s", s);
      }

      fclose(istream);
   }

   return;
}
