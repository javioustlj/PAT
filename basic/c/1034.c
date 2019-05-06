#include<stdio.h>
#include<string.h>

int get_max_common_divisor(long long int a, long long int b)
{
        long long int r = 0;
        while (1){
                r = a % b;
                if (r)
                        a = b, b = r;
                else
                        return b;
        }
}

void print_num(long long int a, long long int b)
{
        int flag = 1;
        long long int k = 0; 
        long long int d = 0;

        if (!b){
                printf("Inf");
                return;
        }
        if (!a){
                putchar('0');
                return;
        }

        if (a < 0){
                flag = -1;
                a *= -1;
        }
        else
                flag = 1;

        d = get_max_common_divisor(a, b);
        a /= d;
        b /= d;
        k = a / b;
        a %= b;

        if (flag == 1){
                if (k){
                        if (a)
                                printf("%lld %lld/%lld", k, a, b);
                        else
                                printf("%lld", k);
                }
                else
                        printf("%lld/%lld", a, b);
        }
        else if (flag == -1){
                if (k){
                        if (a)
                                printf("(-%lld %lld/%lld)", k, a, b);
                        else
                                printf("(-%lld)", k);
                }
                else
                        printf("(-%lld/%lld)", a, b);
        }

        return;
}

int main(void)
{
        long long int a1, b1, a2, b2;
        long long int a[4];
        long long int b[4];
        char op[8] = "+-*/";

        scanf("%lld/%lld", &a1, &b1);
        scanf("%lld/%lld", &a2, &b2);

        //printf("%lld/%lld %lld/%lld\n", a1, b1, a2, b2);
        a[0] = a1 * b2 + a2 * b1;
        a[1] = a1 * b2 - a2 * b1;
        a[2] = a1 * a2;
        a[3] = a1 * b2;

        b[0] = b1 * b2;
        b[1] = b1 * b2;
        b[2] = b1 * b2;
        b[3] = b1 * a2;
        if (b[3] < 0){
                b[3] *= -1;
                a[3] *= -1;
        }

        for (int i = 0; i < 4; ++i) {
               print_num(a1, b1); 
               printf(" %c ", op[i]);
               print_num(a2, b2);
               printf(" = ");
               print_num(a[i], b[i]);
               putchar('\n');
        }

        return 0;
}
