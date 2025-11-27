#ifndef RND_H
#define RND_H

#include "fleet.h" // preciso saber o que é 'orienta', tlgd?

// prepara o terreno pro random funcionar (srand)
void setup_random();

// escolhe um numero aleatorio entre min e max, na sorte
int get_random_number(int min, int max);

// tira no par ou impar se o barco fica deitado ou em pe
Orientation get_random_orientation();
#endif 