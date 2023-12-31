#ifndef CORE_VECTOR_H
#define CORE_VECTOR_H

#include "../std_include.h"

#include "../memory/alloc.h"

// ===============================================================================
// VECTOR:       | Can store any type in the same vector as another type 
// ===============================================================================

// Define a macro to declare a vector type
#define DECLARE_VECTOR(_type) \
    typedef struct { \
        uint64_t size; \
        uint64_t capacity; \
        byte** data; \
    } _type##_vector

// Define a macro to declare the vector type if not already declared
#define DECLARE_VECTOR_IF_NOT_DECLARED(_type) 
        #ifdef _type
_type##_vector
        #else 
DECLARE_VECTOR(_type);
#endif

// Define a macro to create an alias for the vector type
#ifndef vector
#define vector(_type) DECLARE_VECTOR_IF_NOT_DECLARED(_type)
#endif

// ===============================================================================
// VECTOR FUNCTIONS:

__A_CORE_API__ vector(generic) vector_default(void);
__A_CORE_API__ vector(generic) _vector_new(u64 size, generic values[]);
__A_CORE_API__ byte*       vector_get(vector(generic) v, u64 index);
__A_CORE_API__ void        vector_free(vector* v);
__A_CORE_API__ void        vector_push(vector* v, generic data);
__A_CORE_API__ void        vector_insert(vector* v, u64 index, generic data);
__A_CORE_API__ void        vector_pop(vector* v);
__A_CORE_API__ void        vector_remove(vector* v, u64 index);
__A_CORE_API__ void        vector_clear(vector* v);
__A_CORE_API__ void        vector_reverse(vector* v);
__A_CORE_API__ void        vector_add_capacity(vector* v, u64 size);
__A_CORE_API__ void        vector_add_vector(vector* v, vector* other);
__A_CORE_API__ void        _vector_add_array(vector* v, u64 size, generic array[]);
__A_CORE_API__ void        vector_remove_slice(vector* v, u64 index, u64 amount);
__A_CORE_API__ void        vector_move_data(vector* v, vector* other);
__A_CORE_API__ void        vector_change_data(vector* v, vector* other);
__A_CORE_API__ __A_CORE_INLINE__ static bool vector_is_big_enough(vector* v);


// helper macros to make calling vector functions easier
#define vector_new(_arr)   _vector_new(sizeof(_arr) / sizeof(_arr[0]), _arr)
#define vector_add_array(_v, _arr) _vector_add_array(_v, sizeof(_arr) / sizeof(_arr[0]), _arr)

//===============================================================================

#endif // CORE_VECTOR_H