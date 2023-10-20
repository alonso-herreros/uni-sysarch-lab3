#include "question.h"
#include <stdio.h>

#define Q_NUM 4


int main(int argc, char **argv) {
    Question *qparr[Q_NUM] = {
        Question_init(
            "What is the answer to life, the universe and everything?", "43", GENERAL, 2.0f
        ),
        Question_init(
            "What color is Santiago's white horse?", "White", GENERAL, 1.0f
        ),
        Question_init(
            "Which civilization invented paper first?", "Chinese", CIVILIZATIONS, 3.0f
        ),
        Question_init(
            "Who painted the Mona Lisa?", "Leonardo da Vinci", ART, 2.5f
        )
    };
    Question qarr[Q_NUM]; for (int i=0; i<Q_NUM; i++) {qarr[i] = *qparr[i];}

    printf("Total number of points attainable: %.2f", max_score(qarr, Q_NUM, ANY));

    for (int i=0; i<Q_NUM; i++) {
        Question_free(qparr[i]);
    }

    return 0;
}
