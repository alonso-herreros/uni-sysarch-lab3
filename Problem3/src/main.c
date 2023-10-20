#include <stdarg.h>
#include <stdio.h>

int count(int is_odd, int n, ...)
{
    va_list args;
    va_start(args, n);
    int count = 0;
    for (int i = 0; i < n; i++) {
        int num = va_arg(args, int);
        if (is_odd && num % 2 != 0) {
            count++;
        } else if (!is_odd && num % 2 == 0) {
            count++;
        }
    }
    va_end(args);
    return count;
}


int main(int argc, char **argv)
{
    printf("count(0, 2, 10, 14) returned %d\n", count(0, 2, 10, 14)); // returns 2
    printf("count(1, 2, 10, 14) returned %d\n", count(1, 2, 10, 14)); // returns 0
    printf("count(0, 5, 10, 14, 2, 3, 1) returned %d\n", count(0, 5, 10, 14, 2, 3, 1)); // returns 3
    printf("count(1, 5, 10, 14, 2, 3, 1) returned %d\n", count(1, 5, 10, 14, 2, 3, 1)); // returns 2
}
