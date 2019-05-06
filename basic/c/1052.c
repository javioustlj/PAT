#include<stdio.h>

int main(void)
{
        char symbol[3][10][32];
        int count[3] = {0};
        char c;
        int K = 0;
        int left_hand = 0, left_eye = 0, mouth = 0, right_eye = 0, right_hand = 0;

        for (int i = 0; i < 3; ++i){
                int j = 0, k = 0, flag = 0;
                while ((c = getchar()) != '\n'){
                        if (c == '[')
                                flag = 1;
                        else if (c == ']'){
                                symbol[i][j][k++] = '\0';
                                flag = 0;
                                ++j;
                                k = 0;
                        }
                        else {
                                if (flag)
                                        symbol[i][j][k++] = c;
                        }
                }
                count[i] = j;
        }
        /*
        for (int i = 0; i < 3; ++i){
                for (int j = 0; j < count[i]; ++j)
                        printf("[%s] ", symbol[i][j]);
                printf("\n");
        }
        */
        scanf("%d", &K);
        for (int i = 0; i < K; ++i){
                scanf("%d %d %d %d %d", &left_hand, &left_eye, &mouth, &right_eye, &right_hand);
                if (left_hand <= 0 || left_eye <= 0 || mouth <= 0 || right_eye <= 0 || right_hand <= 0)
                        printf("Are you kidding me? @\\/@\n");
                else if (left_hand > count[0] || right_hand > count[0] ||
                                left_eye > count[1] || right_eye > count[1] ||
                                mouth > count[2])
                        printf("Are you kidding me? @\\/@\n");
                else
                        printf("%s(%s%s%s)%s\n", symbol[0][left_hand - 1], symbol[1][left_eye - 1], symbol[2][mouth - 1], symbol[1][right_eye - 1], symbol[0][right_hand - 1]);
        }

        return 0;
}

