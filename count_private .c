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
int size = 6;
int count;

int count1s()
{
    int i;
    count = 0;
    for (i = 0; i < size; i++)
    {
        if (array[i] == 1)
        {
            count++;
        }
    }
    return count;
}

int Threads(int numofThreads)
{
    int i;
    pthread_t *threads;
    int index = numofThreads;
    int array_private [numofThreads];
    threads = (pthread_t *)malloc(numofThreads * sizeof(pthread_t));
    for (i = 0; i < numofThreads; i++)
    {
        pthread_create(&threads[i], NULL, (void *)count1s, NULL);
        
    }
    for (i = 0; i < numofThreads; i++)
    {
        array_private[i] = count1s();
        pthread_join(threads[i], NULL);
    }
    int sum = 0;
    for(i = 0; i < numofThreads; i++){
    sum += array_private[i];
    }
    return sum;
}
int main()
{
    
    printf("The number of 1s in the array is %d", Threads(2));
    return 0;
}
