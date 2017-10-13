#ifndef __RING_BUFFER__
#define __RING_BUFFER__

#define RB_SIZE 1000

typedef struct {
  int rb[RB_SIZE];
  int head;
  int tail;
  int nElem;
} RingBuffer;

RingBuffer *rb_create();
void rb_push(RingBuffer *rb, int elem);
int rb_pop(RingBuffer *rb);
void rb_print(RingBuffer *rb);
void rb_destroy(RingBuffer *rb);


#endif /* __RING_BUFFER__ */