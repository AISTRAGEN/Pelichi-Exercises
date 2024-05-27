#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <grp.h>
#include <pwd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
    printf("Аргументи:\n");

    for (int i = 0; i < argc; i++)
    {
        printf("%s ", argv[i]);
    }
    printf("\n");

    struct passwd *pwd;
    pwd = getpwuid(getuid());

    struct group *grp;
    grp = getgrgid(getgid());

    printf("Process ID (pid): %d\n", getpid());
    printf("Session ID (sid): %d\n", getpid());
    printf("Process group ID (pgid): %d\n", getpid());
    printf("Ancestor process ID (ppid): %d\n", getpid());
    printf("User name: %s\n", pwd->pw_name);
    printf("Group name: %s\n", grp->gr_name);
    
    return 0;
}
