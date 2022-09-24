/********************************************************************************
* file.h: Inneh�ller funktionalitet f�r filhantering via externa funktioner. 
********************************************************************************/
#ifndef FILE_H_
#define FILE_H_

/* Inkluderingsdirektiv: */
#include <stdio.h>

/********************************************************************************
* file_write: Skriver ett textstycke till angiven fils�kv�g. Eventuellt
*             tidigare inneh�ll skrivs �ver.
* 
*             - filepath: Pekare till fils�kv�gen dit skrivning skall ske.
*             - s       : Pekare till textstycket som skall skrivas.
********************************************************************************/
void file_write(const char* filepath,
                const char* s);

/********************************************************************************
* file_append: Bifogar ett textstycke till angiven fils�kv�g. 
*              Det nya textstycket l�ggs till l�ngst ned i filen.
*
*             - filepath: Pekare till fils�kv�gen dit befogning skall ske.
*             - s       : Pekare till textstycket som skall skrivas.
********************************************************************************/
void file_append(const char* filepath,
                 const char* s);

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
                       FILE* ostream);

/********************************************************************************
* file_read: L�ser inneh�llet fr�n angiven fils�kv�g rad f�r rad och skriver
*            ut i terminalen.
* 
*            - filepath: Pekare till fils�kv�gen d�r l�sning skall ske.
********************************************************************************/
void file_read(const char* filepath);

#endif /* FILE_H_ */