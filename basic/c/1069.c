#include<stdio.h>
#include<string.h>
#include<stdbool.h>

#define M 1000

int main(void)
{
        int m = 0, n = 0, s = 0;
        int num = 0;//中奖人数
        bool exist = false;
        char list[M][21] = {0};
        char name[21] = {0};

        scanf("%d %d %d", &m, &n, &s);

        for (int i = 1; i < m + 1; ++i){
                scanf("%s", name);
                if (i >= s && !((i - s) % n)){
                        exist = false;
                        for (int i = 0; i < num; ++i)
                                if (!strcmp(name, list[i]))
                                        exist = true;
                        if (exist)
                                s = i + 1;
                        else 
                                strcpy(list[num++], name);
                }
        }

        if (num > 0)
                for (int i = 0; i < num; ++i)
                        printf("%s\n", list[i]);
        else
                printf("Keep going...\n");

        return 0;
}
