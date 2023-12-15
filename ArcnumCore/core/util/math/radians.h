#ifndef CORE_RADIANS_H
#define CORE_RADIANS_H

AC_CORE_API #define PI 3.14159265358979

AC_CORE_API #define RADIANS(_degrees) _degrees * (PI / 180)
AC_CORE_API #define DEGREES(_radians) _radians * (180 / PI)

#endif // CORE_RADIANS_H