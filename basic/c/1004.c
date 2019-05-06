#include<stdio.h>
#include<string.h>

int main(void)
{
        int n = 0; 
        int score = 0, max = 0, min = 100;
        char name[12], maxName[12], minName[12];
        char ID[12], maxID[12], minID[12];

        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
                scanf("%s %s %d", name, ID, &score);
                if (score >= max) {
                        max = score;
                        strcpy(maxName, name);
                        strcpy(maxID, ID);
                }
                if (score <= min) {
                        min = score;
                        strcpy(minName, name);
                        strcpy(minID, ID);
                }
        }
        printf("%s %s\n", maxName, maxID);
        printf("%s %s\n", minName, minID);

        return 0;
}
