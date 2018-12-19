#include <stdlib.h>
#include "list.h"

list_t * Init (comp_t comp)
{
  list_t *lst;
  lst = (list_t*) malloc(sizeof(list_t));
  lst->root = NULL;
  lst->comp = comp;
  return (lst);
}

node_t * Search (list_t *lst, void *search)
{
        node_t *temp;
        temp = lst->root;
        while (temp->ptr != NULL)
        {
                if (lst->comp(temp->field, search)==0) return(temp);
                temp = temp->ptr;
        }
}

void Delete (list_t *lst, node_t *del)
{
        node_t *temp;
        temp = lst->root;
        if (temp == del)
        {
                lst->root = temp->ptr;
                free(del);
        }
        else
        {
                while (temp->ptr != del)
                        temp = temp->ptr;
                temp->ptr = del->ptr;
                free(del);
        }
}

node_t * Next (node_t *lst)
{
        return (lst->ptr);
}

node_t * Previous (node_t *lst, node_t *root)
{
        node_t *temp;
        temp = root;
        while (temp->ptr != lst)
        {
                temp = temp->ptr;
        }
}

void AddFirst (list_t *lst, void *data)
{
        node_t* temp;
        if (lst->root == NULL)
        {
                temp->ptr = NULL;
                temp->field = data;
                lst->root = temp;
        }
        else
        {
                temp = (node_t*) malloc(sizeof(node_t));
                temp->ptr = lst->root;
                temp->field = data;
                lst->root=temp;
                free(temp);
        }
}

void AddLast (list_t *lst, void *data)
{
        node_t *temp, *p;
        if (lst->root == NULL)
        {
                temp->ptr = NULL;
                temp->field = data;
                lst->root = temp;
        }
        else
        {
                temp = (node_t*) malloc(sizeof(node_t));
                p = lst->root;
                while (p->ptr != NULL)
                        p = p->ptr;
                temp->ptr = NULL;
                temp->field = data;
                p->ptr = temp;
                free(temp);
        }
}

void Sort (list_t *lst)
{
    node_t *temp, *p, *key;
    node_t *result = lst->root;
    temp = lst->root->ptr;
    result->ptr = NULL;

    while(temp->ptr != NULL){
        key = temp;
        lst->root = temp->ptr;
        if(key->field < result->field)
                {
            key->ptr = result;
            result = key;
        }
                else
                {
            p = result;
            while (p->ptr != NULL)
                        {
                if (lst->comp(p->ptr->field, key->field)>0)
                    break;
                p = p->ptr;
            }
            key->ptr = p->ptr;
            p->ptr = key;
        }
    }
    temp = result;
}

void Clean (list_t *lst)
{
        while (lst->root == NULL)
        {
                Delete(lst,lst->root);
                free(lst->root);
        }
        free(lst);
}

