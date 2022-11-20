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

int Threads(int numThreads)
{
    int i;
    pthread_t *threads;
    int index = numThreads;
    threads = (pthread_t *)malloc(numThreads * sizeof(pthread_t));
    for (i = 0; i < numThreads; i++)
    {
        pthread_create(&threads[i], NULL, (void *)count1s, NULL);
        
    }
    for (i = 0; i < numThreads; i++)
    {

        pthread_join(threads[i], NULL);
    }
    return count;
}
int main()
{
    
    printf("Number of 1s in the array is %d", Threads(2));
    return 0;
}
//Specifications :
//requires: array of integers that are randomly generated 
// effects:count and print the num of ones in the array  
