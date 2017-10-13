#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include "ringbuffer.h"

RingBuffer *rb_create() {
  RingBuffer *newRB = malloc(sizeof(RingBuffer));
  newRB->head = 0;
  newRB->tail = 0;
  newRB->nElem = 0;

  return newRB;
}

int next_index(int i) {
  if (i + 1 == RB_SIZE) 
    i = 0;
  else 
    i++;

  return i;
}

void rb_push(RingBuffer *rb, int elem) {
  assert(rb->nElem < RB_SIZE);
  rb->rb[rb->head] = elem;
  rb->head = next_index(rb->head);
  rb->nElem++;
}


int rb_pop(RingBuffer *rb) {
  assert(rb->nElem > 0);
  int retValue = rb->rb[rb->tail];
  rb->tail = next_index(rb->tail);
  rb->nElem--;

  return retValue;
}

void rb_print(RingBuffer *rb) {
  int i, j;
  if (rb->nElem > 0) {
    printf("| ");
    for (i = rb->tail, j = 0; j < rb->nElem; i = next_index(i), j++) 
      printf("%d | ", rb->rb[i]);
    printf("\n");
  }
  else 
    printf("Ring buffer vacío.\n");
}

void rb_destroy(RingBuffer *rb) {
  free(rb);
}