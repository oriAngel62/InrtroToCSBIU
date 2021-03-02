/***********
* Ori Angel
* 314617739
* 01
* ass06
***********/
#ifndef _EX6_H_
#define _EX6_H_


typedef void *Ptr;

struct Trin_Ari {
    int id;
    char *name;

    struct Trin_Ari *left;
    struct Trin_Ari *middle;
    struct Trin_Ari *right;
};
typedef struct Trin_Ari Trin_Ari;

typedef enum {
    true = 1, false = 0
} Bool;

//typedef enum {
//    space=3
//} Space;




#endif