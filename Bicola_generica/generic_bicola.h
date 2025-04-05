#ifndef GENERIC_BICOLA_H
#define GENERIC_BICOLA_H

#include "../include/linked_list.h"

// ----------------------------
// Declaración de la estructura y funciones para bicola genérica
// ----------------------------
#define DECLARE_BICOLA(TYPE) \
    typedef struct { \
        List_##TYPE* list; /* Usamos una lista ligada como base para la bicola */ \
    } Bicola_##TYPE; \
    \
    Bicola_##TYPE* bicola_##TYPE##_create(void); \
    void bicola_##TYPE##_destroy(Bicola_##TYPE* bicola); \
    bool bicola_##TYPE##_is_empty(const Bicola_##TYPE* bicola); \
    size_t bicola_##TYPE##_size(const Bicola_##TYPE* bicola); \
    bool bicola_##TYPE##_push_front(Bicola_##TYPE* bicola, TYPE value); \
    bool bicola_##TYPE##_push_back(Bicola_##TYPE* bicola, TYPE value); \
    bool bicola_##TYPE##_pop_front(Bicola_##TYPE* bicola, TYPE* value); \
    bool bicola_##TYPE##_pop_back(Bicola_##TYPE* bicola, TYPE* value); \
    bool bicola_##TYPE##_peek_front(const Bicola_##TYPE* bicola, TYPE* value); \
    bool bicola_##TYPE##_peek_back(const Bicola_##TYPE* bicola, TYPE* value); \
    void bicola_##TYPE##_display(const Bicola_##TYPE* bicola, void (*print_fn)(TYPE));

// ----------------------------
// Implementación de las funciones para bicola genérica
// ----------------------------
#define IMPLEMENT_BICOLA(TYPE) \
    Bicola_##TYPE* bicola_##TYPE##_create(void) { \
        Bicola_##TYPE* bicola = malloc(sizeof(Bicola_##TYPE)); \
        if (!bicola) return NULL; \
        bicola->list = list_##TYPE##_create(); \
        if (!bicola->list) { \
            free(bicola); \
            return NULL; \
        } \
        return bicola; \
    } \
    \
    void bicola_##TYPE##_destroy(Bicola_##TYPE* bicola) { \
        if (!bicola) return; \
        list_##TYPE##_destroy(bicola->list); \
        free(bicola); \
    } \
    \
    bool bicola_##TYPE##_is_empty(const Bicola_##TYPE* bicola) { \
        return bicola ? list_##TYPE##_is_empty(bicola->list) : true; \
    } \
    \
    size_t bicola_##TYPE##_size(const Bicola_##TYPE* bicola) { \
        return bicola ? list_##TYPE##_length(bicola->list) : 0; \
    } \
    \
    bool bicola_##TYPE##_push_front(Bicola_##TYPE* bicola, TYPE value) { \
        return bicola ? list_##TYPE##_insert(bicola->list, value, 0) : false; \
    } \
    \
    bool bicola_##TYPE##_push_back(Bicola_##TYPE* bicola, TYPE value) { \
        return bicola ? list_##TYPE##_append(bicola->list, value) : false; \
    } \
    \
    bool bicola_##TYPE##_pop_front(Bicola_##TYPE* bicola, TYPE* value) { \
        if (!bicola || !value || list_##TYPE##_is_empty(bicola->list)) return false; \
        if (!list_##TYPE##_get(bicola->list, 0, value)) return false; \
        return list_##TYPE##_remove_at(bicola->list, 0); \
    } \
    \
    bool bicola_##TYPE##_pop_back(Bicola_##TYPE* bicola, TYPE* value) { \
        if (!bicola || !value || list_##TYPE##_is_empty(bicola->list)) return false; \
        size_t last_index = list_##TYPE##_length(bicola->list) - 1; \
        if (!list_##TYPE##_get(bicola->list, last_index, value)) return false; \
        return list_##TYPE##_remove_at(bicola->list, last_index); \
    } \
    \
    bool bicola_##TYPE##_peek_front(const Bicola_##TYPE* bicola, TYPE* value) { \
        return bicola && value ? list_##TYPE##_get(bicola->list, 0, value) : false; \
    } \
    \
    bool bicola_##TYPE##_peek_back(const Bicola_##TYPE* bicola, TYPE* value) { \
        if (!bicola || !value || list_##TYPE##_is_empty(bicola->list)) return false; \
        size_t last_index = list_##TYPE##_length(bicola->list) - 1; \
        return list_##TYPE##_get(bicola->list, last_index, value); \
    } \
    \
    void bicola_##TYPE##_display(const Bicola_##TYPE* bicola, void (*print_fn)(TYPE)) { \
        if (!bicola) return; \
        printf("Contenido de la bicola: "); \
        list_##TYPE##_print(bicola->list, print_fn); \
    }

// ----------------------------
// Declaraciones concretas
// ----------------------------
DECLARE_BICOLA(int)
DECLARE_BICOLA(char)
DECLARE_BICOLA(float)

// ----------------------------
// Implementaciones concretas
// ----------------------------
#ifdef GENERIC_BICOLA_IMPLEMENTATION
IMPLEMENT_BICOLA(int)
IMPLEMENT_BICOLA(char)
IMPLEMENT_BICOLA(float)
#endif

#endif /* GENERIC_BICOLA_H */
