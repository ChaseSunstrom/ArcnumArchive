#include "../util/memory/alloc.h"
#include "sub.h"

subscription** subscriptions = NULL;
unsigned int subscription_count = 0;

subscription* subscription_new(topic topic, on_publish on_publish_function)
{
	subscription* _subscription = ALLOC(subscription);
	_subscription->subscription_id = subscription_count++; 
	_subscription->topic = topic;
	_subscription->on_publish_function = on_publish_function;
	subscriptions = REALLOC(subscriptions, subscription, subscription_count);
	subscriptions[_subscription->subscription_id] = _subscription;
	return _subscription;
}

bool subscription_unsubscribe(subscription* subscription)
{
	if (subscription == NULL) return false;
	if (subscription->subscription_id >= subscription_count) return false;

	FREE(subscription);
	return true;
}

int publish(topic topic, void* value)
{
	publisher publisher = { .topic = topic, .value = value };

	int sent = 0;

	for (int i = 0; i < subscription_count; i++) {
		subscription* subscription = subscriptions[i];
		if (subscription == NULL || subscription->topic != topic) continue;
		subscription->on_publish_function(publisher);
		sent++;
	}
	return sent;
}
