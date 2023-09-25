#ifndef HUMAN_H
#define HUMAN_H

enum Hazard {HARMLESS, COMMON, DANGEROUS};

struct Human { 
    char *name;
    enum Hazard hazard;
    float recruitmentProb;
};

struct Human *init_human(struct Human *human, char *name, enum Hazard hazard, float recruitmentProb);

int count_recruitable_humans(struct Human *humans, int size, float recruitmentReq, enum Hazard hazardReq);

void free_human(struct Human *human);

void free_humans(struct Human *humans, int size);

#endif