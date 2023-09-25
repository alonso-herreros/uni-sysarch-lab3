#include <stdio.h>
#include <stdlib.h>
#include "Human.h"

#define HUMANS_COUNT 4


int main(int argc, char **argv) {
    struct Human humans[HUMANS_COUNT];
    init_human(&humans[0], "Alice", COMMON, 0.8);
    init_human(&humans[1], "Bob", HARMLESS, 0.2);
    init_human(&humans[2], "Charlie", DANGEROUS, 0.5);
    init_human(&humans[3], "Dave", HARMLESS, 0.6);

    int count = count_recruitable_humans(humans, HUMANS_COUNT, 0.3, HARMLESS);
    printf("There are %d recruitable humans\n", count);

    free_humans(humans, HUMANS_COUNT);

    return 0;
}
