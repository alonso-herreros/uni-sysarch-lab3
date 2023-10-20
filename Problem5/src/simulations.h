#ifndef PARTIDA_H
#define PARTIDA_H

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
void Partida_free(Partida *game);
void Puntuacion_free(Puntuacion *score);

#endif