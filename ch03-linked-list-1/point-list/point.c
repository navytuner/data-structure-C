#include <stdio.h>
#include "point.h"

void set_point(struct point* point, int x, int y){
    point->x = x;
    point->y = y;
}

void show_point(struct point* point){
    printf("[%d, %d]\n", point->x, point->y);
}

int comp_point(struct point* p1, struct point* p2){
    if (p1->x == p2->x && p1->y == p2->y) return 0;
    else return 1;
}