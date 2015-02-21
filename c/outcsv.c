#include <stdio.h>

char *setvalue(char *p, char *field, int size)
{
    if (*p == '"') {
        while (*(++p) && *p != '\n' && (*p != '"' || *(++p) == '"'))
        {
            if (--size > 0) {
                *(field++) = *p;
            }
        }
    }

    for ( ; *p && *p != ',' && *p != '\n'; p++)
    {
        if (--size > 0) {
            *(field++) = *p;
        }
    }

    *field = '\0';
    return *p ? (p + 1) : p;
}

int main()
{
    char buf[256];
    char field[256];
    char *p;
    FILE *fp = NULL;
    FILE *wfp = NULL;

    if ((fp = fopen("test.csv", "r")) == NULL) { return 1; }
    if ((wfp = fopen("wtest.csv", "w")) == NULL) { return 1; }

    while (fgets(buf, sizeof(buf), fp))
    {
        for (p = buf; *p; )
        {
            p = setvalue(p, field, sizeof(field));
            printf(":%s", field);
            fputs(":", wfp);
            fputs(field, wfp);
        }
        puts("");
        fputs("\n", wfp);
    }
    fclose(fp);
    fclose(wfp);

    return 0;
}
