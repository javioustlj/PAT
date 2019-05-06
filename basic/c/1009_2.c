#include <stdio.h>
#include <string.h>

int main ()
{
        char str[84];
        char * pch;

        fgets(str, 81, stdin);
        pch = strtok (str," \n");
        while (pch != NULL)
        {
                printf ("%s\n",pch);
                pch = strtok (NULL, " \n");
        }
        
        return 0;
}
