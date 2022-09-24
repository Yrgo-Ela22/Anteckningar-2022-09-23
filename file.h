/********************************************************************************
* file.h: Innehåller funktionalitet för filhantering via externa funktioner. 
********************************************************************************/
#ifndef FILE_H_
#define FILE_H_

/* Inkluderingsdirektiv: */
#include <stdio.h>

/********************************************************************************
* file_write: Skriver ett textstycke till angiven filsökväg. Eventuellt
*             tidigare innehåll skrivs över.
* 
*             - filepath: Pekare till filsökvägen dit skrivning skall ske.
*             - s       : Pekare till textstycket som skall skrivas.
********************************************************************************/
void file_write(const char* filepath,
                const char* s);

/********************************************************************************
* file_append: Bifogar ett textstycke till angiven filsökväg. 
*              Det nya textstycket läggs till längst ned i filen.
*
*             - filepath: Pekare till filsökvägen dit befogning skall ske.
*             - s       : Pekare till textstycket som skall skrivas.
********************************************************************************/
void file_append(const char* filepath,
                 const char* s);

/********************************************************************************
* file_print_double: Skriver flyttal lagrad i en array via angiven utström,
*                    där standardutenheten används som default för utskrift
*                    i terminalen.
* 
*                    - numbers: Pekare till arrayen innehållande flyttalen.
*                    - size   : Arrayens storlek, dvs. antalet flyttal.
*                    - ostream: Pekare till angiven utström (default = stdout).
********************************************************************************/
void file_print_double(const double* numbers, 
                       const int size,
                       FILE* ostream);

/********************************************************************************
* file_read: Läser innehållet från angiven filsökväg rad för rad och skriver
*            ut i terminalen.
* 
*            - filepath: Pekare till filsökvägen där läsning skall ske.
********************************************************************************/
void file_read(const char* filepath);

#endif /* FILE_H_ */