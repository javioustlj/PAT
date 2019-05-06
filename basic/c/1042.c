#include<stdio.h>

#define N 1004
int main(void)
{
        char str[N] = {0};
        int count[26] = {0};
        int index = 0, max = 0;

        gets(str);

        for (int i = 0; str[i] != '\0'; ++i){
                if (isupper(str[i]))
                        ++count[str[i] - 'A'];
                else if (islower(str[i]))
                        ++count[str[i] - 'a'];
        }

        for (int i = 0; i < 26; ++i) 
                if (max < count[i]){
                        max = count[i];
                        index = i;
                }

        printf("%c %d\n", 'a' + index, max);
        
        return 0;
}
