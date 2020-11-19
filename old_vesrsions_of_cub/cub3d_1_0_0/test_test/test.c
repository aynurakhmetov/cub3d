#include <stdio.h>

int main()
{
    // Побитовые операции

    char a = 3;
    char b = 8;
    char c = a & b;
    printf("%d\n", c);

    char d = a | b; 
    printf("%d\n", d);

    char e = ~a;
    printf("%d\n", e);


    int f = 12;
    printf("%d << 1 == %d\n", f, f << 1);
    printf("%d << 2 == %d\n", f, f << 2);
    printf("%d >> 1 == %d\n", f, f >> 1);
    printf("%d >> 2 == %d\n", f, f >> 2);

    return (0);
}