#ifndef IO_H
#define IO_H

#include "fleet.h" 
#include "board.h"
#include "fleet.h"

void io_display_board(Board *board , int mostra_navios) ;
void io_display_fleet_status(Fleet *fleet);
void io_read_coordenada(int *linha , int *coluna);
int io_read_orietation() ;

#endif
