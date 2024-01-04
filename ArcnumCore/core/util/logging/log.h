#ifndef CORE_LOG_H
#define CORE_LOG_H

#include "../std_include.h"


// Formatted logging
__A_CORE_API__ void _a_core_trace_f_(c_str format, ...);
__A_CORE_API__ void _a_core_info_f_(c_str format, ...);
__A_CORE_API__ void _a_core_warn_f_(c_str format, ...);
__A_CORE_API__ void _a_core_error_f_(c_str format, ...);

// Unformatted logging
__A_CORE_API__ void _a_core_trace_uf_(c_str uformat);
__A_CORE_API__ void _a_core_info_uf_(c_str uformat);
__A_CORE_API__ void _a_core_warn_uf_(c_str uformat);
__A_CORE_API__ void _a_core_error_uf_(c_str uformat);

#ifdef __A_CORE_TRACE__
#define A_CORE_TRACE_F(_format_, ...) _a_core_trace_f_(_format_, __VA_ARGS__)
#define A_CORE_TRACE_UF(_uformat_) _a_core_trace_uf_(_uformat_)
#else
#define A_CORE_TRACE(_format_, ...)
#endif // __A_CORE_TRACE__

#ifdef __A_CORE_INFO__
#define A_CORE_INFO_F(_format_, ...) _a_core_info_f_(_format_, __VA_ARGS__)
#define A_CORE_INFO_UF(_uformat_) _a_core_trace_uf_(_uformat_)
#else
#define A_CORE_INFO(_format_, ...)
#endif // __A_CORE_INFO__

#ifdef __A_CORE_WARN__
#define A_CORE_WARN_F(_format_, ...) _a_core_warn_f_(_format_, __VA_ARGS__)
#define A_CORE_WARN_UF(_uformat_) _a_core_warn_uf_(_uformat_)
#else
#define A_CORE_WARN(_format_, ...)
#endif // __A_CORE_WARN__

#ifdef __A_CORE_ERROR__
#define A_CORE_ERROR_F(_format_, ...) _a_core_error_f_(_format_, __VA_ARGS__)
#define A_CORE_ERROR_UF(_uformat_) _a_core_error_uf_(_uformat_)
#else
#define A_CORE_ERROR(_format_, ...)
#endif // __A_CORE_ERROR__

#endif // CORE_LOG_H