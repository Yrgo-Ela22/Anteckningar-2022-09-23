/********************************************************************************
* main.c: Demonstration av filhantering i C via ett fåtal externa funktioner
*         deklarerade i den egenskapade headerfilen file.h.z
* 
*         Filhantering genomförs enligt nedan i C:
* 
*         1. Öppna filen för skrivning via en filpekare via funktionen fopen.
*            Passera filsökvägen samt vad som skall ske, exempelvis "w" (write)
*            för skrivning till fil, där eventuellt tidigare innehåll i filen 
*            raderas, "a" (append) för bifogande av text längst bak i filen
*            samt "r" (read) för läsning av innehåll på filsökvägen.
* 
*            Antag att en pekare döpt filepath pekare på filsökvägen data.txt
*            enligt nedan:
* 
*            const char* filepath = "data.txt";
* 
*            För att öppna filen data.txt för skrivning via filpekaren ostream
*            kan följande instruktion användas:
* 
*            FILE* ostream = fopen(filepath, "w");
* 
*            För att öppna filen data.txt för läsning via filpekaren istream 
*            kan följande instruktion användas:
* 
*            FILE* istream = fopen(filepath, "r");
* 
*         2. Kontrollera att filen gick att öppna. Om det inte gick att öppna
*            filen returneras en nullpekare från filen fopen. Om filpekaren är
*            null (kontrolleras via NULL eller 0), så gick filen inte att öppna.
*            Skriv då ut ett felmeddelande, föredragsvis till standardfelenheten
*            stderr via funktionen fprintf, men utskrift i terminalen via printf
*            är också okej). Avsluta funktionen ifall filen inte gick att öppna.
* 
*            För att kontrollera att filen data.txt gick att öppna för skrivning
*            via ovanstående filpekare ostream kan följande if-sats användas:
* 
*            if (!ostream)
*            {
*               fprintf(stderr, "Could not open file at path %s!\n", filepath);
*            }
* 
*         3. Om filen gick att öppna, genomför antingen skrivning/bifogande av
*            text via funktionen fprintf eller filläsning via funktionen fgets.
* 
*            Vid skrivning/bifogande av text, använd filpekaren ostream som 
*            första argument följt av det som skall skrivas till filen 
*            (förutom första argumentet fungerar fprintf exakt samma som printf). 
* 
*            Som exempel, för att skriva/bifoga innehållet lagrat i en intvariabel
*            x till filen data.txt kan följande instruktion användas:
*            
*            fprintf(ostream, "%d", x);
* 
*            Vid läsning, deklarera en sträng för lagring av text från varje
*            inläst rad. En lämplig storlek är 100 tecken, vilket kan 
*            implementeras via en sträng döpt s, som initieras till tom vid
*            start via nedanstående instruktion: 
*
*            char s[100] = { '\0' };
* 
*            En given rad kan läsas ur filen via anrop af funktionen fgets:
* 
*            fgets(s, (int)sizeof(s), istream);
* 
*            Vid anropet till inläsningsfunktionen fgets passeras en pekare
*            till strängen där aktuell inläst rad temporärt skall lagras,
*            sedan passeras strängens storlek (så att högst så många tecken
*            som strängen rymmer läses in) följt av filpekaren till filen
*            där läsningen skall ske från.
* 
*            Ovanstående instruktion medför dock enbart läsning av en enda
*            rad. För att läsa in rad för rad tills filen är slut kan
*            ovanstående instruktion används som villkor till en while-sats:
* 
*            while (fgets(s, (int)sizeof(s), istream))
*            {
*            }
* 
*            Eftersom en pekare till den textsnutt som läses in returneras
*            från funktionen fgets och en nullpekare returneras när filen är
*            slut så medför ovanstående while-sats att så länge rad läses in
*            så fortgår while-satsen. 
* 
*            Eftersom varje inläst rad lagras i strängen s så kan utskrift
*            av denna rad genomföras via formatspecificare %s:
* 
*            printf("%s", s);
* 
*            Nedanstående while-sats medför därmed inläsning av varje rad i
*            aktuell fil, följt av utskrift i terminalen:
*             
*            while (fgets(s, (int)sizeof(s), istream))
*            {
*               printf("%s", s);
*            }
*
*         4. Stäng filen efter slutförd läsning/skrivning via anrop av 
*            funktionen fclose. Passera använd filpekare. Som exempel, för
*            att stänga filen data.txt, som tidigare öppnades för skrivning
*            via filpekaren ostream, kan filen stängas via följande instruktion:
* 
*            fclose(ostream);
* 
*         OBS! För att använda funktionen fopen i Visual Studio, högerklicka
*         på projektnamnet, scrolla ned till Properties. I den nya ruta som
*         kommer upp, klicka på C/C++ -> Preprocessor. I rutan märkt
*         Preprocessor Definitions, skrivs in _CRT_SECURE_NO_WARNINGS.
*         Se till att ha ett blanksteg mellan föregående definition och 
*         denna nya definition.
*
*         Tips: För att enkelt läsa innehållet skrivet till en viss fil utan
*         att använda en filskrivningsfunktion, klicka på Tools -> Command Line 
*         -> Developer Command Prompt. I den terminal som dyker upp, skriv 
*         kommandot type följt av filens namn för att skriva ut innehållet. 
*         Som exempel, för att läsa innehållet från filen numbers.txt, skriv 
*         följande kommando (utan dollartecknet):
* 
*         $ type numbers.txt
********************************************************************************/
#include "file.h"

/********************************************************************************
* main: Skriver två rader text till filen data.txt. Filens innehåll skrivs 
*       sedan ut i terminalen. Därefter skrivs fem flyttal ut i terminalen
*       samt till en fil döpt numbers.txt.
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
