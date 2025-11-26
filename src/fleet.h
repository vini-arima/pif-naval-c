#ifndef FLEET_H
#define FLEET_H 

typedef enum {ORIENT_H , ORIENT_V} Orientation ; 

typedef struct {
    char name[20]; // NOME
    int length; // TAMANHO
    int hits; // ACERTO
    int placed; // POSICAO
    Orientation orienta ;
} Ship ;

typedef struct{
    Ship *navios ; 
    int count ; 
} Fleet ;

typedef enum {
    navio_aviao,      // Porta-aviões (5 células)
    navio_encouracado,   // Encouraçado (4 células)
    navio_crusador,      // Cruzador (3 células)
    navio_destroyer      // Destroyer (2 células)
} ShipType ;

#endif