#include<stdio.h>
#include<stdbool.h>

#define N 10000

bool is_prime(int n)
{
        for (int i = 2; i < n / 2; ++i)
                if (!(n % i))
                        return false;
        return true;
}

int main(void)
{
        int n = 0, k = 0;
        int rank[N] = {0};
        int ID = 0;

        scanf("%d", &n);
        for (int i = 0; i < n; ++i){
                scanf("%d", &ID);
                rank[ID] = i + 1;
        }
        scanf("%d", &k);
        for (int i = 0; i < k; ++i){
                scanf("%d", &ID);
                printf("%04d: ", ID);
                if (!rank[ID])
                        printf("Are you kidding?\n");
                else if (rank[ID] == 1)
                        printf("Mystery Award\n");
                else if (rank[ID] == -1)
                        printf("Checked\n");
                else if (is_prime(rank[ID]))
                        printf("Minion\n");
                else
                        printf("Chocolate\n");
                if (rank[ID])
                        rank[ID] = -1;
        }

        return 0;
}
