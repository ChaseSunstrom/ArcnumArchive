#include "event.h"

bool event_dispatcher_dispatch(event_dispatcher dispatcher, void* function_to_call, generic_event* e)
{
	if (dispatcher.event->type == e->type)
	{
		EVENT_FUNCTION_PTR(function_to_call, event_function);
		dispatcher.event->handled = event_function(dispatcher.event);

		return true;
	}

	return false;
}