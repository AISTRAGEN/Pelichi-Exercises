#ifndef HEADER_H
#define HEADER_H

#include <pthread.h>
#include <semaphore.h>


#define DEFAULT_M 50
#define DEFAULT_T 60
#define DEFAULT_N 5
#define DEFAULT_W 10
#define DEFAULT_R1 3
#define DEFAULT_R2 2
#define DEFAULT_R3 1


extern int M;  
extern int T;  
extern int n;  
extern int w;  
extern int r1; 
extern int r2; 
extern int r3; 

extern sem_t registration_semaphore;


extern pthread_mutex_t voting_booth_mutex;


extern int registered_voters;
extern pthread_mutex_t registered_voters_mutex;


extern int voted_voters;
extern pthread_mutex_t voted_voters_mutex;


extern time_t start_time;


void* voter(void* arg);

#endif // HEADER_H
