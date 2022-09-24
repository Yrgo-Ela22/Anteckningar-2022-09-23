# Anteckningar - 2022-09-23
Filhantering i C via externa funktioner deklarerad i en egenskapad headerfil döpt file.h.

Filen file.h utgör en egenskapad headerfil som innehåller deklaration av skapade filfunktioner
för skrivning och läsning av filer.

Filen file.c innehåller definitioner av de funktioner som deklarerades i filen file.c.

Filen main.c innehåller detaljerad information om filskrivning i C samt demonstrerar skrivning/bifogning
av text och tal samt läsning av filer. 

Filen repetitions.c utgörs av en repetitionsuppgift innefattande pekare till arrayer. 
I detta fall användes också en statisk lokal uppräkningvariabel för att öka livslängden 
från att sträcka sig till ett funktionsanrop till hela programmet. Denna variabels värde
kvarstod då mellan funktionsanrop för att tilldela unika tal till en array vid olika anrop.
