#include<stdio.h>
#include<string.h>

#define N 100

char a[13][5] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
char b[13][4] = {"", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

void earth_to_mars(int num, char *str)
{
        int tens = 0;
        int ones = 0;

        tens = num / 13;
        ones = num % 13;
        if (!tens)
                sprintf(str, "%s", a[ones]);
        else{
                if (ones)
                        sprintf(str, "%s %s", b[tens], a[ones]);
                else
                        sprintf(str, "%s", b[tens]);
        }

        return;
}

void mars_to_earth(char *str1, char *str2, char *out)
{
        int ans = 0;
        int tens = 0;
        if (strlen(str1)){
                for (int i = 0; i < 13; ++i)
                        if (!strcmp(str1, b[i])){
                                ans += 13 * i;
                                goto str2not0;
                        }
                for (int i = 0; i < 13; ++i)
                        if (!strcmp(str1, a[i])){
                                ans += i;
                                goto str2is0;
                        }
        }
str2not0:
        if (strlen(str2))
                for (int i = 0; i < 13; ++i)
                        if (!strcmp(str2, a[i])){
                                ans += i;
                                break;
                        }
str2is0:
        sprintf(out, "%d", ans);
        
        return;
}
int main(void)
{
        int n = 0;
        char ans[N][16];
        char str1[8];
        char str2[8];

        scanf("%d", &n);
        for (int i = 0; i < n; ++i){
                str1[0] = '\0';
                str2[0] = '\0';
                scanf("%s", str1);
                if (getchar() != '\n')
                        scanf("%s", str2);
                if (isdigit(str1[0]))
                        earth_to_mars(atoi(str1), ans[i]);
                else
                        mars_to_earth(str1, str2, ans[i]);
        }

        for (int i = 0; i < n; ++i)
                printf("%s\n", ans[i]);
        /*
        for (int i = 0; i < n; ++i)
                printf("%s\n", ans[i]);
                */

        return 0;
}
