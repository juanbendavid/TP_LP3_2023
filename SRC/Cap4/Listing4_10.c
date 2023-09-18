#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

struct job
{
    struct job *next;
    /* Other fields describing work to be done... */
};

/* A linked list of pending jobs.  */
struct job *job_queue;

extern void process_job(struct job *);

/* Process queued jobs until the queue is empty.  */

void *thread_function(void *arg)
{
    while (job_queue != NULL)
    {
        /* Get the next available job.  */
        struct job *next_job = job_queue;
        /* Remove this job from the list.  */
        job_queue = job_queue->next;
        /* Carry out the work.  */
        // process_job(next_job);
        /* Clean up.  */
        free(next_job);
    }
    return NULL;
}

int main(int argc, char const *argv[])
{
    // Initialize job_queue with some jobs (for example, three jobs)
    struct job *job1 = (struct job *)malloc(sizeof(struct job));
    struct job *job2 = (struct job *)malloc(sizeof(struct job));
    struct job *job3 = (struct job *)malloc(sizeof(struct job));

    // Set up the job queue
    job1->next = job2;
    job2->next = job3;
    job3->next = NULL;

    // Create threads to process jobs
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, thread_function, NULL);
    pthread_create(&thread2, NULL, thread_function, NULL);

    // Wait for the threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("All threads have finished processing jobs.\n");

    // Clean up any remaining resources (if needed)

    return 0;
}
