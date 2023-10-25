#include<stdio.h>

int endlos = 0;

int schrittZwei (int z) {
    if (z % 2 == 0) {
        z = z / 2;
        if (z != 1) {
            z = schrittZwei(z);
        }
    }
    return z;
}

int schrittDrei (int z) {
    if (z % 3 == 0) {
        z = z / 3;
        if (z != 1) {
            z = schrittZwei(z);
            z = schrittDrei(z);
        }
    }
    return z;
}

int schrittVier (int z) {
    z = z + 5;
    endlos++;
    z = schrittZwei(z);
    if (z != 1)
        {
            z = schrittDrei(z);
            if (endlos > 20)
            {
                endlos = 200;
            }            
            else if (z != 1)
            {
                z = schrittVier(z);
            }
        }
    return z;
}


int main () {
    for (int i = 9; i < 210; i++)
    {
        endlos = 0;
        int z = i;
        z = schrittZwei(z);
        if (z == 1)
        {
            printf("Startzahl %d Ausgabe %d\n", i,z);
            continue;
        }
        z = schrittDrei(z);
        if (z == 1)
        {
            printf("Startzahl %d Ausgabe %d\n", i,z);
            continue;
        }
        z = schrittVier(z);
        if (endlos > 20)
            {
                printf("Startzahl %d : Endlosshleife erkannt!\n", i);
            }
        else
        {
            printf("Startzahl %d Ausgabe %d\n", i,z);
        }
    }
    
}