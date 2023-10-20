#include "simulations.h"
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char **argv)
{
    int numpartidas = 4;
    Partida *partidas = malloc(numpartidas*sizeof(Partida));

    Partida_set(&partidas[0], "John", 10.0);
    Partida_set(&partidas[1], "Tom", 20.0);
    Partida_set(&partidas[2], "John", 25.0);
    Partida_set(&partidas[3], "Bob", 40.0);

    int num_players;
    int error;
    Puntuacion *points_counts = agrego_puntuacion(partidas, numpartidas, &num_players, &error);

    if (error != SUCCESS) {
        printf("Error: %d\n", error);
        return 1;
    }

    printf("Number of players (children): %d\n", num_players);
    for (int i=0; i<num_players; i++) {
        printf("%-8s: %2d games, %6.2f points\n", points_counts[i].nombre, points_counts[i].num_partidas, points_counts[i].total);
    }

    Partida_freeall(partidas, numpartidas);
    Puntuacion_freeall(points_counts, num_players);

    return 0;
}
