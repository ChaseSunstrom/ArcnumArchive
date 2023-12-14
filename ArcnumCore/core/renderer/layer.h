#ifndef CORE_LAYER_H
#define CORE_LAYER_H

typedef enum
{
	WINDOW_LAYER,
	RENDERER_LAYER,
	ENTITY_LAYER,
} layer_type;



// ==============================================================================
// LAYER:        | Used for the _renderer 
// ==============================================================================
typedef struct
{
	string name;
} layer;



// ==============================================================================
// LAYER FUNCTIONS:

layer* layer_new(void);
void   layer_on_attach(layer* layer);
void   layer_on_detach(layer* layer);
void   layer_on_update(layer* layer);
void   layer_on_event(layer* layer);
void   layer_free(layer* layer);

// ==============================================================================

#endif //CORE_LAYER_H