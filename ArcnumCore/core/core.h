#ifndef CORE_CORE_H
#define CORE_CORE_H

#define __A_CORE_API__

#ifdef _MSC_VER
	#define __A_CORE_INLINE__   __forceinline
	#define __A_CORE_RESTRICT__ __restrict 
#else
	#define __A_CORE_INLINE__   inline
	#define __A_CORE_RESTRICT__ restrict
#endif // _MSC_VER

#define AC_STRUCT(_name, ...) struct _name { __VA_ARGS__ }
#define AC_ENUM(_name, ...) enum _name { __VA_ARGS__ }

// ANONYMOUS DATA STRUCTURES 
#define AC_A_STRUCT(_name, ...) typedef struct { __VA_ARGS__ } _name
#define AC_A_ENUM(_name, ...) typedef enum { __VA_ARGS__ } _name

#define AC_FN_PTR(_name, _return_type, ...) _return_type (*_name)(__VA_ARGS__)

#endif // CORE_CORE_H