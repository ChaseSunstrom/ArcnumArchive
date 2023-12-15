#include "../util/memory/alloc.h"
#include "sub.h"

#include "event.h"

// Vector of current subscriptions
AC_CORE_API static subscription** subscriptions = NULL;
AC_CORE_API static u32            subscription_count = 0;

// ===============================================================
// SUBSCRIPTION AND PUBLISHER FUNCTIONS:

AC_CORE_API subscription* subscription_new(subscription_topic topic, on_publish on_publish_function)
{
	subscription* _subscription = ALLOC(subscription);
	_subscription->subscription_id = subscription_count++; 
	_subscription->topic = topic;
	_subscription->on_publish_function = on_publish_function;
	subscriptions = REALLOC(subscriptions, subscription, subscription_count);
	subscriptions[_subscription->subscription_id] = _subscription;
	return _subscription;
}

AC_CORE_API bool subscription_unsubscribe(subscription* subscription)
{
	if (subscription == NULL) return false;
	if (subscription->subscription_id >= subscription_count) return false;

	FREE(subscription);
	return true;
}

AC_CORE_API void publish(subscription_topic topic, void* value)
{
	publisher publisher = { .topic = topic, .value = value };

	for (i32 i = 0; i < subscription_count; i++) {
		subscription* subscription = subscriptions[i];
		if (subscription == NULL || subscription->topic != topic) continue;
		subscription->on_publish_function(publisher.value);
	}
}

// ===============================================================