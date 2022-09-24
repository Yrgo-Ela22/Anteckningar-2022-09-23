/********************************************************************************
* main.c: Demonstration av filhantering i C via ett f�tal externa funktioner
*         deklarerade i den egenskapade headerfilen file.h.z
* 
*         Filhantering genomf�rs enligt nedan i C:
* 
*         1. �ppna filen f�r skrivning via en filpekare via funktionen fopen.
*            Passera fils�kv�gen samt vad som skall ske, exempelvis "w" (write)
*            f�r skrivning till fil, d�r eventuellt tidigare inneh�ll i filen 
*            raderas, "a" (append) f�r bifogande av text l�ngst bak i filen
*            samt "r" (read) f�r l�sning av inneh�ll p� fils�kv�gen.
* 
*            Antag att en pekare d�pt filepath pekare p� fils�kv�gen data.txt
*            enligt nedan:
* 
*            const char* filepath = "data.txt";
* 
*            F�r att �ppna filen data.txt f�r skrivning via filpekaren ostream
*            kan f�ljande instruktion anv�ndas:
* 
*            FILE* ostream = fopen(filepath, "w");
* 
*            F�r att �ppna filen data.txt f�r l�sning via filpekaren istream 
*            kan f�ljande instruktion anv�ndas:
* 
*            FILE* istream = fopen(filepath, "r");
* 
*         2. Kontrollera att filen gick att �ppna. Om det inte gick att �ppna
*            filen returneras en nullpekare fr�n filen fopen. Om filpekaren �r
*            null (kontrolleras via NULL eller 0), s� gick filen inte att �ppna.
*            Skriv d� ut ett felmeddelande, f�redragsvis till standardfelenheten
*            stderr via funktionen fprintf, men utskrift i terminalen via printf
*            �r ocks� okej). Avsluta funktionen ifall filen inte gick att �ppna.
* 
*            F�r att kontrollera att filen data.txt gick att �ppna f�r skrivning
*            via ovanst�ende filpekare ostream kan f�ljande if-sats anv�ndas:
* 
*            if (!ostream)
*            {
*               fprintf(ostream, "Could not open file at path %s!\n", filepath);
*            }
* 
*         3. Om filen gick att �ppna, genomf�r antingen skrivning/bifogande av
*            text via funktionen fprintf eller fill�sning via funktionen fgets.
* 
*            Vid skrivning/bifogande av text, anv�nd filpekaren ostream som 
*            f�rsta argument f�ljt av det som skall skrivas till filen 
*            (f�rutom f�rsta argumentet fungerar fprintf exakt samma som printf). 
* 
*            Som exempel, f�r att skriva/bifoga inneh�llet lagrat i en intvariabel
*            x till filen data.txt kan f�ljande instruktion anv�ndas:
*            
*            fprintf(ostream, "%d", x);
* 
*            Vid l�sning, deklarera en str�ng f�r lagring av text fr�n varje
*            inl�st rad. En l�mplig storlek �r 100 tecken, vilket kan 
*            implementeras via en str�ng d�pt s, som initieras till tom vid
*            start via nedanst�ende instruktion: 
*
*            char s[100] = { '\0' };
* 
*            En given rad kan l�sas ur filen via anrop af funktionen fgets:
* 
*            fgets(s, (int)sizeof(s), istream);
* 
*            Vid anropet till inl�sningsfunktionen fgets passeras en pekare
*            till str�ngen d�r aktuell inl�st rad tempor�rt skall lagras,
*            sedan passeras str�ngens storlek (s� att h�gst s� m�nga tecken
*            som str�ngen rymmer l�ses in) f�ljt av filpekaren till filen
*            d�r l�sningen skall ske fr�n.
* 
*            Ovanst�ende instruktion medf�r dock enbart l�sning av en enda
*            rad. F�r att l�sa in rad f�r rad tills filen �r slut kan
*            ovanst�ende instruktion anv�nds som villkor till en while-sats:
* 
*            while (fgets(s, (int)sizeof(s), istream))
*            {
*            }
* 
*            Eftersom en pekare till den textsnutt som l�ses in returneras
*            fr�n funktionen fgets och en nullpekare returneras n�r filen �r
*            slut s� medf�r ovanst�ende while-sats att s� l�nge rad l�ses in
*            s� fortg�r while-satsen. 
* 
*            Eftersom varje inl�st rad lagras i str�ngen s s� kan utskrift
*            av denna rad genomf�ras via formatspecificare %s:
* 
*            printf("%s", s);
* 
*            Nedanst�ende while-sats medf�r d�rmed inl�sning av varje rad i
*            aktuell fil, f�ljt av utskrift i terminalen:
*             
*            while (fgets(s, (int)sizeof(s), istream))
*            {
*               printf("%s", s);
*            }
*
*         4. St�ng filen efter slutf�rd l�sning/skrivning via anrop av 
*            funktionen fclose. Passera anv�nd filpekare. Som exempel, f�r
*            att st�nga filen data.txt, som tidigare �ppnades f�r skrivning
*            via filpekaren ostream, kan filen st�ngas via f�ljande instruktion:
* 
*            fclose(ostream);
* 
*         OBS! F�r att anv�nda funktionen fopen i Visual Studio, h�gerklicka
*         p� projektnamnet, scrolla ned till Properties. I den nya ruta som
*         kommer upp, klicka p� C/C++ -> Preprocessor. I rutan m�rkt
*         Preprocessor Definitions, skrivs in _CRT_SECURE_NO_WARNINGS.
*         Se till att ha ett blanksteg mellan f�reg�ende definition och 
*         denna nya definition.
*
*         Tips: F�r att enkelt l�sa inneh�llet skrivet till en viss fil utan
*         att anv�nda en filskrivningsfunktion, klicka p� Tools -> Command Line 
*         -> Developer Command Prompt. I den terminal som dyker upp, skriv 
*         kommandot type f�ljt av filens namn f�r att skriva ut inneh�llet. 
*         Som exempel, f�r att l�sa inneh�llet fr�n filen numbers.txt, skriv 
*         f�ljande kommando (utan dollartecknet):
* 
*         $ type numbers.txt
********************************************************************************/
#include "file.h"

/********************************************************************************
* main: Skriver tv� rader text till filen data.txt. Filens inneh�ll skrivs 
*       sedan ut i terminalen. D�refter skrivs fem flyttal ut i terminalen
*       samt till en fil d�pt numbers.txt.
********************************************************************************/
int main(void)
{
   const char* filepath1 = "data.txt";
   const char* filepath2 = "numbers.txt";

   file_write(filepath1, "This is the first write!");
   file_append(filepath1, "The is appended to the same file!");
   file_read(filepath1);

   const double numbers[5] = { 10, 20, 30, 40, 50 };
   FILE* ostream = fopen(filepath2, "w");
   file_print_double(numbers, 5, ostream);

   return 0;
} 