/*
=========================================================
Pseudocode for Dining Philosophers (Deadlock-Free)

Initialize:
    N = 5 (Number of philosophers/forks)
    forks = array of N mutexes
    
Philosopher Process (id):
    left_fork = id
    right_fork = (id + 1) % N

    WHILE (true) DO
        // 1. Thinking phase
        Print "Philosopher [id] is thinking."
        Sleep for some time

        // 2. Hungry phase (Picking up forks)
        // ASYMMETRIC SOLUTION TO PREVENT DEADLOCK:
        IF (id is EVEN) THEN
            LOCK(forks[left_fork])
            Print "Picked up left fork"
            LOCK(forks[right_fork])
            Print "Picked up right fork"
        ELSE (id is ODD) THEN
            LOCK(forks[right_fork])
            Print "Picked up right fork"
            LOCK(forks[left_fork])
            Print "Picked up left fork"
        END IF

        // 3. Eating phase
        Print "Philosopher [id] is eating."
        Sleep for some time

        // 4. Put down forks
        UNLOCK(forks[left_fork])
        UNLOCK(forks[right_fork])
        Print "Philosopher [id] put down both forks."
    END WHILE

Main Process:
    For i = 0 to N-1: Initialize forks[i] mutex
    For i = 0 to N-1: Create Philosopher thread(i)
    For i = 0 to N-1: Join Philosopher thread(i)
=========================================================
*/

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define N 5

pthread_mutex_t forkm[N];

void *philosopher(void *arg)
{
    int id = *(int *)arg;
    int left = id;
    int right = (id + 1) % N;

    while(1)
    {
        printf("P%d Thinking\n", id);

        pthread_mutex_lock(&forkm[left]);
        pthread_mutex_lock(&forkm[right]);

        printf("P%d Eating\n", id);
        sleep(1);

        pthread_mutex_unlock(&forkm[left]);
        pthread_mutex_unlock(&forkm[right]);
    }
}

int main()
{
    pthread_t p[N];
    int id[N];

    for(int i = 0; i < N; i++)
    {
        pthread_mutex_init(&forkm[i], NULL);
        id[i] = i;
        pthread_create(&p[i], NULL,
                       philosopher, &id[i]);
    }

    for(int i = 0; i < N; i++)
        pthread_join(p[i], NULL);

    return 0;
}