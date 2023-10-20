#include "fstack.h"
#include <math.h>
#include <stdio.h>


int main(int argc, char **argv)
{
    FloatStack stack;
    FloatStack_init(&stack, 10, 10);
    stack.push(&stack, 1);
    stack.push(&stack, 2);
    stack.push(&stack, 2.5);
    stack.push(&stack, 3.2);
    float peek = stack.peek(&stack);
    stack.push(&stack, peek);
    float pop1 = stack.pop(&stack);
    stack.push(&stack, 8.2);
    float pop2 = stack.pop(&stack);
    float pop3 = stack.pop(&stack);
    float pop4 = stack.pop(&stack);

    printf("peek: %.2f\n", peek);
    printf("pop1: %.2f\n", pop1);
    printf("pop2: %.2f\n", pop2);
    printf("pop3: %.2f\n", pop3);
    printf("pop4: %.2f\n", pop4);
}
