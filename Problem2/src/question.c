#include "question.h"
#include <stdlib.h>
#include <string.h>


Question *Question_init(char *prompt, char *ans, enum q_type type, float points)
{
    Question *this_p = malloc(sizeof(Question));
    this_p->prompt = strdup(prompt);
    strcpy(this_p->ans, ans);
    this_p->type = type;
    this_p->points = points;
    return this_p;
}

void Question_free(Question *this_p)
{
    free(this_p->prompt);
    free(this_p);
}


float max_score(Question *q_array, int nmemb, enum q_type type)
{
    float sum = 0;
    for (int i=0; i<nmemb; i++) {
        if (type == ANY || q_array[i].type == type) {
            sum +=q_array[i].points;
        }
    }
    return sum;
}
