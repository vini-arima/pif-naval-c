#include <stdio.h>
#include <stdlib.h>
#include "game.h"
#include "board.h"
#include "fleet.h"
#include "rnd.h"
#include "io.h" 
// VALIDAÇÃO DO JOGO
int is_place_navio(Board *board , int tamanho , int linha , int coluna , int orient){
    if(orient == ORIENT_H){
        if (coluna + tamanho > board->colunas) return 0; 
    }
    else{
        if (linha + tamanho > board->linhas) return 0; 
    } 

    for (int i = 0; i < tamanho; i++) {
        int r = linha + (orient == ORIENT_V ? i : 0);
        int c = coluna + (orient == ORIENT_H ? i : 0);
        Cell *cell = get_cell(board, r, c);
        if (cell->state != CELL_agua) return 0; 
    }
    return 1; 
} 

// POSICIONAMENTO AUTOMATICO
int place__auto_navio(Board *board, Fleet *fleet){
    int tentativas = 0 ; 
    int colocado = 0 ; 
    for( int i = 0 ; i < fleet ->count ; i++){
        Navio *navio = &fleet->navios[i];
        while(!colocado && tentativas < 100){
            int linha = random_number(board -> linhas) ;
            int coluna = random_number(board -> colunas) ;
            int orient = random_number(2) ; 

            tentativas++ ;
        }
    }
    if(!colocado){
        return 0 ;
    }
    return 1;
}
// POSICIONAMENTO MANUAL
int place_manual_navio(Board *board , Fleet *fleet){
    int colocado = 0 ;
    for(int i = 0 ; i < fleet -> count ; i++){
        Navio *navio = &fleet->navios[i];
        while(!colocado){
            printf("\nPosicionando: %s (Tamanho: %d)\n", navio->nome, navio->tamanho);
            print_board(board, 1); 
        }

        int r , c ; 
        read_coordinate(&r, &c);
        int orient = read_orientation();
    }
}

int process_tiro(Player *atacante , Player *defensor){
    // ?
}

// Verifica s eo jogo acabou
int game_over(Player *p , Fleet *fleet){
    for (int i = 0; i < p->fleet.count; i++) {
        if (p->fleet.navios[i].dano < p->fleet.navios[i].tamanho) {
            return 0; // Jogo NÃO acabou
        }
    }
    // Se o loop terminar sem encontrar nenhum navio flutuando, todos foram afundados.
    return 1; // Jogo ACABOU
}

