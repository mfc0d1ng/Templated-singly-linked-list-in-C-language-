#ifndef _LINKED_LIST_CFS_H
#define _LINKED_LIST_CFS_H

#include "linked_list.h"

/* User configurations goes Here */

/** 
 * This macro generates the appropriate functions
 * for the type @a List(char). the generated functions
 * must appear once in each source code file */
class_List(char)

/** 
 * This macro generates the appropriate functions
 * for the type @a List(int). the generated functions
 * must appear once in each source code file */
class_List(int)

#include "point.h"

/** 
 * This macro generates the appropriate functions
 * for the type @a List(point). the generated functions
 * must appear once in each source code file */
class_List(point)

/** 
 * This macro selects the appropriate (List_before_begin)
 * depending on the type of the List @a this.
 */
#define List_before_begin(this) ({ \
    _Generic((this), \
        List(char) * : List_before_begin ## char, \
        List(int) * : List_before_begin ## int \
    )(this);\
})

/** 
 * This macro selects the appropriate (List_begin)
 * depending on the type of the List @a this.
 */
#define List_begin(this) ({ \
    _Generic((this), \
        List(char) * : List_begin ## char, \
        List(int)  * : List_begin ## int, \
        List(point)  * : List_begin ## point \
    )(this);\
})

/** 
 * This macro selects the appropriate (List_push_back)
 * depending on the type of the List @a this.
 */
#define List_push_back(this, ...) ({ \
    _Generic((this), \
        List(int)  * : List_push_back ## int, \
        List(point)  * : List_push_back ## point \
    )(this, __VA_ARGS__);\
})

/** 
 * This macro selects the appropriate (List_insert_after)
 * depending on the type of the List @a this.
 */
#define List_insert_after(this, __position, ...) ({ \
    _Generic((this), \
        List(char)  * : List_insert_after ## char \
    )(this, __position, __VA_ARGS__); \
})

/** 
 * This macro selects the appropriate (List_data)
 * depending on the type of the iterator @a __it.
 */
#define List_data(__it) ({ \
    _Generic((__it), \
        List_iterator(char) : List_data ## char, \
        List_iterator(int) : List_data ## int, \
        List_iterator(point) : List_data ## point \
    )(__it); \
})

#endif