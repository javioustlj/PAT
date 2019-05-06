#include<stdio.h>
#include<ctype.h>

int main(void)
{
        int week = 0, hour = 0, minute = 0;
        char str[4][64] = {0};
        char weekName[8][4] = { "", "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

        for (int i = 0; i < 4; ++i)
                gets(str[i]);

        for (int i = 0; str[0][i] != '\0' && str[1][i] != '\0'; ++i) {
                if (str[0][i] == str[1][i]) {
                        if (week) {
                                if ('A' <= str[0][i] && str[0][i] <= 'N') {
                                        hour = str[0][i] - 'A' + 10;
                                        break;
                                } else if ('0' <= str[0][i] && str[0][i] <= '9') {
                                        hour = str[0][i] - '0';
                                        break;
                                }
                        } else {
                                if (str[0][i] >= 'A' && str[0][i] <= 'G') {
                                        week = str[0][i] - 'A' + 1;
                                }
                        }
                }
        }

        for (int i = 0; str[2][i] != '\0' && str[3][i] != '\0'; ++i) {
                if (str[2][i] == str[3][i] && isalpha(str[2][i])) {
                        minute = i;
                        break;
                }
        }
        printf("%s %02d:%02d\n", weekName[week], hour, minute);

        return 0;
}
