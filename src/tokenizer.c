#include <string.h>

void tokenize(char *string, char *argv[], int max_tokens) {
    int count = 0;
    int i = 0;
    while (string[i] != '\0' && count < max_tokens - 1) {
        while (string[i] == ' ') i++;
        if (string[i] == '\0') break;
        argv[count] = &string[i];
        count++;
        while (string[i] != '\0' && string[i] != ' ') i++;
        if (string[i] == ' ') {
            string[i] = '\0';
            i++;
        }
        if (string[i] == '\n'){string[i] = '\0';}
    }
    argv[count] = NULL;
}