#ifndef CORE_LAYER_H
#define CORE_LAYER_H

__A_CORE_API__ typedef enum
{
	WINDOW_LAYER,
	RENDERER_LAYER,
	ENTITY_LAYER,
} layer_type;



// ==============================================================================
// LAYER:        | Used for the _renderer 
// ==============================================================================
__A_CORE_API__ typedef struct
{
	c_str name;
} layer;



// ==============================================================================
// LAYER FUNCTIONS:

__A_CORE_API__ layer* layer_new(void);
__A_CORE_API__ void   layer_on_attach(layer* layer);
__A_CORE_API__ void   layer_on_detach(layer* layer);
__A_CORE_API__ void   layer_on_update(layer* layer);
__A_CORE_API__ void   layer_on_event(layer* layer);
__A_CORE_API__ void   layer_free(layer* layer);

// ==============================================================================

#endif //CORE_LAYER_H