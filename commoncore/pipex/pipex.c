#include "pipex.h"

int main(void)
{
    pid_t pid;
    int fd[2];
    const char *pathname;
    char *const *argv;
    char *const env;

    pipe(fd);
    pid = fork();

    if (fork() == 0)
    {
        dup2(fd[1], STDOUT_FILENO);
        close(fd[0]);
        close(fd[1]);
        argv = {"ls", "-l", NULL};
        execve("/bin/ls", argv, )
    }

    return (0);
}
