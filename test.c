#include <stdio.h>
#include <unistd.h>
#include <string.h>


int main()
{
    char a;
    char b;
    char c;
    char d;

    a = 0b11110000;
    b = 0b10011111;
    c = 0b10011000;
    d = 0b10000100;
    write(1, &a, 1);
    write(1, &b, 1);
    write(1, &c, 1);
    write(1, &d, 1);

    //printf("%s\n", s);
    //printf("%lc", 536);

    return 0;
}