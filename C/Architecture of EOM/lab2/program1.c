#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

void synchronous_execution(const char *executable) 
{
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(1);
    } else if (pid == 0) { // Child process
        execlp(executable, executable, NULL);
        perror("execlp");
        exit(1);
    } else { // Parent process
        int status;
        waitpid(pid, &status, 0);
        printf("Child process %s terminated with status %d\n", executable, WEXITSTATUS(status));
    }
}

void asynchronous_execution(const char *executable) 
{
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(1);
    } else if (pid == 0) { // Child process
        execlp(executable, executable, NULL);
        perror("execlp");
        exit(1);
    } else { // Parent process
        printf("Child process %s is running asynchronously\n", executable);
    }
}

int main(int argc, char *argv[]) 
{
    if (argc != 3 || (strcmp(argv[1], "-w") != 0 && strcmp(argv[1], "-f") != 0)) 
    {
        printf("Usage: %s -w executable_name or %s -f executable_name\n", argv[0], argv[0]);
        return 1;
    }

    char *executable = argv[2];

    if (strcmp(argv[1], "-w") == 0) 
    {
        synchronous_execution(executable);
    } else {
        asynchronous_execution(executable);
    }

    return 0;
}
