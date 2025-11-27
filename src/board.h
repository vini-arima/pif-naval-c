#ifndef BOARD_H  
#define BOARD_H  

typedef enum { 
    CELL_agua,     // 0 - Água
    CELL_navio,      // 1 - Navio
    CELL_dano,       // 2 - Acertado
    CELL_erro       // 3 - Água com tiro
} CellState;

typedef struct {
    CellState state;
    int navio_id;    
} Cell;

typedef struct {
    int linhas, colunas;
    Cell *cells;    
} Board;
void inicialize_board(Board *board , int linhas , int colunas);
void free_board(Board *board);
int board_get_cell(Board *board , int l , int c , Cell **result_cells) ;
Cell *get_cell(Board *board, int row, int col);

#endif