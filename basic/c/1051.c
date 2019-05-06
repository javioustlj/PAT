#include<stdio.h>
#include<math.h>

int main(void)
{
        double R1, R2, P1, P2;
        double A, B;

        scanf("%lf %lf %lf %lf", &R1, &P1, &R2, &P2);
        A = R1 * R2 * cos(P1 + P2);
        B = R1 * R2 * sin(P1 + P2);

        if (A > -0.005 && A < 0)
                printf("0.00");
        else
                printf("%.2f", A);

        if (B > -0.005 && B < 0)
                printf("+0.00i\n");
        else
                printf("%+.2fi\n", B);

        return 0;
}
