#ifndef PIPEX_H
# define PIPEX_H
# define NULL ((void *)0)

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int pipe(int fd);
int execve(const char *pathname, char *const argv[], char *const envp[]);
pid_t   fork();

#endif