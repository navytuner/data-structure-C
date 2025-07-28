#ifndef __HEAP_H__
#define __HEAP_H__

#define HLEN 100

struct hent {
    int pri;
    char data;
};

struct heap {
    int sz;
    struct hent arr[HLEN];
};

void heap_init(struct heap *hp);
void heap_push(struct heap *hp, int pri, char data);
char heap_pop(struct heap *hp);
char heap_top(struct heap *hp);
void heap_display(struct heap *hp);

#endif