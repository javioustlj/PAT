#include<stdio.h>
#include<stdbool.h>
//将输入作为字符串处理更简单
#define YEAR        2014
#define MONTH       9
#define DAY         6

typedef struct people {
        char name[8];
        int year;
        int month;
        int day;
}person;

bool isLegal(person *p)
{
        if (YEAR - 200 < p->year && p->year < YEAR) {
                return true;
        } else if (p->year == YEAR - 200) {
                if (p->month > MONTH) {
                        return true;
                } else if (p->month == MONTH) {
                        return p->day >= DAY;
                } else {
                        return false;
                }
        } else if (p->year == YEAR) {
                if (p->month < MONTH) {
                        return true;
                } else if (p->month == MONTH) {
                        return p->day <= DAY;
                } else {
                        return false;
                }
        } else {
                return false;
        }
}

int compare(person *a, person *b)
{
        if (a->year != b->year) {
                return a->year - b->year;
        } else if (a->month != b->month) {
                return a->month - b->month;
        } else if (a->day != b->day) {
                return a->day - b->day;
        } else {
                return 0;
        }
}

int main(void)
{
        person old = {"", 2004, 9, 6}, young = {"", 1804, 9, 6}, p = {0};
        int count = 0, n = 0;
        
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
                scanf("%s", p.name);
                scanf("%d/%d/%d", &p.year, &p.month, &p.day);
                if (isLegal(&p)) {
                        ++count;
                        if (compare(&p, &old) <= 0) {
                                old = p;
                        } 

                        if (compare(&p, &young) >= 0) {
                                young = p;
                        }
                }
        }
        
        if (count) {
                printf("%d %s %s\n", count, old.name, young.name);
        } else {
                printf("%d\n", count);
        }

        return 0;
}
