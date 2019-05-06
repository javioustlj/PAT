#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define N 100004

int main(void)
{
        char brokenKey[44] = {0}, s[N] = {0}, output[N] = {0};
        int count = 0, shift = 0;

        gets(brokenKey);
        gets(s);
        if (NULL == strchr(brokenKey, '+'))
                shift = 1;
        for (int i = 0; s[i] != '\0'; ++i) {
                if (isupper(s[i])) {
                        if (NULL == strchr(brokenKey, s[i]) && shift == 1)
                                output[count++] = s[i];
                } else {
                        if (NULL == strchr(brokenKey, toupper(s[i])))
                                output[count++] = s[i];
                }        
        }
        puts(output);

        return 0;
}
