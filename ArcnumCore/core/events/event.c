#include "event.h"

bool event_dispatcher_dispatch(event_dispatcher dispatcher, void* function_to_call)
{
	// Checks if the type is greater than 0 which will be anything except 'NO_TYPE'
	if (dispatcher.event->type)
	{
		EVENT_FUNCTION_PTR(event_function, function_to_call);
		dispatcher.event->handled = event_function(dispatcher.event);

		return true;
	}

	return false;
}