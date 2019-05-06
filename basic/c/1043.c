#include<stdio.h>

#define N 10004

int main(void)
{
        char str[N] = {0};
        char a[6] = {'P', 'A', 'T', 'e', 's', 't'};
        int count[6] = {0};

        scanf("%s", str);
        for (int i = 0; str[i] != '\0'; ++i){
                switch (str[i]){
                        case 'P':
                                ++count[0];
                                break;
                        case 'A':
                                ++count[1];
                                break;
                        case 'T':
                                ++count[2];
                                break;
                        case 'e':
                                ++count[3];
                                break;
                        case 's':
                                ++count[4];
                                break;
                        case 't':
                                ++count[5];
                                break;
                        default:
                                break;
                }
        }
        while(count[0] || count[1] || count[2] || count[3] || count[4] || count[5]){
                for (int i = 0; i < 6; ++i){
                        if (count[i] > 0){
                                putchar(a[i]);
                                --count[i];
                        }
                }
        }

        putchar('\n');
        return 0;
}

