#ifndef CORE_SUB_H
#define CORE_SUB_H

#include "../util/data/vector.h"

typedef enum
{
	NO_TOPIC,
	EVENT_TOPIC
} topic;

typedef struct
{
	topic topic;
	void* value;
} publisher;

typedef void (*on_publish)(publisher);

typedef struct
{
	unsigned int subscription_id;
	topic topic;
	on_publish on_publish_function;
} subscription;

subscription* subscription_new(topic topic, on_publish on_publish_function);
bool          subscription_unsubscribe(subscription* subscription);
int           publish(topic topic, void* value);

#endif