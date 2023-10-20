#include "fstack.h"
#include <stdlib.h>
#include <math.h>

/** @brief Initialize a FloatStack to a given initial capacity
 * 
 * Initialize a FloatStack to a given initial capacity. The stack's capacity will
 * be incremented by the factor specified when the stack was initialized if it is
 * full and another value is pushed onto it.
 * 
 * @param stack The FloatStack variable to initialize.
 * @param capacity The initial capacity of the stack_p->
 * @param factor The factor by which the stack should grow when it is full.
*/
FloatStack *FloatStack_init(FloatStack *stack_p, int capacity, int factor)
{
    stack_p->data = calloc(capacity, sizeof(float));
    stack_p->size = 0;
    stack_p->capacity = capacity;
    stack_p->factor = factor;

    stack_p->delete_stack = FloatStack_delete;
    stack_p->push = FloatStack_push;
    stack_p->pop = FloatStack_pop;
    stack_p->peek = FloatStack_peek;
    stack_p->get_size = FloatStack_size;
    return stack_p;
}

/** @brief Delete a FloatStack and free the memory it used.
 * 
 * @param stack The FloatStack to delete.
 * 
 * @note This function does not free the memory allocated for the FloatStack object if it
 * allocated dynamically. It only frees the memory allocated for the stack's data.
*/
void FloatStack_delete(FloatStack *stack_p)
{
    free(stack_p->data);
}

/** @brief Push a value onto a FloatStack.
 * 
 * Push a value onto a FloatStack. If the stack's capacity is full, it will be
 * resized by the factor specified when the stack was initialized.
 * 
 * @param stack The FloatStack to push the value onto.
 * @param value The value to push onto the stack_p->
 * 
 * @return 0 if the value was successfully pushed onto the stack_p-> Error cases are
 * not considered.
*/
int FloatStack_push(FloatStack *stack_p, float value)
{
    if (stack_p->size == stack_p->capacity)
    {
        stack_p->capacity += stack_p->factor;
        //stack_p->data = realloc(stack_p->data, stack_p->capacity * sizeof(float));
    }
    stack_p->data[stack_p->size++] = value;
    return 0;
}

/** @brief Pop the top value of a FloatStack.
 * 
 * Remove and return the top value of a FloatStack. The size of the stack will be
 * decremented by one after this operation. If the stack is empty, the value INFINITY
 * from math.h will be returned.
 * 
 * @param stack The FloatStack to pop from.
 * 
 * @return The top value of the stack_p->
*/
float FloatStack_pop(FloatStack *stack_p)
{
    if (stack_p->size == 0)  return INFINITY;
    return stack_p->data[--stack_p->size];
}

/** @brief Peek at the top value of a FloatStack.
 * 
 * Peek at the top value of a FloatStack. The size of the stack will not be
 * decremented after this operation. If the stack is empty, the value INFINITY
 * from math.h will be returned.
 * 
 * @param stack The FloatStack to peek at.
 * 
 * @return The top value of the stack_p->
*/
float FloatStack_peek(FloatStack *stack_p)
{
    if (stack_p->size == 0)  return INFINITY;
    return stack_p->data[stack_p->size - 1];
}


/** @brief Get the size of a FloatStack, or -1 if the stack is empty.
 * 
 * Get the size of a FloatStack, or the value -1 if there are no elements on the stack_p->
 * The size of the stack is the number of values currently on the stack_p->
 * 
 * @param stack The FloatStack to get the size of.
 * 
 * @return The size of the stack_p-> -1 if the stack is empty.
*/
int FloatStack_size(FloatStack *stack_p)
{
    return (stack_p->size == 0) ? -1 : stack_p->size;
}
