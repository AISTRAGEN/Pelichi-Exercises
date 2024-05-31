#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <syslog.h>
#include <sys/types.h>
#include <sys/resource.h>
#include <sys/stat.h>

void user_input(int signum) 
{
    switch (signum) 
    {
        case SIGUSR1: 
            syslog(LOG_NOTICE, "Отримано сигнал SIGUSR1\n");
            break;
        case SIGINT: 
            syslog(LOG_NOTICE, "Отримано сигнал SIGINT, демон завершений\n");
            closelog();
            exit(0);
            break;
    }
}

int main() 
{
    pid_t pid = fork();

    if (pid < 0) 
    {
        printf("Помилка при створенні процесу\n");
        exit(-1);
    } 
    
    if (pid != 0) 
    {
        printf("Демон запущений з PID: %d\n", pid);
        exit(0);
    }

    setsid();
    chdir("/");
 
    struct rlimit file_limits;
    getrlimit(RLIMIT_NOFILE, &file_limits);
    for (int fd = 0; fd < file_limits.rlim_max; fd++) 
    {
        close(fd);
    }

    openlog("my_daemon", LOG_PID, LOG_DAEMON);
    syslog(LOG_NOTICE, "Демон запущено, очікування сигналу:");

    signal(SIGUSR1, user_input);
    signal(SIGINT, user_input);

    while (1) {
        sleep(1);
    }

    return 0;
}
