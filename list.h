#ifndef __LIST_H__
#define __LIST_H__

typedef int (*comp_t)(void*, void*);

typedef struct node {
        void *field;
        struct node *ptr;
}node_t;

typedef struct list {
        comp_t comp;
        node_t *root;
}list_t;

list_t * Init (comp_t comp);

node_t * Search (list_t *lst, void *search);

void Delete (list_t *lst, node_t *del);

node_t * Next (node_t *lst);

node_t * Previous (node_t *lst, node_t *root);

void AddFirst (list_t *lst, void *data);

void AddLast (list_t *lst, void *data);

void Sort (list_t *lst);

void Clean (list_t *lst);

typedef struct Dnode {
        void *data;
        struct Dnode *next, *prev;
}Dnode_t;

typedef struct Dlist {
        comp_t comp;
        Dnode_t *root;
}Dlist_t;

Dlist_t * InitD (comp_t comp);

void AddFirstD (Dlist_t *dlst, void *data);

void AddLastD (Dlist_t *dlst, void *data);

Dnode_t * SearchD (Dlist_t *dlst, void *search);

void DeleteD (Dlist_t *dlst, Dnode_t *del);

Dnode_t * NextD (Dnode_t *dlst);

Dnode_t * PreviousD (Dnode_t *dlst);

void SortD (Dlist_t *dlst);

void CleanD (Dlist_t *dlst);

#endif

