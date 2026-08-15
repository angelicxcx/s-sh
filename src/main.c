#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <wait.h>


int tokenize(char *string, char *argv[], int max_tokens);

void handler() {
    char prompt[15000];
    char *username = getenv("USER");
    char* argv[150];
    int pid = 0;
    while (1) {
        printf("%s>", username);
        fgets(prompt, 15000, stdin);
        prompt[strcspn(prompt, "\n")] = '\0';
        tokenize(prompt, argv, 150);
        pid = fork();
        if (pid == 0) {
            execvp(argv[0], argv);
        } else {
            wait(NULL);
        }
    }
}

int main() {
    handler();
}