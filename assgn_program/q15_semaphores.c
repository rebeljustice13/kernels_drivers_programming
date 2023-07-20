#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t sem1, sem2;
int counter1 = 0, counter2 = 0;

void* thread1(void* arg)
{
    int i;
    for(i = 0; i < 5; i++) // run for 5 iterations
    {
        sem_wait(&sem1);
        printf("Thread 1\n");
        sem_post(&sem2);
        counter1++;
    }
    pthread_exit(NULL);
}

void* thread2(void* arg)
{
    int i;
    for(i = 0; i < 5; i++) // run for 5 iterations
    {
        sem_wait(&sem2);
        printf("Thread 2\n");
        sem_post(&sem1);
        counter2++;
    }
    pthread_exit(NULL);
}

int main()
{
    pthread_t t1, t2;
    sem_init(&sem1, 0, 1);
    sem_init(&sem2, 0, 0);
    pthread_create(&t1, NULL, thread1, NULL);
    pthread_create(&t2, NULL, thread2, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    sem_destroy(&sem1);
    sem_destroy(&sem2);
    printf("Thread 1 printed %d times\n", counter1);
    printf("Thread 2 printed %d times\n", counter2);
    return 0;
}

