#ifndef CORE_SUB_H
#define CORE_SUB_H

#include "event.h"
#include "../util/data/vector.h"


// ===============================================================
// TOPIC:      | Used to store the subscription and publisher subscription_topic
// ===============================================================
__A_CORE_API__ typedef enum
{
	NO_TOPIC,
	WINDOW_EVENT_TOPIC
} subscription_topic;



// ===============================================================
// PUBLISHER:  | Used to hold a value that will be used in the function
//             | that subscription holds
// ===============================================================
__A_CORE_API__ typedef struct
{
	subscription_topic topic;
	void* value;
} publisher;



// Function pointer to any function the subscription will hold
__A_CORE_API__ typedef void (*on_publish)(void*);



// ===============================================================
// SUBSCRIPTION: | Used to hold a publisher function and to store
//				 | data related to publishers
// ===============================================================
__A_CORE_API__ typedef struct
{
	uint32_t subscription_id;
	subscription_topic topic;
	on_publish on_publish_function;
} subscription;



// ===============================================================
// SUBSCRIPTION AND PUBLISHER FUNCTIONS:

__A_CORE_API__ subscription* subscription_new(subscription_topic topic, on_publish on_publish_function);
__A_CORE_API__ bool          subscription_unsubscribe(subscription* subscription);
__A_CORE_API__ void          publish(subscription_topic topic, void* value);

// ===============================================================

#endif // CORE_SUB_H