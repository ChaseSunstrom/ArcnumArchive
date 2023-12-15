#ifndef CORE_ALLOC_H
#define CORE_ALLOC_H

#include "../std_include.h"

AC_CORE_API #define ALLOC(_type) (_type*)malloc(sizeof(_type))
AC_CORE_API #define REALLOC(_ptr, _type, _size) (_type*)realloc(_ptr, sizeof(_type) * (_size))
AC_CORE_API #define FREE(_ptr) free(_ptr)

#endif // CORE_ALLOC_H