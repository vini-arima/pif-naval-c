#include<stdio.h>
#include<time.h>
#include"fleet.h"
#include "rnd.h"

void setup_random() {
    srand((unsigned int)time(NULL));
}

int random_number(int min, int max) {
    return min + (rand() % (max - min + 1));
}

Orientation random_orientation() {
    int val = rand() % 2;
    if (val == 0) {
        return ORIENT_H;
    } else {
        return ORIENT_V;
    }
}
