#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "board.h"
#include "fleet.h"
#include "io.h"
#include "game.h"
#include "rnd.h"

int main(){

    setup_random() ;
    printf("|============== BATALHA NAVAL =============== |");

    // Jogador 1
    Fleet frota_player1 ;
    inicialize_fleet(&frota_player1); 
    Board tab_p1 ; 
    inicialize_board(&tab_p1, 10, 10);

    // Jogador 2 
    Fleet frota_player2; 
    init_fleet(&frota_player2);
    Board tab_p2; 
    init_board(&tab_p2, 10, 10);

    int game_running = 1;
    int turnos = 1;
    int jogador_atual = 1;

    while (game_running) {
        printf("\n================ TURNO %d ================\n", turnos);
        
        // Determinar o jogador atual e o oponente
        Board *tab_atacante = (jogador_atual == 1) ? &tab_p1 : &tab_p2;
        Board *tab_alvo = (jogador_atual == 1) ? &tab_p2 : &tab_p1;
        Fleet *frota_alvo  = (jogador_atual == 1) ? &frota_player2: &frota_player2;
        
        printf("\n--> VEZ DO JOGADOR %d <--\n", jogador_atual);
        
        // Adicionar um prompt para o jogador ver as telas do oponente
        printf("\nPressione ENTER para ver o estado do jogo e fazer sua jogada...");
        while (getchar() != '\n'); // Limpa buffer e espera por ENTER
        getchar();

        // Mostrar o tabuleiro do alvo (escondido: 0) e o próprio (visível: 1)
        printf("\n--- AREA ALVO (JOGADOR %d) ---\n", (jogador_atual == 1) ? 2 : 1);
        print_board(tab_alvo, 0); // O tabuleiro alvo é sempre mostrado como 'escondido'
        
        printf("\n--- TUA FROTA (JOGADOR %d) ---\n", jogador_atual);
        print_board(tab_atacante, 1); // O seu tabuleiro é sempre mostrado como 'visível'

        // Leitura e execução da jogada
        int l, c;
        printf("\nJOGADOR %d, introduz coordenadas para atacar (ex: A10): ", jogador_atual);
        read_coordinate(&l, &c);
        
        int res = fire_shot(tab_alvo, frota_alvo, l, c);
        
        if (res == 1) printf("BOOM! ACERTASTE!\n");
        else if (res == 0) printf("Agua...\n");
        else printf("Tiro invalido! Perdeste a vez.\n");

        // 3. Verificação de Vitória
        if (game_over(frota_alvo)) {
            printf("\n\nVITORIA! JOGADOR %d DESTRUIU A FROTA INIMIGA EM %d TURNOS!\n", jogador_atual, turnos);
            game_running = 0; // Fim do jogo
        } else {
            // Se o jogo continuar, alternar o jogador
            jogador_atual = (jogador_atual == 1) ? 2 : 1;
            
            // Incrementa o turno apenas após a jogada dos dois jogadores (ou seja, no início do P1)
            if (jogador_atual == 1) {
                turnos++;
            }
        }
        
        // 4. Liberação de Memória
        free_board(&tab_p1); free_fleet(&frota_player1);
        free_board(&tab_p2); free_fleet(&frota_player2);
        return 0;
    }
    
}