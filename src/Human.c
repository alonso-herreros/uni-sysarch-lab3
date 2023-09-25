#include "Human.h"
#include <string.h>
#include <stdlib.h>


struct Human *init_human(struct Human *human, char *name, enum Hazard hazard, float recruitmentProb) {
    human->name = strdup(name);
    human->hazard = hazard;
    human->recruitmentProb = recruitmentProb;
    return human;
}


int count_recruitable_humans(struct Human *humans, int size, float recruitmentReq, enum Hazard hazardReq) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (humans[i].hazard == hazardReq && humans[i].recruitmentProb >= recruitmentReq) {
            count++;
        }
    }
    return count;
}

void free_human(struct Human *human) {
    free(human->name);
}

void free_humans(struct Human *humans, int size) {
    for (int i = 0; i < size; i++) {
        free_human(&humans[i]);
    }
}
