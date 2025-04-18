#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include "linked_list_details.h"

#define class_List(T)    \
typedef struct List(T)   \
{                        \
    _M_List List;        \
}List(T);                \
\
typedef struct List_node(T) {    \
    struct List_node(T)* next;   \
    _M_List_generic data[];      \
}List_node(T);                   \
\
typedef List_node(T)* List_iterator(T);   \
\
/**
 *  @param this Reference to %List.
 *  @returns Iterator that points before the first element 
 *           in the %List.
 */\
__attribute__((unused))                                     \
static                                                      \
List_iterator(T) List_before_begin ## T(List(T)* this) {    \
    return (List_iterator(T)) &this->List.begin;            \
}                                                           \
\
/**
 *  @param this Reference to %List.
 *  @returns A read/write iterator that points to the first element 
 *           in the %List.
 */\
__attribute__((unused))                              \
static                                               \
List_iterator(T) List_begin ## T(List(T)* this) {    \
    return (List_iterator(T)) this->List.begin;      \
}                                                    \
\
/**
 *  @param this Reference to %List.
 *  @returns A read/write reverse iterator that points to the last 
 *           element in the %List.
 */\
__attribute__((unused))                              \
static                                               \
List_iterator(T) List_rbegin ## T(List(T)* this) {   \
    return (List_iterator(T)) this->List.rbegin;     \
}                                                    \
\
/**
 * @brief Provides read/write reference to the first element
 *        in non-empty %List.
 * @param this Reference to %List.
 */\
__attribute__((unused))                     \
static                                      \
T* List_front ## T (List(T)* this)          \
{                                           \
    return (T *)this->List.begin->data;     \
}                                           \
\
/**
 * @brief Provides read/write reference to the last element
 *        in non-empty %List.
 * @param this Reference to %List.
 */\
__attribute__((unused))                      \
static                                       \
T* List_back ## T (List(T)* this)            \
{                                            \
    return (T *)this->List.rbegin->data;     \
}                                            \
\
/**
 * @brief Provides read/write reference to data.
 * @param __it Iterator into the %List.
*/\
__attribute__((unused))                      \
static                                       \
T* List_data ## T (List_iterator(T) __it)    \
{                                            \
    return (T *)__it->data;                  \
}                                            \
\
/**
 * @brief Provides read/write reference to data in the element following 
 *        the element pointed to by @a __it.
 * @param __it Iterator into the %List.
*/\
__attribute__((unused))                            \
static                                             \
T* List_data_after ## T (List_iterator(T) __it)    \
{                                                  \
    return (T *)__it->next->data;                  \
}                                                  \
\
/**
 * @brief Add data to the end of the %List.
 * @param this Reference to %List.
 * @param __x Data to be added.
 *
 * This is a typical stack operation.  The function creates an
 * element at the end of the %List. and assigns the given 
 * data to it. Due to the nature of a %List. this operation
 * can be done in constant time, and does not invalidate iterators
 * and references.
 */\
__attribute__((unused))                                       \
static                                                        \
void List_push_back ## T(List(T)* this, T __x)                \
{                                                             \
    *(T *)_M_List_push_back(&this->List, sizeof(T)) = __x;    \
}                                                             \
\
/**
 * @brief Add data to the front of the %List.
 * @param this Reference to %List.
 * @param __x Data to be added.
 *
 * This is a typical stack operation.  The function creates an
 * element at the front of the %List and assigns the given 
 * data to it.  Due to the nature of a %List this operation 
 * can be done in constant time, and does not invalidate iterators 
 * and references.
 */\
__attribute__((unused))                                        \
static                                                         \
void List_push_front ## T(List(T)* this, T __x)                \
{                                                              \
    *(T *)_M_List_push_front(&this->List, sizeof(T)) = __x;    \
}                                                              \
\
/**
 * @brief Inserts given value into %List after specified iterator.
 * @param this Reference to %List.
 * @param __position Iterator into the %List.
 * @param __x Data to be inserted.
 * @return Iterator that points to the inserted data.
 * 
 * This function will insert a copy of the given value after the specified location.
 * Due to the nature of a %List this operation can be done in constant time,
 * and does not invalidate iterators and references.
*/\
__attribute__((unused))                                                                                                      \
static                                                                                                                       \
List_iterator(T) List_insert_after ## T(List(T)* this, List_iterator(T) __position, T __x)                                   \
{                                                                                                                            \
    List_iterator(T) __it = (List_iterator(T)) _M_List_insert_after(&this->List, (_M_List_iterator)__position, sizeof(T));   \
    *(T *)__it->data = __x;                                                                                                  \
    return __it;                                                                                                             \
}                                                                                                                            \
\
/**
 * @brief Removes first element.
 * @param this Reference to %List.
 *
 * This is a typical stack operation.  It shrinks the %List
 * by one.  Due to the nature of a %List this operation can 
 * be done in constant time, and only invalidates iterators/references
 * to the element being removed.
 *
 * Note that no data is returned, and if the first element's data
 * is needed, it should be retrieved before List_pop_front() is
 * called.
 */\
