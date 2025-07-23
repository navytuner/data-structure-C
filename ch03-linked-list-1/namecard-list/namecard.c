#include "namecard.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct namecard* make_namecard(char *name, char *phone){
   struct namecard *card = (struct namecard*)malloc(sizeof(struct namecard));
   strcpy(card->name, name);
   strcpy(card->phone, phone); 
   return card;
}

void show_namecard(struct namecard* card){
    printf("name: %s\n", card->name);
    printf("phone: %s\n", card->phone);
}

int comp_name(struct namecard *card, char *name){
    return strcmp(card->name, name);
}

void change_phone(struct namecard *card, char *phone){
    strcpy(card->phone, phone);
}


