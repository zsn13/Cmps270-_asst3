/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
int count1s();
int Threads();
int arr[] = {0, 1, 2, 3, 4, 5};
int *array = &arr[0];
int length = 6;
int count;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int count1s()
{
    int i;
    count = 0;
    for (i = 0; i < length; i++)
    {
        if (array[i] == 1)
        {
            count++;
        }
    }
    return count;
}
int ccount_mutex()
{
    pthread_mutex_lock(&mutex);
    count1s();
    pthread_mutex_unlock(&mutex);
    return count;
}
int Threads_mutex(int number_of_threads)
{
    int i;
    pthread_t *threads;
    int index = number_of_threads;
    threads = (pthread_t *)malloc(number_of_threads * sizeof(pthread_t));
    for (i = 0; i < number_of_threads; i++)
    {
        pthread_mutex_lock(&mutex);
        pthread_create(&threads[i], NULL, (void *)count1s, NULL);
        pthread_mutex_unlock(&mutex);
    }
    for (i = 0; i < number_of_threads; i++)
    {

        pthread_join(threads[i], NULL);
    }
    return count;
}
int main()
{

    printf("The number of 1s in the array is %d", Threads_mutex(2));
    return 0;
}