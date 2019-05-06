#include<stdio.h>
#include<ctype.h>
#include<stdbool.h>

#define N 100

bool get_double(char *str, double *res)
{
        int sign = 1;
        int count_after = 0;
        int count_before = 0;
        int before = 0, after = 0;
        int flag = 0;
        int divisor[3] = {1, 10, 100};

        for (int i = 0; str[i] != '\0'; ++i){
                if (isdigit(str[i]) || str[i] == '-' || str[i] == '.'){
                        if (str[i] == '-'){
                                if (i == 0)
                                        sign = -1;
                                else
                                        return false;
                        }
                        else if (str[i] == '.'){
                                if (flag)
                                        return false;
                                if (i > 0)
                                        flag = 1;
                                else
                                        return false;
                        }
                        else{
                                if (flag){
                                        ++count_after;
                                        if (count_after > 2)
                                                return false;
                                        after = after * 10 + str[i] - '0';
                                }
                                else {
                                        ++count_before;
                                        before = before * 10 + str[i] - '0';
                                        if (before > 1000)
                                                return false;
                                }
                        }
                                
                }
                else
                        return false;
        }
        if (count_before < 1)
                return false;
        if (before == 1000 && after != 0)
                return false;
        *res = sign * (before + (double)after / divisor[count_after]);

        return true;
}
int main(void)
{
        int n = 0;
        char input[N][100]; // 注意input字符串大小，当取为32时，测试通过不了
        double d = 0;
        double sum = 0;
        int count = 0;

        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
                scanf("%s", input[i]);

        for (int i = 0; i < n; ++i){
                if (get_double(input[i] ,&d)){
                        sum += d;
                        ++count;
                }
                else {
                        printf("ERROR: %s is not a legal number\n", input[i]);
                }
        }

        if (count == 1) 
                printf("The average of 1 number is %.2f\n", sum);
        else if (count > 1)
                printf("The average of %d numbers is %.2f\n", count, sum / count);// numbers instead of number
        else
                printf("The average of 0 numbers is Undefined\n");

        return 0;
}
