/*
Willkommen zum fünften Aufgabenblatt vom Programmierkurs. Auf diesem Aufabenblatt geht es um Rekursion.

Um die Tests für dieses Blatt zu kompilieren und zu starten, führen Sie den folgenden Befehl aus:
cc -std=c11 -g -Wall 05ex_test.c -o 05ex_test.o -lm && ./05ex_test.o
*/

#include "05_canvas.h"
#include <stdio.h>
#include <math.h>

/*
Aufgabe 1a:
Zeichnen Sie eine horizontale Linie der Länge `width`, deren am weitesten links liegender Pixel bei `(x, y)` ist.

_Benutzen Sie keine Schleifen - Die Aufgabe soll über Rekursion gelöst werden!
*/

Canvas recursive_line(Canvas c, int x, int y, int width) {
    if (width > 0)
    {            
        recursive_line(c, x + 1, y, width - 1);
        if (x >= 0 && x < canvas_width(c) && y >= 0 && y < canvas_height(c))
        {
            return canvas_set_black(c, x, y);
        }
    }
    return c;
}

/*
Aufgabe 1b:
Zeichnen Sie ein Rechteck mit der Breite `width` und der Höhe `height`. Der Pixel der linken unteren Ecke liegt bei `(x, y)`.

_Benutzen Sie keine Schleifen, die Aufgabe soll über Rekursion gelöst werden!_
*/
Canvas recursive_rectangle(Canvas c, int x, int y, int width, int height) {
/*
    for (height > 0; height--;)
    {
        recursive_line(c, x, y + 1 ,width);
        y++;
    }
*/

    if(height > 0)
    {
        recursive_line(c, x, y ,width);
        recursive_rectangle(c, x, y + 1, width, height - 1);
    }


    //bottomhalf
/*
int half = height/2;
    if (half > 0)
    {
        recursive_line(c, x, y , width);
        recursive_rectangle(c, x, y + 1, width, half - 1);
    }
*/

    //tophalf
/*
    if (height > half)
    {
        recursive_line(c, x, y, width);
        recursive_rectangle(c, x, y + half + 1, width, height);
    }
*/


    return c;
}

/*
Aufgabe 2:
Der *Sierpinski Carpet der Ordnung 0* ist ein einzelnes schwarzes Pixel.
Der *Sierpinski Carpet der Ordnung n+1* besteht aus acht Sierpinski Carpets der Ordnung n, angeordnet als drei-mal-drei
Quadrat dessen Mittelstück fehlt.

Beispiele (`X` stellt schwarze Pixel dar)
=========================================

Ordnung 0:

X

Ordnung 1:

XXX
X X
XXX

Ordnung 2:

XXXXXXXXX
X XX XX X
XXXXXXXXX
XXX   XXX
X X   X X
XXX   XXX
XXXXXXXXX
X XX XX X
XXXXXXXXX

Siehe auch die Datei `05sierpinski.jpg`

Aufgabe 2a:
Um in der nächsten Aufgabe den Sierpinski-Carpet auf die Canvas zeichnen zu können müssen Potenzen berechnet werden.
Implementieren Sie die Berechnung der Potenz einer nicht-negativen, ganzzahligen Basis `b` mit einem
nicht-negativen, ganzzahligen Exponenten `exp`.

_Benutzen Sie keine Schleifen, die Aufgabe soll über Rekursion gelöst werden!_
*/

int power(int b, int exp){

    if (exp == 0 && b == 0)
    {
        return 0;
    }
    else if (exp == 0)
    {
        return 1;
    }
    else if (exp > 0)
    {
        return b * power(b, exp - 1);
    }
   
}

/*
int power(int b, int exp){

    if (exp == 0 && b == 0)
    {
        return 0;
    }
    else if (exp == 0)
    {
        return 1;
    }
    else if (exp > 1)
    {
        b = b * power(b, exp - 1);
    }
    return b;
}
*/
/*
Aufgabe 2b:
Diese Funktion soll den Sierpinski Carpet der Ordnung `n` auf die Canvas zeichnen, mit unterer linker Ecke an Koordinate `(x, y)`.

_Benutzen Sie keine Schleifen, die Aufgabe soll über Rekursion gelöst werden!_
*/
Canvas sierpinski_carpet(Canvas c, int n, int x, int y){
        if(n == 0)
        {
            if (x < canvas_width(c) && y < canvas_height(c) && x >= 0 && y >= 0)
            {
                canvas_set_black(c, x, y);
            }
        }
        else
        {
        sierpinski_carpet(c, n-1, x ,y);

        sierpinski_carpet(c, n-1, x + power(3,n-1), y);
        sierpinski_carpet(c, n-1, x + power(3,n-1)*2, y);

        sierpinski_carpet(c, n-1, x, y + power(3,n-1));
        sierpinski_carpet(c, n-1, x, y + power(3,n-1)*2);

        sierpinski_carpet(c, n-1, x + power(3,n-1), y + power(3,n-1)*2);

        sierpinski_carpet(c, n-1, x + power(3,n-1)*2 , y + power(3,n-1));
        sierpinski_carpet(c, n-1, x + power(3,n-1)*2 , y + power(3,n-1)*2);
        }

    return c;
}

/*
    if (n == 0) {
        canvas_set_black(c, x, y); // Set the center pixel to black in the base case
    } else {
        sierpinski_carpet(c, n - 1, x, y);

        sierpinski_carpet(c, n - 1, x + power(3, n - 1), y);
        sierpinski_carpet(c, n - 1, x + power(3, n - 1) * 2, y);

        sierpinski_carpet(c, n - 1, x, y + power(3, n - 1));
        sierpinski_carpet(c, n - 1, x, y + power(3, n - 1) * 2);

        sierpinski_carpet(c, n - 1, x + power(3, n - 1), y + power(3, n - 1) * 2);

        sierpinski_carpet(c, n - 1, x + power(3, n - 1) * 2, y + power(3, n - 1) * 2);
        sierpinski_carpet(c, n - 1, x + power(3, n - 1) * 2, y + power(3, n - 1));
    }
    return c;
}
*/


/*
Aufgabe 3:
Implementieren Sie einen Fülleimer. Gegeben eine Koordinate `(x, y)` auf einer (bereits bemalten) Canvas, soll die komplette
zusammenhängende Fläche aller Pixel der selben Farbe (schwarz oder weiß) schwarz gefärbt werden.
Zwei Pixel sind Teil der selben Fläche wenn sie die selbe Farbe haben und direkt benachbart sind. Jeder Pixel hat bis
zu vier direkte Nachbarn - die Diagonalen zählen nicht.

Funktionen, um die Farbe eines Pixels auf der Canvas zu bestimmen, sind im Headerfile der Canvas dokumentiert.
*/
Canvas bucket_fill(Canvas c, int x, int y){
/*
    for(int a = 0; a < canvas_width(c); a++)
    {
        for(int b = 0; b < canvas_height(c); b++)
        {
                c = canvas_set_black(c,a,b);
        }
    }
*/
    return c;
}