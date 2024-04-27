#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <limits.h>

#define NUM_THREADS 4 // Number of threads for parallel execution

void *thread_function(void *arg) {
    long long int start = *((long long int *)arg);
    for (long long int i = start; i < start + INT_MAX / NUM_THREADS; i++) {
        // Perform some computation (dummy loop)
    }
    pthread_exit(NULL);
}

int main() {
    printf("INT MAX = %d\n", INT_MAX);
    double tick1, tick2, et;

    tick1 = clock();

    pthread_t threads[NUM_THREADS];
    int rc;
    long long int start[NUM_THREADS];
    for (int t = 0; t < NUM_THREADS; t++) {
        start[t] = t * (INT_MAX / NUM_THREADS);
        rc = pthread_create(&threads[t], NULL, thread_function, (void *)&start[t]);
        if (rc) {
            printf("ERROR: return code from pthread_create() is %d\n", rc);
            return 1;
        }
    }

    // Wait for all threads to finish
    for (int t = 0; t < NUM_THREADS; t++) {
        pthread_join(threads[t], NULL);
    }

    tick2 = clock();
    double e = tick2 - tick1;
    et = (double)e / CLOCKS_PER_SEC;

    printf("Elapsed time = %lf seconds \n", et);

    return 0;
}
