#ifndef CORE_MATH_H
#define CORE_MATH_H

#include "../std_include.h"

#define E         2.71828182845904523536028747135266250   
#define LOG2_E    1.44269504088896340735992468100189214   
#define LOG10_E   0.43429448190325182765112891891660508  
#define LN2       0.69314718055994530941723212145817656  
#define LN10      2.30258509299404568401799145468436421   
#define PI        3.14159265358979323846264338327950288   
#define PI_2      1.57079632679489661923132169163975144   
#define SQRT_2    1.41421356237309504880168872420969808

__A_CORE_API__ __A_CORE_INLINE__ f64 clamp(f64 val, f64 minval, f64 maxval);

#endif