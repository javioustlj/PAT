#include<stdio.h>
#include<string.h>

int main(void)
{
        int n = 0, i = 0;
        char correct_password[21];
        char password[1000];

        scanf("%s %d", correct_password, &n);
        getchar();
        gets(password);

        while (strcmp("#", password)){
                if (strcmp(password, correct_password))
                        printf("Wrong password: %s\n", password);
                else {
                        printf("Welcome in\n");
                        return 0;
                }
                if (++i >= n){
                        printf("Account locked\n");
                        break;
                }
                gets(password);
        }

        /*
        for (i = 0; i < n; ++i){
                scanf("%s", password);
                if (!strcmp("#", password))
                        break;
                if (strcmp(password, correct_password))
                        printf("Wrong password: %s\n", password);
                else {
                        printf("Welcome in\n");
                        return 0;
                }
        }

        if (i = n)
                printf("Account locked");
        */

        return 0;
}
