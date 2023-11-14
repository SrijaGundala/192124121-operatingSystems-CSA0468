#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_PHILOSOPHERS 7

pthread_t philosophers[NUM_PHILOSOPHERS];
pthread_mutex_t chopsticks[NUM_PHILOSOPHERS];

void *philosopher(void *arg) {
    int id = *(int *)arg;
    int left_chopstick = id;
    int right_chopstick = (id + 1) % NUM_PHILOSOPHERS;
    int i;
    for (i = 0; i <= 1; i++) {
        printf("Philosopher %d is thinking.\n", id);
        usleep(rand() % 1000000);

        pthread_mutex_lock(&chopsticks[left_chopstick]);
        pthread_mutex_lock(&chopsticks[right_chopstick]);

        printf("Philosopher %d is eating.\n", id);
        usleep(rand() % 1000000);

        pthread_mutex_unlock(&chopsticks[left_chopstick]);
        pthread_mutex_unlock(&chopsticks[right_chopstick]);
    }

    return NULL;
}

int main() {
    srand(time(NULL));
    int i;
    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_mutex_init(&chopsticks[i], NULL);
    }

    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        int *id = malloc(sizeof(int));
        *id = i;
        pthread_create(&philosophers[i], NULL, philosopher, id);
    }

    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_join(philosophers[i], NULL);
    }

    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_mutex_destroy(&chopsticks[i]);
    }

    return 0;
}

