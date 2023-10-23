/*
Willkommen zum vierten Übungsblatt vom Programmierkurs.

Nachdem Sie in einem Terminal mittels des 'cd' Befehls in das Verzeichnis gewechselt sind, in dem diese Datei liegt,
können Sie mit folgendem Befehl ihre Lösungen überprüfen:
cc -std=c11 -g -Wall 04practice_test.c -o 04practice_test.o -lm && ./04practice_test.o

Auf diesem Blatt geht es primär darum, komplexe Probleme erfolgreich anzugehen.
*/

#include <stdio.h>
#include "04_canvas.h"

/*
Nehme eine dreistellige Zahl, sortiere ihre Ziffern absteigend, und subtrahiere von dieser Zahl die Zahl die
sich aus den aufsteigend sortierten Ziffern ergibt.
Wiederhole, bis zwei mal in Folge die gleiche Zahl herauskommt.

Beispiel:
Sort the number into (bigger to smaller) - (smaller to bigger)
792 ~> 972 - 279 = 693
693 ~> 963 - 369 = 594
594 ~> 954 - 459 = 495
495 ~> 954 - 459 = 495

Gebe in dieser Funktion zurück, wie viele Schritte die dreistellige Eingabezahl 'n' braucht, um bei einer Zahl anzukommen,
bei der die sortiere-und-subtrahiere Prozedur wieder die Zahl selbst ausgibt.

Beispiele: 'kaprekar_count_steps(792) == 3', 'kaprekar_count_steps(693) == 2',
           'kaprekar_count_steps(594) == 1', 'kaprekar_count_steps(495) == 0'

Hinweis: Sollte die Eingabe 'x' kleiner als 100 sein (also weniger als 3 Dezimalstellen besitzen), sollte sie trotzdem
dreistellig behandelt werden, indem Nullen vorangesetzt werden. D.H. 64 ~> 640 - 046 = 594.
*/

int Firstdigit(int x)
{
    return x / 100;
}

int Seconddigit(int y)
{
    return (y / 10) % 10;
}

int Thirddigit(int z)
{
    return z % 10;
}

int sortDesc(int x, int y, int z) {
    int temp;
    if (x < y) 
    {
        temp = x;
        x = y;
        y = temp;
    }

    if (x < z) 
    {
        temp = x;
        x = z;
        z = temp;
    }

    if (y < z) 
    {
        temp = y;
        y = z;
        z = temp;
    }

    return x * 100 + y * 10 + z;
}

int sortAsce(int x, int y, int z) {
    int temp;
    if (x > y) 
    {
        temp = x;
        x = y;
        y = temp;
    }

    if (x > z) 
    {
        temp = x;
        x = z;
        z = temp;
    }

    if (y > z) 
    {
        temp = y;
        y = z;
        z = temp;
    }

    return x * 100 + y * 10 + z;
}

int getsinglestep(int x) {
    int a = Firstdigit(x);
    int b = Seconddigit(x);
    int c = Thirddigit(x);

    int d = sortDesc(a, b, c);
    int e = sortAsce(a, b, c);
    return d - e;
}

int expandnumber(int x)
{
    while (x < 100)
    {
        x *= 10;
    }
    return x;
}


int kaprekar_count_steps(int x) {
    
    x = expandnumber(x);
    
    int prev;
    int counter = 0;
    while (prev != x) {
        prev = x;
         x = getsinglestep(x);
        counter++;
    }
    
    return counter - 1;
}

/*
Färbe alle Pixel (mit den Koordinaten '(x, y)') auf dem Canvas schwarz, für welche die sortiere-und-subtrahiere Aktion
von 'x' die Zahl 'y' ergibt.

Bonus: Gibt es ein Muster, dass man ausnutzen kann um 'kaprekar_count_steps' effizienter zu implementieren als
alle Schritte durchzuführen?
*/
Canvas plot_kaprekar(Canvas c) {
    return c;
}
