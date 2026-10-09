
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[100];
    char *keywords[] = {
        "int", "float", "char", "if",
        "else", "while", "return"
    };
    int i, j, flag;

    printf("Enter an expression: ");
    fgets(str, sizeof(str), stdin);

    i = 0;

    while (str[i] != '\0') {
        if (isspace(str[i])) {
            i++;
        }
        else if (isalpha(str[i]) || str[i] == '_') {
            char word[30];
            j = 0;

            while (isalnum(str[i]) || str[i] == '_') {
                word[j++] = str[i++];
            }
            word[j] = '\0';

            flag = 0;
            for (j = 0; j < 7; j++) {
                if (strcmp(word, keywords[j]) == 0) {
                    flag = 1;
                    break;
                }
            }

            if (flag)
                printf("%s : Keyword\n", word);
            else
                printf("%s : Identifier\n", word);
        }
        else if (isdigit(str[i])) {
            char num[30];
            j = 0;

            while (isdigit(str[i])) {
                num[j++] = str[i++];
            }
            num[j] = '\0';

            printf("%s : Number\n", num);
        }
        else if (strchr("+-*/=%<>!", str[i])) {
            printf("%c : Operator\n", str[i]);
            i++;
        }
        else {
            printf("%c : Special Symbol\n", str[i]);
            i++;
        }
    }

    return 0;
}
