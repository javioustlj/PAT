#include<stdio.h>

int main(void)
{
        int n = 0; 
        double sum = 0;
        double a = 0;

        scanf("%d", &n);

        for (int i = 1; i < n + 1; ++i){
                scanf("%lf", &a);
                sum += i * a * (n + 1 - i);//若写成sum += i * (n + 1 - i) *a则有连个测试点不通过
        }

        printf("%.2f\n", sum);

        return 0;
}
