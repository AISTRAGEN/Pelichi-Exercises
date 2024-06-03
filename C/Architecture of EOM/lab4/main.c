#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <time.h>
#include "header.h"


int M = DEFAULT_M;
int T = DEFAULT_T;
int n = DEFAULT_N;
int w = DEFAULT_W;
int r1 = DEFAULT_R1;
int r2 = DEFAULT_R2;
int r3 = DEFAULT_R3;

sem_t registration_semaphore;
pthread_mutex_t voting_booth_mutex = PTHREAD_MUTEX_INITIALIZER;

int registered_voters = 0;
pthread_mutex_t registered_voters_mutex = PTHREAD_MUTEX_INITIALIZER;

int voted_voters = 0;
pthread_mutex_t voted_voters_mutex = PTHREAD_MUTEX_INITIALIZER;

time_t start_time;

void* voter(void* arg) 
{
    int voter_id = *(int*)arg;
    free(arg);

  
    sleep(rand() % r1 + 1);

    if (time(NULL) - start_time > T) 
    {
        printf("Виборець %d пішов, тому що час закінчився.\n", voter_id);
        return NULL;
    }

  
    printf("Виборець %d намагається зареєструватися.\n", voter_id);
    time_t registration_start_time = time(NULL);
    while (1) 
    {
        if (sem_trywait(&registration_semaphore) == 0) 
        {
            
            sleep(rand() % r2 + 1);
            pthread_mutex_lock(&registered_voters_mutex);
            registered_voters++;
            printf("Виборець %d успішно зареєстрований. (Загалом зареєстровано: %d)\n", voter_id, registered_voters);
            pthread_mutex_unlock(&registered_voters_mutex);
            sem_post(&registration_semaphore);
            break;
        } 
        else if (time(NULL) - registration_start_time > w) 
        {
            printf("Виборець %d пішов через довге очікування.\n", voter_id);
            return NULL;
        }
    }

   
    printf("Виборець %d чекає на кабінку для голосування.\n", voter_id);
    pthread_mutex_lock(&voting_booth_mutex);
   
    sleep(rand() % r3 + 1);
    pthread_mutex_lock(&voted_voters_mutex);
    voted_voters++;
    printf("Виборець %d успішно проголосував. (Загалом проголосувало: %d)\n", voter_id, voted_voters);
    pthread_mutex_unlock(&voted_voters_mutex);
    pthread_mutex_unlock(&voting_booth_mutex);

    return NULL;
}

int main(int argc, char* argv[]) 
{
    if (argc == 8) 
    {
        M = atoi(argv[1]);
        T = atoi(argv[2]);
        n = atoi(argv[3]);
        w = atoi(argv[4]);
        r1 = atoi(argv[5]);
        r2 = atoi(argv[6]);
        r3 = atoi(argv[7]);
    }

    srand(time(NULL));

   
    sem_init(&registration_semaphore, 0, n);

   
    start_time = time(NULL);

    
    pthread_t* voters_threads = malloc(M * sizeof(pthread_t));
    for (int voter_id = 1; voter_id <= M; voter_id++) 
    {
        int* id = malloc(sizeof(int));
        *id = voter_id;
        pthread_create(&voters_threads[voter_id - 1], NULL, voter, id);
    }

   
    for (int i = 0; i < M; i++) 
    {
        pthread_join(voters_threads[i], NULL);
    }

    
    free(voters_threads);
    sem_destroy(&registration_semaphore);

    printf("Вибори закінчилися. Загалом зареєстровано: %d, Загалом проголосувало: %d\n", registered_voters, voted_voters);
    return 0;
}
