#include<stdio.h>
#include<math.h>

int main(void)
{
        int n = 0, max = 0;
        int a = 0, b = 0;

        scanf("%d", &n);
        for (int i = 0; i < n; ++i){
                scanf("%d %d", &a, &b);
                if (a * a + b * b > max)
                        max = a * a + b * b;
        }
        printf("%.2f\n", sqrt(max));

        return 0;
}
