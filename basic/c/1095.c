#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 10000
#define M 100

typedef struct student {
        char num[16];
        int score;
        int level;
        int room_num;
        int date;
}student;

typedef struct request {
        int type;
        char content[8];
}request;

typedef struct room_node {
        int num;
        int cnt;
}room_node;

student stu[N];
int n;

int compare_stu(const void *a, const void *b)
{
        student *stu_a = (student *)a, *stu_b = (student *)b;
        
        if (stu_b->score - stu_a->score)
                return stu_b->score - stu_a->score;
        else 
                return strcmp( stu_a->num, stu_b->num);
}

void handle_type1_request(char *content)
{
        student temp[N] = {0};
        int cnt = 0, level = content[0];

        for (int i = 0; i < n; ++i)
                if (stu[i].level == level)
                        temp[cnt++] = stu[i];
        qsort(temp, cnt, sizeof(student), compare_stu);
        for (int i = 0; i < cnt; ++i)
                printf("%s %d\n", temp[i].num, temp[i].score);
        if (!cnt)
                puts("NA");
}

void handle_type2_request(char *content)
{
        int sum = 0, cnt = 0, room_num = atoi(content);

        for (int i = 0; i < n; ++i) {
                if (room_num == stu[i].room_num) {
                        ++cnt;
                        sum += stu[i].score;
                }
        }

        if (!cnt) {
                puts("NA");
                return;
        }
        printf("%d %d\n", cnt, sum);
}

int compare_room(const void *a, const void *b)
{
        room_node *room_a = (room_node *)a, *room_b = (room_node *)b;
        if (room_b->cnt - room_a->cnt)
                return room_b->cnt - room_a->cnt;
        else
                return room_a->num - room_b->num;
}

void handle_type3_request(char *content)
{
        int cnt = 0, date = atoi(content);
        room_node room[1000] = {0};

        for (int i = 0; i < 1000; ++i)
                room[i].num = i;

        for (int i = 0; i < n; ++i) {
                if (stu[i].date == date) {
                        ++room[stu[i].room_num].cnt;
                        ++cnt;
                }
        }
        qsort(room, 1000, sizeof(room_node), compare_room);

        if (!cnt) {
                puts("NA");
                return;
        }
        for (int i = 0; i < 900; ++i)
                if (room[i].cnt)
                        printf("%d %d\n", room[i].num, room[i].cnt);

}

void handle_request(request req)
{
        switch (req.type) {
        case 1:
                handle_type1_request(req.content);
                break;
        case 2:
                handle_type2_request(req.content);
                break;
        case 3:
                handle_type3_request(req.content);
                break;
        default:
                break;
        }
}

int main(void)
{
        int m = 0;
        request req[M] = {0};
        char room_num[4] = {0}, date[8] = {0};

        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; ++i)
                scanf("%s %d", stu[i].num, &stu[i].score);
        for (int i = 0; i < m; ++i)
                scanf("%d %s", &req[i].type, req[i].content);

        for (int i = 0; i < n; ++i) {
                stu[i].level = stu[i].num[0];
                strncpy(room_num, &stu[i].num[1], 3);
                strncpy(date, &stu[i].num[4], 6);
                stu[i].room_num = atoi(room_num);
                stu[i].date = atoi(date);
        }

        for (int i = 0; i < m; ++i) {
                printf("Case %d: %d %s\n", i + 1, req[i].type, req[i].content);
                handle_request(req[i]);
        }

        return 0;
}
