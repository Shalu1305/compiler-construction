#include <stdio.h>
#include <string.h>

int main() {
    char macro[100], statement[100];

    printf("Enter macro definition: ");
    fgets(macro, sizeof(macro), stdin);

    printf("Enter statement to expand: ");
    fgets(statement, sizeof(statement), stdin);

    printf("\nMacro Definition: %s", macro);
    printf("Before Expansion: %s", statement);

    if (strstr(statement, "SQUARE") != NULL) {
        char *pos = strstr(statement, "SQUARE");
        char result[200] = "";
        char *arg = strchr(pos, '(');

        if (arg != NULL) {
            char variable = arg[1];
            snprintf(result, sizeof(result),
                     "Expanded Statement: %c * %c\n",
                     variable, variable);
            printf("%s", result);
        } else {
            printf("Macro argument not found.\n");
        }
    } else {
        printf("No macro found.\n");
    }

    return 0;
}
