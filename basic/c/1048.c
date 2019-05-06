#include<stdio.h>
#include<string.h>

void reverse(char *str)
{
        int len = strlen(str);
        for (int i = 0; i < len / 2; ++i)
                str[i] ^= str[len - 1 - i] ^= str[i] ^= str[len - 1 - i];
        
        return;
}

void fill0(char *str1, char *str2)
{
        int len1 = strlen(str1);
        int len2 = strlen(str2);

        if (len1 < len2){
                for (int i = len1; i < len2; ++i)
                       str1[i] = '0';
                str1[len2] = '\0';
        }
        else if (len1 > len2){
               for (int i = len2; i < len1; ++i)
                      str2[i] = '0';
               str2[len1] = '\0';
        }

       return;
} 
        
int main(void)
{
        char A[104] = {0};
        char B[104] = {0};
        int bit = 0, flag = 0;

        scanf("%s %s", A, B);
        reverse(A);
        reverse(B);
        fill0(A, B);
        flag = 1;
        for(int i = 0; i < strlen(B); ++i){
                if (flag){
                        bit = B[i] - '0' + A[i] - '0';
                        bit %= 13;
                        switch (bit){
                                case 10:
                                        B[i] = 'J';
                                        break;
                                case 11:
                                        B[i] = 'Q';
                                        break;
                                case 12:
                                        B[i] = 'K';
                                        break;
                                default:
                                        B[i] = bit + '0';
                                        break;
                        }
                        flag = 0;
                }
                else {
                        bit = (B[i] - A[i] + 10) % 10;
                        B[i] = bit + '0';
                        flag = 1;
                }
        }
        
        reverse(B);
        printf("%s", B);
        return 0;
}        
