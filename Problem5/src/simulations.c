#include "simulations.h"
#include <stdlib.h>
#include <string.h>


void Partida_free(Partida game)
{
    free(game.nombre);
}
void Partida_freeall(Partida *games, int num_games)
{
    for (int i=0; i<num_games; i++) {
        Partida_free(games[i]);
    }
    free(games);
}
void Puntuacion_free(Puntuacion score)
{
    free(score.nombre);
}
void Puntuacion_freeall(Puntuacion *scores, int num_scores)
{
    for (int i=0; i<num_scores; i++) {
        Puntuacion_free(scores[i]);
    }
    free(scores);
}


/** @brief Finds the index of a player with the given name in an array of point counts.
 *
 * @param point_counts An array of `Puntuacion` point count structs.
 * @param num_counts The number of entries in the array.
 * @param player_name The name of the player to find.
 *
 * @return The index of the point count with the given player name, or -1 if the player is not found.
 */
static int find_player(Puntuacion *point_counts, int num_counts, char *player_name)
{
    for (int i=0; i<num_counts; i++) {
        if (strcmp(point_counts[i].nombre, player_name) == 0) {
            return i;
        }
    }
    return -1;
}

/** @brief Adds up the points for each player in an array of games.
 * 
 * Given a dynamic array of variables of type `struct partida` of a given length, creates
 * another dynamic array of variables of type  `struct puntuacion` of length equal to the
 * number of unique players in the `games` array.
 * Each position of the new array will correspond to a unique player and it stores the
 * name of the child, the number of games they have played and their total score (as sum
 * of the obtained points in each game).
 * 
 * @param games An array of `Partida` game structs.
 * @param num_games The number of entries in the `games` array.
 * @param num_players (Output) The number of entries in the returned array.
 * @param error (Output) The error code, if any.
 * 
 * @return A dynamically allocated array of `Puntuacion` point count structs, or NULL if
 * an error occurred.
 * 
 * @note The returned array must be freed by the caller.
*/
Puntuacion *agrego_puntuacion(Partida *games, int num_games, int *num_players, int *error)
{
    *error = SUCCESS;
    if (num_games <= 0)  return NULL; // No error

    Puntuacion *players_counts = calloc(num_games, sizeof(Puntuacion));
    if (players_counts == NULL) {
        *error = MEMORY_ERROR; return NULL; // Indeed error
    }

    *num_players = 0;
    for (int i=0; i<num_games; i++) {
        int index = find_player(players_counts, *num_players, games[i].nombre);
        if (index < 0) {
            index = (*num_players)++; // Watch out: post-increment
            players_counts[index].nombre = strdup(games[i].nombre);
        }
        players_counts[index].total += games[i].puntos;
        players_counts[index].num_partidas += 1;
    }

    players_counts = realloc(players_counts, sizeof(Puntuacion)*(*num_players));
    if (players_counts == NULL) {
        *error = MEMORY_ERROR; return NULL; // Indeed error
    }
    return players_counts;
}
