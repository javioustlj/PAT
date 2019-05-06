#include<stdio.h>

int main(void)
{
        char str[10000] = {0};

        scanf("%s", str);
        int index = 0, flag = 0, decimal = 0;
        for (int i = 4; str[i] != '\0'; ++i) {
                if (flag != 0) {
                        index = index * 10 + str[i] - '0';
                } else {
                        decimal++;
                }
                if (str[i] == '+')
                        flag = 1;
                if (str[i] == '-')
                        flag = -1;
        }
        decimal--;

        if (str[0] == '-')
                putchar(str[0]);
        if (index == 0) {
                for (int i = 0; str[i] != 'E'; ++i)
                        putchar(str[i]);
        } else {
                if (flag < 0) {
                        printf("0.");
                        for (int i = 1; i < index; ++i)
                                putchar('0');
                        putchar(str[1]);
                        for (int i = 3; str[i] != 'E'; ++i)
                                putchar(str[i]); 
                } else {
                        putchar(str[1]);
                        if (decimal == index) {
                                for (int i = 3; str[i] != 'E'; ++i)
                                        putchar(str[i]);
                        } else if (decimal > index) {
                                for (int i = 3; str[i] != 'E'; ++i) {
                                        putchar(str[i]);
                                        if (i == index + 2)
                                                putchar('.');
                                }
                        } else {
                                for (int i = 3; str[i] != 'E'; ++i)
                                        putchar(str[i]);
                                for (int i = 0; i < index - decimal; ++i)
                                        putchar('0');
                        }
                }
        }

        return 0;
}
