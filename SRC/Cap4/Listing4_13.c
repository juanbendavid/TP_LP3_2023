

#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int thread_flag;
pthread_mutex_t thread_flag_mutex;

void initialize_flag()
{
    pthread_mutex_init(&thread_flag_mutex, NULL);
    thread_flag = 0;
}

/* Calls do_work repeatedly while the thread flag is set; otherwise
   spins.  */

void *thread_function(void *thread_arg)
{
    while (1)
    {
        int flag_is_set;

        /* Protect the flag with a mutex lock.  */
        pthread_mutex_lock(&thread_flag_mutex);
        flag_is_set = thread_flag;
        pthread_mutex_unlock(&thread_flag_mutex);

        if (flag_is_set)
            printf("Doing some work \n");
            
        /* Else don't do anything.  Just loop again.  */
    }
    return NULL;
}

/* Sets the value of the thread flag to FLAG_VALUE.  */

void set_thread_flag(int flag_value)
{
    /* Protect the flag with a mutex lock.  */
    pthread_mutex_lock(&thread_flag_mutex);
    thread_flag = flag_value;
    pthread_mutex_unlock(&thread_flag_mutex);
}

int main(int argc, char const *argv[])
{
    // Create threads to process jobs
    pthread_t thread1, thread2;

    initialize_flag();
    // Initialize the job queue
    pthread_create(&thread1, NULL, thread_function, NULL);

    // Set the flag to 1 to enable thread to do work
    set_thread_flag(1);

    // Let the thread work for a few seconds
    sleep(3);

    // Set the flag to 0 to stop the thread
    set_thread_flag(0);

    // Wait for the threads to finish
    pthread_join(thread1, NULL);

    return 0;
}
