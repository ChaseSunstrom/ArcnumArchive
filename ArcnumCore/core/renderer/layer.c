#include "../util/memory/alloc.h"
#include "layer.h"

AC_CORE_API layer* layer_new()
{
	layer* _layer = ALLOC(layer);
	_layer->name = "LAYER";
	return _layer;
}

AC_CORE_API void layer_on_update(layer* layer)
{
}