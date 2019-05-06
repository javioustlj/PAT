#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(void)
{
        int index = 0, k = 0;
        char str[84];
        char output[84];

        fgets(str, 81, stdin);
        index = strlen(str);
        for (int i = strlen(str) - 1; i >= 0; --i) {
                if (str[i] == '\n') {
                        index = i;
                        continue;
                }
                if (isspace(str[i])) {
                        for (int j = i + 1; j < index; ++j) {
                                output[k++] = str[j];
                        }
                        output[k++] = str[i];
                        index = i;
                }
                if (!i) {
                        for (int j = 0; j < index; ++j) {
                                output[k++] = str[j];
                        }
                        output[k++] = '\0';
                }
        }
        printf("%s\n", output);

        return 0;
}
