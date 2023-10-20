#include <stdio.h>
#include <stdarg.h>

double print_and_sum(char *format, int num, ...) {
    va_list args;

    va_start(args, num);
    double sum = 0.0;
    for (int i = 0; i < num; i++) {
        double arg = va_arg(args, double);
        sum += arg;
    }

    va_start(args, num);
    vprintf(format, args);
    printf("= %.3f\n", sum);

    va_end(args);
    return sum;
}


int main(int argc, char **argv) {
    print_and_sum("%3.1f ", 1, 1.5);
    print_and_sum("%3.1f + %3.1f ", 2, 1.5, 2.5);
    print_and_sum("%3.1f + %3.1f + %3.1f ", 3, 1.5, 2.5, 3.5);
    return 0;
}
