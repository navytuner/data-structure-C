#ifndef __NAMECARD_H__
#define __NAMECARD_H__

#define NAME_LEN 30
#define PHONE_LEN 30

struct namecard {
    char name[NAME_LEN];
    char phone[NAME_LEN];
};

struct namecard* make_namecard(char*, char*);
void show_namecard(struct namecard*);
int comp_name(struct namecard*, char*);
void change_phone(struct namecard*, char*);

#endif