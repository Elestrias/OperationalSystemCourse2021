#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

char **comand_taker() {
    char *x = NULL;
    size_t n = 0;
    int flag = 1;
    int sizer = 0, counter = 0;
    getline(&x, &n, stdin);
    char **a = (char **) malloc(sizeof(char *));
    a[0] = (char *) malloc(sizeof(char) * 256);
    int firstWord = 0;
    for (int i = 0; i < strlen(x); i++) {
        if (firstWord == 1 && x[i] == ' ' && flag == 1 && i + 1 < strlen(x) && x[i + 1] != ' ' && x[i + 1] != '\n' && x[i + 1] != EOF) {
            counter = 0;
            sizer++;
            flag = 0;
            a = realloc(a, sizeof(char *) * sizer);
            a[sizer] = (char *) malloc(sizeof(char) * 256);
        } else {
            if (x[i] != '\n' && x[i] != EOF && x[i] != ' ') {
                firstWord = 1;
                flag = 1;
                a[sizer][counter] = x[i];
                a[sizer][counter + 1] = '\0';
                counter++;
            }
        }
    }
    a = realloc(a, sizeof(char *) * (sizer + 1));
    a[sizer + 1] = NULL;
    return a;
}


int main() {
    char **argv = comand_taker();
    int pid = fork();
    if (pid == 0) {
        execvp(argv[0], argv);
        return 0;
    }
    else waitpid(pid, NULL, 0);
    return 0;
}
