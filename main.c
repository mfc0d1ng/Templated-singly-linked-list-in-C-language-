#include <stdio.h>
#include <stdlib.h>
#include "include/linked_list_cfg.h"

int main()
{
    List(char) chars = List_new();
    
    for (int i = 'A'; i < 'H'; i++)
    {
        List_insert_after(&chars, List_before_begin(&chars), i);
    }

    printf("List chars contains: ");
    for (List_iterator(char) it = List_begin(&chars); it; it = it->next)
    {
        printf("'%c' -> ", *List_data(it));
    }
    printf("%s\n\n", "NULL");

    List_destructor(&chars);
    
    /*----------------------------*/

    List(int) integers = List_new();
    
    for (int i = 0; i < 10; i++)
    {
        List_push_back(&integers, i);
    }

    printf("List integers contains: ");
    for (List_iterator(int) it = List_begin(&integers); it; it = it->next)
    {
        printf("%i -> ", *List_data(it));
    }
    printf("%s\n\n", "NULL");

    List_destructor(&integers);

    /*----------------------------*/

    List(point) points = List_new();
    
    for (int i = 100; i <= 104; i += 2)
    {
        List_push_back(&points, (point){i, i+1});
    }

    printf("List points contains: ");
    for (List_iterator(point) it = List_begin(&points); it; it = it->next)
    {
        printf("{%i, %i} -> ", List_data(it)->x, List_data(it)->y);
    }
    printf("%s\n\n", "NULL");

    List_destructor(&points);

    return EXIT_SUCCESS;
}
