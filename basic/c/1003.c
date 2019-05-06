#include<stdio.h>
#include<stdbool.h>

#define N 10

bool isRight(const char *str)
{
        int i = 0;
        int a = 0, b = 0, c = 0;
        bool p = false, t = false;

        while (str[i] != '\0') {
                switch (str[i]) {
                case 'P':
                        if (p) { 
                                return false;
                        } else {
                                p = true;
                        }
                        break;
                case 'A':
                        if (p && t) {
                                ++c;
                        } else if (p && !t) {
                                ++b;
                        } else if (!p) {
                                ++a;
                        }
                        break;
                case 'T':
                        if (!p || t) return false;
                        t = true;
                        break;
                default:
                        return false;
                }
                ++i;
        }

        if (p && t && b && a * b == c)
                return true;

        return false;
}

int main(void)
{
        int n = 0;
        char str[N][104];

        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
                scanf("%s", str[i]);
        for (int i = 0; i < n; ++i) {
                if (isRight(str[i]))
                        printf("YES\n");
                else
                        printf("NO\n");
        }

        return 0;
}
