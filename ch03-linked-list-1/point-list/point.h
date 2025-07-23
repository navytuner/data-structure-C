#ifndef __POINT_H__
#define __POINT_H__

struct point {
    int x;
    int y;
};

void set_point(struct point*, int, int);
void show_point(struct point*);
int comp_point(struct point*, struct point*);

#endif 