#include "Human.h"
#include <string.h>
#include <stdlib.h>


human_t *init_human(human_t *human, char *name, hazard_t hazard, float recruitmentProb) {
    human->name = strdup(name);
    human->hazard = hazard;
    human->recruitmentProb = recruitmentProb;
    return human;
}


int count_recruitable_humans(human_t *humans, int size, float recruitmentReq, hazard_t hazardReq) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (humans[i].hazard == hazardReq && humans[i].recruitmentProb >= recruitmentReq) {
            count++;
        }
    }
    return count;
}

void free_human(human_t *human) {
    free(human->name);
}

void free_humans(human_t *humans, int size) {
    for (int i = 0; i < size; i++) {
        free_human(&humans[i]);
    }
}
