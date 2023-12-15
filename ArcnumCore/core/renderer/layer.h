#ifndef CORE_LAYER_H
#define CORE_LAYER_H

AC_CORE_API typedef enum
{
	WINDOW_LAYER,
	RENDERER_LAYER,
	ENTITY_LAYER,
} layer_type;



// ==============================================================================
// LAYER:        | Used for the _renderer 
// ==============================================================================
AC_CORE_API typedef struct
{
	string name;
} layer;



// ==============================================================================
// LAYER FUNCTIONS:

AC_CORE_API layer* layer_new(void);
AC_CORE_API void   layer_on_attach(layer* layer);
AC_CORE_API void   layer_on_detach(layer* layer);
AC_CORE_API void   layer_on_update(layer* layer);
AC_CORE_API void   layer_on_event(layer* layer);
AC_CORE_API void   layer_free(layer* layer);

// ==============================================================================

#endif //CORE_LAYER_H