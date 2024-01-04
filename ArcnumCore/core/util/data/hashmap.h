#ifndef CORE_HASHMAP_H
#define CORE_HASHMAP_H

#include "../memory/alloc.h"

#include "types.h"

typedef struct entry
{
	byte* key;
	byte* value;
	struct entry* next;
} entry;

typedef struct
{
	u64 size;
	u64 capacity;
	entry** buckets;
} _hashmap;

#define hashmap(_key, _value) _hashmap*

// =================================================================
// HASH FUNCTIONS:

u64  _hash64(byte* _data, u64 size);
u64* _hash128(byte* _data, u64 size);
u64  getblock64(const u64* p, u64 i);
u64  fmix64(u64 k);

#define hash64(_data)  _hash64(_data, sizeof(_data))
#define hash128(_data) _hash128(_data, sizeof(_data))

// =================================================================

entry* entry_new(generic key, generic value);

hashmap(generic, generic) hashmap_default();
hashmap(generic, generic) _hashmap_new(entry* entries, u64 num_entries);
void                      hashmap_free(hashmap(generic, generic) hmap);
void                      hashmap_insert(hashmap(generic, generic) hmap, byte* key, byte* value);
void                      _hashmap_insert_entries(hashmap(generic, generic) hmap, entry* entries, u64 num_entries);
void                      hashmap_remove(hashmap(generic, generic) hmap, byte* key);
generic                   hashmap_get(hashmap(generic, generic) hmap, byte* key);
bool                      _hashmap_compare_keys(byte* key1, byte* key2, u64 key_size);

#define hashmap_insert_entries(_hmap, _entries) _hashmap_insert_entries(_hmap, _entries, sizeof(_entries) / sizeof(_entries[0]))
#define hashmap_new(_entries) _hashmap_new(_entries, sizeof(_entries) / sizeof(_entries[0]))
#define hashmap_compare_keys(_key1, _key2) _hashmap_compare_keys(_key1, _key2, sizeof(_key1) / sizeof(_key1[0]))

#endif // CORE_HASH_H