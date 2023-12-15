#include "../util/memory/alloc.h"
#include "layer.h"

__AC_CORE_API__ layer* layer_new()
{
	layer* _layer = ALLOC(layer);
	_layer->name = "LAYER";
	return _layer;
}

__AC_CORE_API__ void layer_on_update(layer* layer)
{
}