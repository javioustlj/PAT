#include<stdio.h>

int main(void)
{
        int sum = 0, cnt = 0, a[4] = {0};
        char str[104] = {0};
        char numstr[10][8] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
        
        scanf("%s", str);
        for (int i = 0; str[i] != '\0'; ++i)
                sum += str[i] - '0'; 
        do {
                a[cnt++] = sum % 10;
        } while(sum /= 10);
        while (cnt--)
                printf("%s%c", numstr[a[cnt]], cnt ? ' ' : '\n'); 

        return 0;
}
