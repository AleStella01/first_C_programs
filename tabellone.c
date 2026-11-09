#include <stdio.h>
#include <stdlib.h>

int main()
{
    int c,i,r;
    c=0;
    i=0;
    r=0;
    while (c<45){
        system ("cls");
        i++;
        if (i==10){
            i=0;
            r++;
        }
        if(r==60){
            r=0;
            c++;
        }
        printf ("%d : %d",c,r);
    }
    return 0;
}
