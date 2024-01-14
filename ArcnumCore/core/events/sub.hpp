#ifndef CORE_SUB_H
#define CORE_SUB_H

#include "../core.hpp"

#include "event.hpp"

namespace ac
{
	static uint64_t subscription_count = 0;

	__A_CORE_API__ enum class subscription_topic
	{
		NONE = 0,
		WINDOW_EVENT,
		RENDERER_EVENT,
		APP_EVENT,
		INPUT_EVENT,
	};

	template <typename T>
	void publish(subscription_topic topic, std::shared_ptr<T> value);

	// ===============================================================
	// SUBSCRIPTION: | Used to hold a publisher function and to store
	//				 | data related to publishers
	// ===============================================================

	struct base_subscription
	{

	};

	template <typename T>
	struct subscription : base_subscription, std::enable_shared_from_this<subscription<T>>
	{
		subscription(subscription_topic topic, std::function<void(T)> on_publish_function)
			: m_subscription_id(subscription_count++),
			m_topic(topic),
			m_on_publish_function(on_publish_function)
		{
			subscriptions.push_back(shared_from_this());
		}

		bool unsubscribe();

		uint64_t m_subscription_id;
		subscription_topic m_topic;
		std::function<void(T)> m_on_publish_function;
	};
}

#endif // CORE_SUB_H