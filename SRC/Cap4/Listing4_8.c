
#include <malloc.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* Allocate a temporary buffer.  */

void *allocate_buffer(size_t size)
{
    return malloc(size);
}

/* Deallocate a temporary buffer.  */

void deallocate_buffer(void *buffer)
{
    free(buffer);
}

void *do_some_work(void *arg)
{
    /* Allocate a temporary buffer.  */
    void *temp_buffer = allocate_buffer(1024);
    /* Register a cleanup handler for this buffer, to deallocate it in
       case the thread exits or is cancelled.  */
    pthread_cleanup_push(deallocate_buffer, temp_buffer);

    /* Do some work here that might call pthread_exit or might be
       cancelled...  */

    // Simulate some work
    printf("El hilo se está imprimiento...\n");
    sleep(2);

    // Explicitly cancel the thread
    pthread_exit(NULL);

    /* Unregister the cleanup handler.  Since we pass a non-zero value,
       this actually performs the cleanup by calling
       deallocate_buffer.  */
    pthread_cleanup_pop(1);
    return NULL;
}

int main()
{
    pthread_t thread;
    int prime;

    /* Start the computing thread, up to the 5000th prime number.  */
    pthread_create(&thread, NULL, &do_some_work, NULL);
    /* Do some other work here...  */
    /* Wait for the prime number thread to complete, and get the result.  */
    pthread_join(thread, (void *)&prime);
    /* Print the largest prime it computed.  */
    return 0;
}