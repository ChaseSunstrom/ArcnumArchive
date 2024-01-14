#include "event.hpp"

namespace ac
{
	template <typename T>
	__A_CORE_API__ bool event_dispatcher::dispatch(std::function<bool(event)> fn)
	{
		if (T == m_event->m_type)
		{
			m_event->handled = fn(m_event);

			return true;
		}

		return false;
	}
}