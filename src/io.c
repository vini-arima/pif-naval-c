#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include "game.h"
#include "io.h" 

// Funções exibir (TABULEIRO E FROTA)
void io_display_board(Board *board , int mostra_navios){
    printf("  ") ;
    for(int c = 0 ; c < board -> colunas ; c++){
        printf("%c", 'A' + c) ;
    }
    printf("\n");

    for(int l = 0 ; l < board -> linhas ; l++){
        printf("%2d", l + 1);

        for (int c = 0; c < board->colunas; c++) {
            Cell *cell = get_Cell(board , l , c); 

            char simbolo;
            switch (cell->state) {
                case CELL_agua: simbolo = '~'; break; 
                case CELL_dano:   simbolo = 'x'; break;
                case CELL_erro:  simbolo = '*'; break; 
                case CELL_navio: 
                    // Operador ternário: Se show_ships != 0, mostra 'N', senão, mostra '~'
                    simbolo = (mostra_navios) ? 'N' : '~';
                    break; 
                default:         simbolo = '?'; break;
            }
            printf("%c", simbolo); 
        }
        printf("\n");
    }
}

void io_display_fleet_status(Fleet *fleet){
    printf("\n--- Status da Frota ---\n");
    for (int i = 0; i < fleet->count; i++) {
        Navio *navios= &fleet->navios[i];
        printf("%-15s: %d/%d acertos. %s\n", 
               navios ->name, 
               navios ->dano, 
               navios ->tamanho, 
               (navios->dano == navios -> tamanho ? "**AFUNDADO**" : "Flutuando"));
    }
}

