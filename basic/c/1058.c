#include<stdio.h>
#include<string.h>

#define M 100
#define N 1000

typedef struct question{
        int score; //分数
        int option_num; //选项个数
        int right_option_num; //正确选项个数
        int flag[5]; //正确选项标志
        int err_cnt; //每个选项错误次数
}question;
typedef enum status{
        wrong,
        correct,
        missing
}status;

int main(void)
{
        int n = 0, m = 0;
        int num = 0;
        char c = 0;
        status ans = correct;
        int option_flag[5] = {0};
        int score[N] = {0};
        char stu[1600] = {0};
        question que[M] = {0};
        int max_err_cnt = 0;
        int count = 0;

        scanf("%d %d", &n, &m);
        for (int i = 0; i < m; ++i){
                scanf("%d %d %d", &que[i].score, &que[i].option_num, &que[i].right_option_num);
                for (int j = 0; j < que[i].right_option_num; ++j){
                        scanf("%c", &c);
                        if ( (c = getchar()) != ' ')
                                que[i].flag[c - 'a'] = 1;
                }
        }
       
        getchar();
        for (int j = 0; j < n; ++j){
                memset(stu, 0, sizeof(stu));
                gets(stu);
                num = -1;
                for (int i = 0; stu[i] != '\0'; ++i){
                        switch (stu[i]){
                                case '(':
                                        ++num;
                                        memset(option_flag, 0, sizeof(option_flag));
                                        break;
                                case 'a':
                                case 'b':
                                case 'c':
                                case 'd':
                                case 'e':
                                        option_flag[stu[i] - 'a'] = 1;
                                        break;
                                case ')':
                                       ans = correct;
                                        for (int i = 0; i < que[num].option_num; ++i){
                                                if (option_flag[i] != que[num].flag[i]){
                                                        ans = wrong;
                                                        ++que[num].err_cnt;
                                                        break;
                                                }
                                        }
                                        if (ans)
                                                score[j] += que[num].score;
                                        break;
                                default:
                                        break;
                        }
                }
        }
        for (int i = 0; i < n; ++i)
                printf("%d\n", score[i]);
        for (int i = 0; i < m; ++i)
                if (max_err_cnt < que[i].err_cnt){
                                max_err_cnt = que[i].err_cnt;
                                ++count;
                }
        if (!max_err_cnt)
                printf("Too simple\n");
        else{
                printf("%d", max_err_cnt);
                for (int i = 0; i < m; ++i)
                        if (max_err_cnt == que[i].err_cnt)
                                printf(" %d", i + 1);
        }
    return 0;
}
