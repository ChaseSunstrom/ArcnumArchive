#include "sub.hpp"

namespace ac
{
	__A_CORE_API__ void publish_to_topic(subscription_topic topic, std::any value)
	{
		for (auto& sub : subscriptions)
		{
			std::cout << sub->m_subscription_id << std::endl;

			if (sub->m_topic == topic)
				sub->publish(topic, value);
		}
	}
}