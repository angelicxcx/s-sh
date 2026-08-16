#include <unistd.h>

void cd(char** argv) {
    chdir(argv[1]);
}