#include<stdio.h>
#include<stdbool.h>

#define N 100

bool isLegal(char *str)
{
        int sum = 0;
        char M[12] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
        int weight[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};

        for (int i = 0; i < 17; ++i) {
                if (str[i] >= '0' && str[i] <= '9') {
                        sum += (str[i] - '0') * weight[i];
                } else {
                        return false;
                }
        }

        if (M[sum % 11] == str[17])
                return true;

        return false;
}

int main(void)
{
        int n = 0, count = 0;
        char ID[N][20] = {0};

        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
                scanf("%s", ID[i]);

        for (int i = 0; i < n; ++i) {
                if (!isLegal(ID[i])) { 
                        printf("%s\n", ID[i]);
                        ++count;
                }
        }

        if (!count) {
                printf("All passed\n");
        }
        
        return 0;
}
