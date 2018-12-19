#include <stdio.h>
#include <stdlib.h>
#include "list/list.h"
#include <string.h>

int comp (void *a, void *b)
{
        return strcmp(a,b);
}

int main (int argc, char* argv[]) {

        node_t *CList;
        char *str1;
        str1 = (char*) malloc (sizeof(char)*100);
        list_t *List = Init (comp);
        strcpy(str1,"2");
        AddFirst(List,"1");
        AddFirst(List,"2");
        AddLast(List,"3");
        AddFirst(List,"5");
        AddFirst(List,"4");
        CList = Search(List,str1);
        printf("%s", CList->field);
        Delete(List,CList);
        Sort(List);
        free(str1);
        Clean(List);
        return 0;
}
