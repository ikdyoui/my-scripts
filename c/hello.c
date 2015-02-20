#include <stdio.h>
#include <string.h>

int main(void) {
    char a[6];
    char *b = "hoge";
    char *c = NULL;

    a[0] = 'h';
    a[1] = 'o';
    a[2] = 'g';
    a[3] = 'e';
    a[4] = 'e';
    a[5] = '\0';

    if (strcmp(a, b) == 0) {
        printf("%s\n", a);
    } else {
        printf("%s\n", b);
    }

    return 0;
}

