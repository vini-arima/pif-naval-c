#include<stdio.h>
#include<stdlib.h>
#include "board.h" 

void inicialize_board(Board *board , int linhas , int colunas){
      // Validar linhas e colunas [6,26]
    if((linhas < 6 || colunas > 26) || (colunas < 26 || colunas > 6)){
         printf("Dimensões Invalidas") ; 
         return ;
    }
    board -> linhas = linhas ;
    board -> colunas = colunas ;

    int total_cells = linhas * colunas ; 

    board ->cells = malloc(total_cells * sizeof(Cell));
    
    if(board ->cells == NULL){
        printf("Falha ao alocar memoria");
        return ;
    }

    for (int i = 0 ; i < total_cells ; i++){
        board->cells[i].state = CELL_agua ;
        board->cells[i].navio_id = -1 ;
    }
}

void free_board(Board *board){
    if(board->cells != NULL){
        free(board->cells);
    }
}

int board_get_cell(Board *board , int l , int c , Cell **result_cells){
    if(l < 0 || l >= board-> linhas || c < 0 || c >= board-> colunas){
        *result_cells = NULL; 
         return 0;
    } 

    int indice = l * board-> colunas + c;

    *result_cells = &board->cells[indice];
    
    return 1 ;
}