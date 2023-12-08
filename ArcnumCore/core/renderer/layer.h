#ifndef CORE_LAYER_H
#define CORE_LAYER_H


// ==============================================================================
// LAYER:        | Used for the _renderer 
// ==============================================================================

typedef struct
{
	char* name;
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