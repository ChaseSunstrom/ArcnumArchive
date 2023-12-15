#ifndef CORE_RENDERER_H
#define CORE_RENDERER_H

// ==============================================================================
// RENDERER:     | Used for rendering and storing rendering data
// ==============================================================================
AC_CORE_API typedef struct
{
	f64 delta_time;
	f64 fixed_delta_time;
	f64 last_frame_time;
	f64 tick_time;
} renderer;

//===============================================================================
// RENDERER FUNCTIONS:     

AC_CORE_API renderer* renderer_new(void);
AC_CORE_API void      renderer_free(renderer* renderer);
AC_CORE_API void      renderer_render(renderer* renderer);
AC_CORE_API void      renderer_set_tick_time(renderer* renderer);
AC_CORE_API void      renderer_set_delta_time(renderer* renderer);
AC_CORE_API void      renderer_set_fixed_delta_time(renderer* renderer);
AC_CORE_API void      renderer_set_last_frame_time(renderer* renderer);
AC_CORE_API double    calculate_tick_time(void);
AC_CORE_API double    calculate_delta_time(void);
AC_CORE_API double    calculate_fixed_delta_time(void);
AC_CORE_API double    calculate_last_frame_time(void);

//===============================================================================
#endif //CORE_RENDERER_H