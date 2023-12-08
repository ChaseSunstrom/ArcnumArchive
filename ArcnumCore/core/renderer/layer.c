#include "../util/memory/alloc.h"
#include "layer.h"

layer* layer_new()
{
	layer* _layer = ALLOC(layer);
	_layer->name = "LAYER";
	return _layer;
}

void layer_on_update(layer* layer)
{
}