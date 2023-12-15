#ifndef CORE_MATH_H
#define CORE_MATH_H

#include "../std_include.h"

#define E         2.71828182845904523536028747135266250   
#define LOG2E     1.44269504088896340735992468100189214   
#define LOG10E    0.434294481903251827651128918916605082  
#define LN2       0.693147180559945309417232121458176568  
#define LN10      2.30258509299404568401799145468436421   
#define PI        3.14159265358979323846264338327950288   
#define PI_2      1.57079632679489661923132169163975144   
#define PI_4      0.785398163397448309615660845819875721  
#define 1_PI      0.318309886183790671537767526745028724  
#define 2_PI      0.636619772367581343075535053490057448  
#define 2_SQRTPI  1.12837916709551257389615890312154517   
#define SQRT2     1.41421356237309504880168872420969808   
#define SQRT1_2   0.707106781186547524400844362104849039  

__A_CORE_API__ __A_CORE_INLINE__ f64 clamp(f64 val, f64 minval, f64 maxval);

#endif