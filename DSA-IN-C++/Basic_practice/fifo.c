// Dining Philosophers (mutex forks, odd-even solution)
// dining_philosophers.c
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#define N 5
pthread_mutex_t forks[N];
void *philosopher(void *num){
    int id = *((int*)num);
    int left = id;
    int right = (id+1)%N;
    for(int i=0;i<3;i++){
        printf("Philosopher %d is thinking.\n", id);
        usleep(100000 + (rand()%200000));
        // odd-even solution to avoid deadlock
        if (id % 2 == 0) {
            pthread_mutex_lock(&forks[left]);
            pthread_mutex_lock(&forks[right]);
        } else {
            pthread_mutex_lock(&forks[right]);
            pthread_mutex_lock(&forks[left]);
        }
        printf("Philosopher %d is eating.\n", id);
        usleep(150000 + (rand()%200000));
        pthread_mutex_unlock(&forks[left]);
        pthread_mutex_unlock(&forks[right]);
    }
    printf("Philosopher %d done.\n", id);
    return NULL;
}
int main(){
    pthread_t thr[N];
    int ids[N];
    for(int i=0;i<N;i++) { pthread_mutex_init(&forks[i], NULL); ids[i]=i; }
    for(int i=0;i<N;i++) pthread_create(&thr[i], NULL, philosopher, &ids[i]);
    for(int i=0;i<N;i++) pthread_join(thr[i], NULL);
    for(int i=0;i<N;i++) pthread_mutex_destroy(&forks[i]);
    printf("All philosophers finished.\n");
    return 0;
}
