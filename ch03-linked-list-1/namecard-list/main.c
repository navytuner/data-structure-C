#include <stdio.h>
#include "namecard.h"
#include "arraylist.h"

int main(void){
    struct arraylist list;
    struct namecard* card;

    list_init(&list);
    
    // Insert
    card = make_namecard("aaa", "123");
    list_insert(&list, card);
    card = make_namecard("bbb", "4567");
    list_insert(&list, card);
    card = make_namecard("ccc", "890");
    list_insert(&list, card);

    // show info
    if (list_first(&list, &card)){
        show_namecard(card);
        while (list_next(&list, &card)){
            show_namecard(card);
        }
    }

}