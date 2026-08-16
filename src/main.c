#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <wait.h>


void tokenize(char *string, char *argv[], int max_tokens);
void cd(char** argv);


void handler() {
    char prompt[15000];
    char *username = getenv("USER");
    char* argv[150];
    int pid = 0;
    while (1) {
        char PATH[150];
        getcwd(PATH, sizeof(PATH));
        printf("%s | %s>", username, PATH);
        fgets(prompt, 15000, stdin);
        prompt[strcspn(prompt, "\n")] = '\0';
        tokenize(prompt, argv, 150);
        fflush(stdout);
        if(argv[0] == NULL) {continue;}
        if (strcmp(argv[0], "pwd") == 0) {
            printf("%s\n", PATH); continue;
        }
        if (strcmp(argv[0], "exit") == 0) {exit(0);}
        if (strcmp(argv[0], "cd") == 0) {cd(argv); continue;}
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