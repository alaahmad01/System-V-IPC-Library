#include "fork_lib.h"

/*
 * Fork and Execute process with one argument
 * */
int fork_exec (char *path) {
    int cid;
    switch (cid = fork()) {
        case -1:
            perror("fork_exec fork");
            exit(-1);
        case 0:  // child process
            if (execlp(path, path, (void *) NULL) == -1) {
                perror("fork_exec execlp");
                exit(-2);
            }
            break;
        default:  // parent
            break;
    }
    return cid;
}