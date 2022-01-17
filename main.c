#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *getfield(char *line, int num)
{
    const char *tok;
    for (tok = strtok(line, ",");
         tok && *tok;
         tok = strtok(NULL, ",\n"))
    {
        if (!--num)
            return tok;
    }
    return NULL;
}

const int displaySeparator()
{
    return 0;
}

const int getlinelength(char *str)
{
    // char str[] = "ls -l";
    char **res = NULL;
    char *p = strtok(str, ",");
    int n_comma = 0, i;

    /* split string and append tokens to 'res' */

    while (p)
    {
        res = realloc(res, sizeof(char *) * ++n_comma);

        if (res == NULL)
            exit(-1); /* memory allocation failed */

        res[n_comma - 1] = p;

        p = strtok(NULL, ",");
    }

    /* realloc one extra element for the last NULL */

    res = realloc(res, sizeof(char *) * (n_comma + 1));
    res[n_comma] = 0;

    /* print the result */

    for (i = 0; i < (n_comma); ++i)
    {
        displaySeparator();
        printf("res[%d] = %s\n", i, res[i]);
    }

    /* free the memory allocated */

    free(res);

    /* return the length of the parsed line */
    return n_comma - 1;
}

int main()
{
    FILE *stream = fopen("./test.csv", "r");

    char line[1024];
    int maxSize[255];
    while (fgets(line, 1024, stream))
    {

        char *tmp = strdup(line);
        // printf("%d", strlen(tmp));
        // printf("Length of line %d : %d", &line, getlinelength(tmp));
        // printf("Field 3 would be %s\n", getfield(tmp, 3));
        // int currentLength = getlinelength(tmp);
        // for (int i = 0; i < currentLength; i++)
        // {
        //     printf("Field %d would be %s\n", i, getfield(tmp, i));
        // }

        // displaySeparator();

        // NOTE strtok clobbers tmp
        int currentLength = getlinelength(tmp);
        for (int i = 0; i < currentLength; i++)
        {
        }

        free(tmp);
    }
}