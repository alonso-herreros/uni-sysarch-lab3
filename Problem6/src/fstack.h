#ifndef FSTACK_H
#define FSTACK_H

typedef struct fstack {
    float *data;
    int size;
    int capacity;
    int factor;

    void (*delete_stack)(struct fstack *);
    int (*push)(struct fstack *, float);
    float (*pop)(struct fstack *);
    float (*peek)(struct fstack *);
    int (*get_size)(struct fstack *);
} FloatStack;

FloatStack *FloatStack_init(FloatStack *stack, int capacity, int factor);
void FloatStack_delete(FloatStack *stack);
int FloatStack_push(FloatStack *stack, float value);
float FloatStack_pop(FloatStack *stack);
float FloatStack_peek(FloatStack *stack);
int FloatStack_size(FloatStack *stack);

#endif