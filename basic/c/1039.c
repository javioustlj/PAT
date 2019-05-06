#include<stdio.h>

#define N 1004

void count(char *str, int count[62])
{
        for (int i = 0; str[i] != '\0'; ++i){
                if (isdigit(str[i]))
                        ++count[str[i] - '0'];
                else if (islower(str[i]))
                        ++count[str[i] - 'a' + 10];
                else if (isupper(str[i]))
                        ++count[str[i] - 'A' + 36];
        }

        return;
}

int main(void)
{
        char a[N] = {0};
        char b[N] = {0};
        int count_a[62] = {0};
        int count_b[62] = {0};
        int more = 0, less = 0;
        int flag = 1;

        scanf("%s", a);
        scanf("%s", b);
        
        count(a, count_a);
        count(b, count_b);

        for (int i = 0; i < 62; ++i){
                if (count_b[i] > count_a[i]){
                        less += count_b[i] - count_a[i];
                        flag = 0;
                }
                else 
                        more += count_a[i] - count_b[i];
        }
        
        if (flag)
                printf("Yes %d\n", more);
        else
                printf("No %d\n", less);

        return 0;
}
