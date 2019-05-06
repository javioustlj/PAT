#include<stdio.h>

#define MIN(A, B) (((A) > (B)) ? (B) : (A))
#define MAX(A, B) (((A) > (B)) ? (A) : (B))

int get_max_common_divisor(int a, int b)
{
        while (1){
                int r = a % b;
                if (r)
                        a = b, b = r;
                else
                        return b;
        }
}

int main(void)
{
        int n1, n2, m1, m2, k;
        int multiple = 0;
        int divisor = 0;
        int a, b;
        int flag = 0;

        scanf("%d/%d %d/%d %d", &n1, &m1, &n2, &m2, &k);

        divisor = get_max_common_divisor(m1, m2);
        multiple = m1 * m2 / divisor;
        divisor = get_max_common_divisor(multiple, k);
        multiple = multiple * k / divisor;

        a = MIN(multiple / m1 * n1, multiple / m2 * n2);
        b = MAX(multiple / m1 * n1, multiple / m2 * n2);
        
        for (int i = a + 1; i < b; ++i)
                if (i % (multiple / k ) == 0 && 1 == get_max_common_divisor(i / (multiple / k), k)){
                        if (flag)
                                printf(" %d/%d", i / (multiple / k), k);
                        else{
                                printf("%d/%d", i / (multiple / k), k);
                                flag = 1;
                        }
                }

        putchar('\n');

        return 0;
}
