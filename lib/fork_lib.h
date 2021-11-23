#ifndef __FORK_LIB_H
#define __FORK_LIB_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>

int fork_exec(char *path);

#endif