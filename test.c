#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
// int counter = 0;
// pthread_mutex_t mutex;

// void *thread_func(void *arg) {
//     pthread_mutex_lock(&mutex);
//     counter++;
//     printf("Thread %d incremented the counter to %d\n", *(int*)arg, counter);
//     pthread_mutex_unlock(&mutex);
//     return NULL;
// }

// int main() {
//     pthread_t thread1, thread2;
//     int thread1_id = 1, thread2_id = 2;


//     pthread_mutex_init(&mutex, NULL);

//     pthread_create(&thread1, NULL, thread_func, &thread1_id);
//     pthread_create(&thread2, NULL, thread_func, &thread2_id);

//     pthread_join(thread1, NULL);
//     pthread_join(thread2, NULL);

//     return 0;
// }
//void *siham(void *arg)
//{
//    write(1,"hi mohcine\n",11);
//    return NULL;
//}
//
//int main()
//{
//    pthread_t ana;
//    while(1)
//    pthread_create(&ana,NULL,siham,NULL);
//    pthread_join(ana,NULL);
//}
//---
//void *worker(void *arg) {
//    printf("Hello from worker thread1\n");
//    return NULL;
//}
//
//int main() {
//    pthread_t thread;
//
//    // Create the worker thread
//    pthread_create(&thread, NULL, worker, NULL);
//
//    printf("Hello from main thread\n");
//
//    while(1)// Detach the worker thread
//    pthread_detach(thread);
//  usleep(50000);
//
//    // Wait for a short time to let the worker thread finish
//
//    printf("Main thread exiting\n");
//
//    return 0;
//}