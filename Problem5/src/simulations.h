#ifndef PARTIDA_H
#define PARTIDA_H


enum error_code {
    SUCCESS = 0,
    MEMORY_ERROR = 1,
    OUT_OF_BOUNDS = 2
};

typedef struct partida {
    float puntos;
    char *nombre;
} Partida;

typedef struct puntuacion {
    float total;
    char *nombre;
    int num_partidas;
} Puntuacion;

Puntuacion *agrego_puntuacion(Partida *games, int num_games, int *num_players, int *error);
void Partida_free(Partida game);
void Partida_freeall(Partida *games, int num_games);
void Puntuacion_free(Puntuacion score);
void Puntuacion_freeall(Puntuacion *scores, int num_scores);

#endif