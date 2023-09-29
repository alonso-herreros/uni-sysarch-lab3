#ifndef HUMAN_H
#define HUMAN_H

typedef enum Hazard {HARMLESS, COMMON, DANGEROUS} hazard_t;

typedef struct Human { 
    char *name;
    hazard_t hazard;
    float recruitmentProb;
} human_t;

human_t *init_human(human_t *human, char *name, hazard_t hazard, float recruitmentProb);

int count_recruitable_humans(human_t *humans, int size, float recruitmentReq, hazard_t hazardReq);

void free_human(human_t *human);

void free_humans(human_t *humans, int size);

#endif