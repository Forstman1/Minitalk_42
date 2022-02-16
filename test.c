#include <stdio.h>
#include <unistd.h>
#include <string.h>


int main()
{
    char *s;
    long c;

    c = 128516;
    s = strdup("\x263a");
    write(1, &c, 4);
    write(1, "😄", 4);
    //printf("%s\n", s);
    //printf("%lc", 536);

    return 0;
}