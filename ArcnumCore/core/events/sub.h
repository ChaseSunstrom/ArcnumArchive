#ifndef CORE_SUB_H
#define CORE_SUB_H

#include "event.h"
#include "../util/data/vector.h"


// ===============================================================
// TOPIC:      | Used to store the subscription and publisher subscription_topic
// ===============================================================
typedef enum
{
	NO_TOPIC,
	WINDOW_EVENT_TOPIC
} subscription_topic;



// ===============================================================
// PUBLISHER:  | Used to hold a value that will be used in the function
//             | that subscription holds
// ===============================================================
typedef struct
{
	subscription_topic topic;
	T value;
} publisher;



// Function pointer to any function the subscription will hold
typedef void (*on_publish)(T);



// ===============================================================
// SUBSCRIPTION: | Used to hold a publisher function and to store
//				 | data related to publishers
// ===============================================================
typedef struct
{
	u32 subscription_id;
	subscription_topic topic;
	on_publish on_publish_function;
} subscription;



// ===============================================================
// SUBSCRIPTION AND PUBLISHER FUNCTIONS:

subscription* subscription_new(subscription_topic topic, on_publish on_publish_function);
bool          subscription_unsubscribe(subscription* subscription);
void          publish(subscription_topic topic, T value);

// ===============================================================

#endif // CORE_SUB_H