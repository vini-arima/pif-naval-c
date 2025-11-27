#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "fleet.h"

typedef struct {
    Board board;
    Board shots;
    Fleet fleet;
    char nickname[40];
 } Player;

typedef struct {
    Player p1, p2;
    int current_player;
    int game_over;
} Game;

is_place_navio(Board *board , int tamanho , int linha , int coluna , int orient) ;
place__auto_navio(Board *board, Fleet *fleet) ;
place_manual_navio(Board *board , Fleet *fleet) ; 
process_tiro(Player *atacante , Player *defensor) ; 
setup_player(Board *board, Fleet *fleet, int player_num) ;
game_over(Player *p , Fleet *fleet) ;
#endif