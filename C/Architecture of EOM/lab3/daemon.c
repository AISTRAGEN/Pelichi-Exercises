#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
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
            break;
    }
}

int main() 
{

    pid_t pid = fork();

    if (pid < 0) {
        printf("Помилка при створенні процесу");
        exit(-1);
    } 
    
    if (pid != 0) 
    {
        printf("Демон запущений з PID: %d\n", pid);
        exit(0);
    }
    setsid();
  
    chdir("/");

 
    struct rlimit flim;
    getrlimit(RLIMIT_NOFILE, &flim);
    for (int fd = 0; fd < flim.rlim_max; fd++) 
    {
        close(fd);
    }


    openlog("my_daemon", LOG_PID, LOG_DAEMON);

  
    syslog(LOG_NOTICE, "Демон запущено, очікування сигналу:");

    signal(SIGUSR1, user_input);
    signal(SIGINT, user_input);


    kill(pid, SIGUSR1);
    kill(pid, SIGINT);

    return 0;
}
