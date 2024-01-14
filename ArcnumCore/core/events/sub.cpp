#include "sub.hpp"

namespace ac
{
	static auto subscriptions = std::vector<std::shared_ptr<base_subscription>>();

	template <typename T>
	void publish(subscription_topic topic, std::shared_ptr<T> value) 
	{
		for (auto& sub : subscriptions) 
			if (sub->m_topic == topic)
				sub->m_on_publish_function(value);
	}

	template <typename T>
	bool subscription<T>::unsubscribe() 
	{
		auto it = std::find_if(subscriptions.begin(), subscriptions.end(),
			[this](const std::shared_ptr<subscription<T>>& sub) 
			{
				return sub->m_subscription_id == m_subscription_id;
			});

		if (it != subscriptions.end()) 
		{
			subscriptions.erase(it);
			return true;
		}

		return false;
	}
}