__attribute__((unused))                    \
static                                     \
void List_pop_front ## T(List(T)* this)    \
{                                          \
    _M_List_pop_front(&this->List);        \
}                                          \
\
/**
 * @brief Removes the element pointed to by the iterator following position.
 * @param this Reference to %List.
 * @param __position Iterator pointing before the element to be erased.
 * @return Iterator pointing to the element following the one that was erased, 
 *         or List_end() if no such element exists.
 * 
 * This function will erase the element pointed to by the iterator following 
 * position and thus shorten the %List by one. 
 *  
 * This function only erases the element, and that if the element is itself
 * a pointer, the pointed-to memory is not touched in any way. Managing the 
 * pointer is the user's responsibility.
 */\
__attribute__((unused))                                                                         \
static                                                                                          \
List_iterator(T) List_erase_after ## T(List(T)* this, List_iterator(T) __position)              \
{                                                                                               \
    return (List_iterator(T)) _M_List_erase_after(&this->List, (_M_List_iterator)__position);   \
}                                                                                               \
\
/**
 * @brief Resizes the %List to the specified number of elements.
 * @param this Reference to %List.
 * @param __size Number of elements the %List should contain.
 *
 * This function will %resize the %List to the specified number
 * of elements. If the number is smaller than the %List's current
 * number of elements the %List is truncated, otherwise zero-initialized
 * elements are appended.
*/\
__attribute__((unused))                                \
static                                                 \
void List_resize ## T(List(T)* this, size_t __size)    \
{                                                      \
    _M_List_resize(&this->List, __size, sizeof(T));    \
}                                                      \
\
/**
 * @brief Insert element from another %List.
 * @param this Reference to %List.
 * @param __position Iterator referencing the element to insert after.
 * @param __list Source list.
 * @param __pos Iterator referencing the element before the element to move.
 *
 * Removes the element after the element referenced by @a __pos in @a __list
 * and inserts it into @a this after @a __position.
 */\
__attribute__((unused))                                                                                            \
static                                                                                                             \
void List_splice_after ## T(List(T)* this, List_iterator(T) __position, List(T)* __list, List_iterator(T) __pos)   \
{                                                                                                                  \
    _M_List_splice_after(&this->List, (_M_List_iterator)__position, &__list->List, (_M_List_iterator)__pos);       \
}                                                                                                                  \
\
/**
 *  @brief Moves the resources of a %List.
 *  @param this Reference to %List.
 *  @return A list holding the resources of @a this.
 */\
__attribute__((unused))                                      \
static                                                       \
List(T) List_move ## T(List(T)* this)                        \
{                                                            \
    return (List(T)){.List = _M_List_move(&this->List)};     \
}                                                            \
\
/**
 * @brief Reverse the elements in %List.
 * @param this Reference to %List.
 * 
 * This function will reverse the order of elements in the %List.
 * in linear time.
 */\
__attribute__((unused))                  \
static                                   \
void List_reverse ## T(List(T)* this)    \
{                                        \
    _M_List_reverse(&this->List);        \
}                                        \
\
/**
 * @brief Sort the elements according to comparison function.
 * @param this Reference to %List.
 * @param __compare Comparison function.
 *  
 * This function sorts the elements, equivalent elements remain in list order.
 */\
__attribute__((unused))                                                             \
static                                                                              \
void List_sort ## T(List(T)* this, int (*__compare)(const void *, const void *))    \
{                                                                                   \
    _M_List_sort(&this->List, __compare);                                           \
}                                                                                   \
\
/**
 * @brief Swap contents of two %Lists of the same type.
 * @param __first Reference to the first %List.
 * @param __second Reference to the second %List.
 * 
 * This function exchanges the elements between two lists 
 * in constant time.
 */\
__attribute__((unused))                                     \
static                                                      \
void List_swap ## T(List(T)* __first, List(T)* __second)    \
{                                                           \
    _M_List_swap(&__first->List, &__second->List);          \
}

/* Construct an empty %List. */
#define List_new()                      {.List = _M_List_constructor()}

/**
 *  @returns A iterator that points one past the last 
 *           element in the %List.
 */
#define List_end()                      _M_List_end()

/* Returns the number of elements in the %List. */
#define List_empty(this)                _M_List_empty(&(this)->List)

/**
 * @brief Erases all the elements.
 * @param this Reference to %List.
 * 
 * Note that this function only erases the elements, and
 * that if the elements themselves are pointers, the pointed-to
 * memory is not touched in any way. Managing the pointer is the
 * user's responsibility.
 */
#define List_clear(this)                _M_List_clear(&(this)->List)

/**
 * @brief Erases the %List.
 * @param this Reference to %List.
 * 
 * Note that this function only erases the elements, and
 * that if the elements themselves are pointers, the pointed-to
 * memory is not touched in any way. Managing the pointer is the
 * user's responsibility.
 */
#define List_destructor(this)           _M_List_destructor(&(this)->List)

/**
 * @brief Erases a const %List.
 * @param this Reference to a const %List.
 * 
 * Note that this function only erases the elements, and
 * that if the elements themselves are pointers, the pointed-to
 * memory is not touched in any way. Managing the pointer is the
 * user's responsibility.
 */
#define List_const_destructor(this)     _M_List_const_destructor(&(this)->List)

#endif
