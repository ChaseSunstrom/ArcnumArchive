#include "../util/memory/alloc.h"
#include "sub.h"

#include "event.h"

// Vector of current subscriptions
__A_CORE_API__ static subscription** subscriptions = NULL;
__A_CORE_API__ static uint64_t       subscription_count = 0;

// ===============================================================
// SUBSCRIPTION AND PUBLISHER FUNCTIONS:

__A_CORE_API__ subscription* subscription_new(subscription_topic topic, on_publish on_publish_function)
{
	subscription* _subscription = ALLOC(subscription);
	_subscription->subscription_id = subscription_count++; 
	_subscription->topic = topic;
	_subscription->on_publish_function = on_publish_function;
	subscriptions = REALLOC(subscriptions, subscription, subscription_count);
	subscriptions[_subscription->subscription_id] = _subscription;
	return _subscription;
}

__A_CORE_API__ bool subscription_unsubscribe(subscription* subscription)
{
	if (subscription == NULL) return false;
	if (subscription->subscription_id >= subscription_count) return false;

	free(subscription);
	return true;
}

__A_CORE_API__ void publish(subscription_topic topic, void* value)
{
	publisher publisher = { .topic = topic, .value = value };

	for (int32_t i = 0; i < subscription_count; i++) {
		subscription* subscription = subscriptions[i];
		if (subscription == NULL || subscription->topic != topic) continue;
		subscription->on_publish_function(publisher.value);
	}
}

// ===============================================================