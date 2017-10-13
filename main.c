#include <stdio.h>
#include <pthread.h>
#include <malloc.h>
#include "ringbuffer.h"

#define NUM_THREADS 2

pthread_t t[NUM_THREADS];

RingBuffer *nuevo;

pthread_mutex_t actionDone;

static void *thread2 (void *_) {
  pthread_mutex_lock(&actionDone);
  rb_push(nuevo, 5);
  printf("Se ingresó un 5.\n");
  rb_print(nuevo);
  rb_pop(nuevo);
  printf("Se eliminó un elemento.\n");
  rb_print(nuevo);
}

static void *thread1 (void *_) {
  rb_push(nuevo, 7);
  printf("Se ingresó un 7.\n");
  rb_print(nuevo);
  rb_pop(nuevo);
  printf("Se eliminó un elemento.\n");
  rb_print(nuevo);
  pthread_mutex_unlock(&actionDone);
}

int main() {
  nuevo = rb_create();
  pthread_mutex_init(&actionDone, NULL);
  pthread_mutex_lock(&actionDone);

  pthread_create(&t[1], NULL, thread2, NULL);
  pthread_create(&t[0], NULL, thread1, NULL);

  pthread_mutex_destroy(&actionDone);

  pthread_exit(NULL);
  return 0; 
}