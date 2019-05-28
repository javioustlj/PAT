#include<stdio.h>

struct student {
        char name[12];
        char ID[12];
        unsigned score;
};

int main(void)
{
        int n = 0;

        scanf("%d", &n);
        struct student stu[n];
        for (int i = 0; i < n; ++i)
                scanf("%s %s %d", stu[i].name, stu[i].ID, &stu[i].score);

        struct student *min = &stu[0], *max = &stu[0];
        for (int i = 0; i < n; ++i) {
                if (stu[i].score > max->score)
                        max = &stu[i];
                if (stu[i].score < min->score)
                        min = &stu[i];
        }

        printf("%s %s\n", max->name, max->ID);
        printf("%s %s\n", min->name, min->ID);

        return 0;
}
