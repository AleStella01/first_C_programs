#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    float c,m;
    c=pow(7,29)%65;
    printf("c= %f", &c);
    m=pow(c,5)%65;
    printf("m= %f", &m);
    return 0;
}
