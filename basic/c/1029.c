#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main(void)
{
        char s1[84] = {0}, s2[84] = {0}, output[84] = {0};
        int count = 0;
        char *p1 = &s1[0], *p2 = &s2[0];

        scanf("%s", s1);
        scanf("%s", s2);

        while (*p1 != '\0') {
                if (*p1 == *p2) {
                        p1++;
                        p2++;
                } else {
                        if (NULL != strchr(output, toupper(*p1))) {
                                p1++;
                        } else {
                                output[count++] = toupper(*p1);
                        }
                }
        }
        puts(output);

        return 0;
}
