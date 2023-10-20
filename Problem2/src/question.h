#ifndef QUESTION_H
#define QUESTION_H


enum q_type {CORPORATIONS, CIVILIZATIONS, ART, HISTORY, LITERATURE, GENERAL, ANY};

typedef struct question {
    char *prompt;
    char ans[30];
    enum q_type type;
    float points;
} Question;

Question *Question_init(char *prompt, char *ans, enum q_type type, float points);
void Question_free(Question *this_p);
float max_score(Question *q_array, int nmemb, enum q_type type);


#endif