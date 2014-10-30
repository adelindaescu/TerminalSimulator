#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main()
{
    int status;
    int pid;
    pid = fork();

    if (pid == 0) {
        execv("/bin/ls",  (char *[]){ "ls", "-a" , "/home/constantin", NULL});
    }
    else {
        waitpid(pid, &status, WUNTRACED);
        printf("Parent\n");
    }

    return 0;
}
