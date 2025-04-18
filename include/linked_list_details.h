#ifndef _LINKED_LIST_DETAILS_H
#define _LINKED_LIST_DETAILS_H

typedef unsigned char _M_List_generic;

typedef struct _M_List_node
{
    struct _M_List_node* next;
    _M_List_generic data[];
}_M_List_node;

typedef _M_List_node* _M_List_iterator;

typedef struct _M_List
{
    _M_List_iterator begin;
    _M_List_iterator rbegin;
    size_t size;
}_M_List;

#define _M_List_constructor()          {.begin = NULL, .rbegin = NULL, .size = 0}

#define _M_List_before_begin(this)     ((void *)&(this)->begin)

#define _M_List_begin(this)            ((this)->begin)

#define _M_List_rbegin(this)           ((this)->rbegin)

#define _M_List_end()                  (NULL)

#define _M_List_empty(this)            (_M_List_begin(this) == NULL)

#define _M_List_size(this)             ((this)->size)

extern void* _M_List_push_back(_M_List* this, size_t __isize);

extern void* _M_List_push_front(_M_List* this, size_t __isize);

extern _M_List_iterator _M_List_insert_after(_M_List* this, _M_List_iterator __position, size_t __isize);

extern void _M_List_pop_front(_M_List* this);

extern _M_List_iterator _M_List_erase_after(_M_List* this, _M_List_iterator __position);

extern void _M_List_resize(_M_List* this, size_t __size, size_t __isize);

extern void _M_List_splice_after(_M_List* this, _M_List_iterator __position, _M_List* ___M_List, _M_List_iterator __pos);

extern _M_List _M_List_move(_M_List* this);

extern void _M_List_reverse(_M_List* this);

extern void _M_List_sort(_M_List* this, int (*__compare)(const void *, const void *));

extern void _M_List_swap(_M_List* __first, _M_List* __second);

extern void _M_List_clear(_M_List* this);

extern void _M_List_destructor(_M_List* this);

extern void _M_List_const_destructor(const _M_List* this);

#define List(T)             List ## T

#define List_node(T)        List_node ## T

#define List_iterator(T)    List_iterator ## T

#endif