#include "hashmap.h"
#include "../logging/log.h"

#include <stdint.h>
#include <stdlib.h>

#define ROTL64(x, r) ((x << r) | (x >> (64 - r)))

static inline uint64_t getblock64(const uint64_t* p, uint64_t i) 
{
    return p[i];
}

static inline uint64_t fmix64(uint64_t k) 
{
    k ^= (k >> 33);
    k *= 0xff51afd7ed558ccd;
    k ^= (k >> 33);
    k *= 0xc4ceb9fe1a85ec53;
    k ^= (k >> 33);

    return k;
}

uint64_t hash64(ubyte* _data, uint64_t len) 
{
    const ubyte* data = _data;
    const uint64_t nblocks = len / 16;

    uint64_t h = 0xDEADBEEFDEADBEEFULL;

    const uint64_t c1 = 0x87c37b91114253d5;
    const uint64_t c2 = 0x4cf5ad432745937f;

    const uint64_t* blocks = (const uint64_t*)(data);

    for (int i = 0; i < nblocks; i++) 
    {
        uint64_t k1 = getblock64(blocks, i * 2 + 0);
        uint64_t k2 = getblock64(blocks, i * 2 + 1);

        k1 *= c1; k1 = ROTL64(k1, 31); k1 *= c2; h ^= k1;

        h = ROTL64(h, 27); h += h; h = h * 5 + 0x52dce729;

        k2 *= c2; k2 = ROTL64(k2, 33); k2 *= c1; h ^= k2;

        h = ROTL64(h, 31); h += h; h = h * 5 + 0x38495ab5;
    }
    const ubyte* tail = (const ubyte*)(data + nblocks * 16);

    uint64_t k1 = 0;
    switch (len & 15)
    {
    case 15: k1 ^= ((uint64_t)tail[14]) << 48; // fall through
    case 14: k1 ^= ((uint64_t)tail[13]) << 40; // fall through
    case 13: k1 ^= ((uint64_t)tail[12]) << 32; // fall through
    case 12: k1 ^= ((uint64_t)tail[11]) << 24; // fall through
    case 11: k1 ^= ((uint64_t)tail[10]) << 16; // fall through
    case 10: k1 ^= ((uint64_t)tail[9]) << 8; // fall through
    case  9: k1 ^= ((uint64_t)tail[8]) << 0;
        k1 *= c2; k1 = ROTL64(k1, 33); k1 *= c1; h ^= k1;
        break;
    case  8: k1 ^= ((uint64_t)tail[7]) << 56; // fall through
    case  7: k1 ^= ((uint64_t)tail[6]) << 48; // fall through
    case  6: k1 ^= ((uint64_t)tail[5]) << 40; // fall through
    case  5: k1 ^= ((uint64_t)tail[4]) << 32; // fall through
    case  4: k1 ^= ((uint64_t)tail[3]) << 24; // fall through
    case  3: k1 ^= ((uint64_t)tail[2]) << 16; // fall through
    case  2: k1 ^= ((uint64_t)tail[1]) << 8; // fall through
    case  1: k1 ^= ((uint64_t)tail[0]) << 0;
        k1 *= c1; k1 = ROTL64(k1, 31); k1 *= c2; h ^= k1;
        break;
    }

    // Finalization
    h ^= len;
    h = fmix64(h);

    return h;
}

uint64_t* hash128(ubyte* _data, uint64_t len) 
{
    const ubyte* data = _data;
    const uint64_t nblocks = len / 16;

    uint64_t* out = malloc(sizeof(uint64_t) * 2);

    uint64_t h1 = 0xDEADBEEFDEADBEEFULL;
    uint64_t h2 = 0xDEADBEEFDEADBEEFULL;

    const uint64_t c1 = 0x87c37b91114253d5;
    const uint64_t c2 = 0x4cf5ad432745937f;

    const uint64_t* blocks = (const uint64_t*)(data);

    for (int i = 0; i < nblocks; i++) {
        uint64_t k1 = getblock64(blocks, i * 2 + 0);
        uint64_t k2 = getblock64(blocks, i * 2 + 1);

        k1 *= c1; k1 = ROTL64(k1, 31); k1 *= c2; h1 ^= k1;

        h1 = ROTL64(h1, 27); h1 += h2; h1 = h1 * 5 + 0x52dce729;

        k2 *= c2; k2 = ROTL64(k2, 33); k2 *= c1; h2 ^= k2;

        h2 = ROTL64(h2, 31); h2 += h1; h2 = h2 * 5 + 0x38495ab5;
    }

    const ubyte* tail = (const ubyte*)(data + nblocks * 16);

    uint64_t k1 = 0;
    uint64_t k2 = 0;

    switch (len & 15) {
    case 15: k2 ^= ((uint64_t)tail[14]) << 48;
    case 14: k2 ^= ((uint64_t)tail[13]) << 40;
    case 13: k2 ^= ((uint64_t)tail[12]) << 32;
    case 12: k2 ^= ((uint64_t)tail[11]) << 24;
    case 11: k2 ^= ((uint64_t)tail[10]) << 16;
    case 10: k2 ^= ((uint64_t)tail[9]) << 8;
    case  9: k2 ^= ((uint64_t)tail[8]) << 0;
        k2 *= c2; k2 = ROTL64(k2, 33); k2 *= c1; h2 ^= k2;

    case  8: k1 ^= ((uint64_t)tail[7]) << 56;
    case  7: k1 ^= ((uint64_t)tail[6]) << 48;
    case  6: k1 ^= ((uint64_t)tail[5]) << 40;
    case  5: k1 ^= ((uint64_t)tail[4]) << 32;
    case  4: k1 ^= ((uint64_t)tail[3]) << 24;
    case  3: k1 ^= ((uint64_t)tail[2]) << 16;
    case  2: k1 ^= ((uint64_t)tail[1]) << 8;
    case  1: k1 ^= ((uint64_t)tail[0]) << 0;
        k1 *= c1; k1 = ROTL64(k1, 31); k1 *= c2; h1 ^= k1;
    };

    h1 ^= len; h2 ^= len;

    h1 += h2;
    h2 += h1;

    h1 = fmix64(h1);
    h2 = fmix64(h2);

    h1 += h2;
    h2 += h1;

    out[0] = h1;
    out[1] = h2;

    return out;
}

entry* entry_new(void* key, void* value, uint64_t key_size)
{
    entry* _entry = ALLOC(entry);
    _entry->key = key;
	_entry->value = value;
	_entry->next = NULL;
    _entry->key_size = key_size;
	return _entry;
}

void _entry_free(entry* current_entry, void (*key_free)(void*), void (*value_free)(void*))
{  
    if (key_free && value_free)
        goto FREE_BOTH;

    else if (key_free)
        goto FREE_KEY;

    else if (value_free)
        goto FREE_VALUE;

    else
        goto FREE;

FREE_BOTH:
    while (current_entry)
    {
        key_free(current_entry->key);
	    value_free(current_entry->value);

        entry* next = current_entry->next;

        free(current_entry);

        current_entry = next;
    }
    return;

FREE_KEY:
    while (current_entry)
    {
        key_free(current_entry->key);
        
        entry* next = current_entry->next;

        free(current_entry);

        current_entry = next;
    }
    return;

FREE_VALUE:
    while (current_entry)
    {
        value_free(current_entry->value);

        entry* next = current_entry->next;

        free(current_entry);

        current_entry = next;
    }
    return;

FREE:
    while (current_entry)
    {
        entry* next = current_entry->next;

        free(current_entry);

        current_entry = next;
    }
}

bool hashmap_compare_keys(ubyte* key1, ubyte* key2, uint64_t key_size)
{
    ubyte* k1_b = key1;
	ubyte* k2_b = key2;

    for (uint64_t i = 0; i < key_size; i++)
        if (key1[i] != key2[i])
            return false;

    return true;
}

hashmap(void*, void*) hashmap_default()
{
    hashmap(void*, void*) hmap = ALLOC(_hashmap);
    hmap->size = 0;
    hmap->buckets = vector_default();
    return hmap;
}

hashmap(void*, void*) _hashmap_new(entry* entries, uint64_t num_entries, uint64_t key_sizes[])
{
	hashmap(void*, void*) hmap = hashmap_default();
    _hashmap_insert_entries(hmap, entries, num_entries, key_sizes);
	return hmap;
}

void hashmap_insert(hashmap(void*, void*) hmap, ubyte* key, ubyte* value, uint64_t key_size)
{
    const uint64_t default_buckets_count = 16;

    if (hmap->size == 0) 
    {
        // Initialize the hash map with a default number of buckets
        hmap->buckets = vector_news(default_buckets_count);

		for (uint64_t i = 0; i < default_buckets_count; i++)
			vector_assign_data(hmap->buckets, NULL, i);

        hmap->size = default_buckets_count;
    }

    uint64_t hash = hash64(key, key_size);
    uint64_t index = hash % hmap->size;

    entry* new_entry = entry_new(key, value, key_size);

    entry* head = vector_get(hmap->buckets, index);

    if (!head) 
        // If the bucket is empty, place the new entry there
        vector_assign_data(hmap->buckets, new_entry, index);
   
    else 
    {
        // If the bucket is not empty, append the new entry to the end of the list
        entry* current = head;

        while (current->next)
            current = current->next;
       
        current->next = new_entry;
    }
}

void _hashmap_insert_entries(hashmap(void*, void*) hmap, entry entries[], uint64_t num_entries, uint64_t key_sizes[])
{
    for (uint64_t i = 0; i < num_entries; ++i)
        hashmap_insert(hmap, entries[i].key, entries[i].value, key_sizes[i]);
}

void _hashmap_insert_entriess(hashmap(void*, void*) hmap, entry entries[], uint64_t num_entries, uint64_t key_sizes)
{
    for (uint64_t i = 0; i < num_entries; ++i)
        hashmap_insert(hmap, entries[i].key, entries[i].value, key_sizes);
}

void _hashmap_inserts(hashmap(void*, void*) hmap, void* keys[], void* values[], uint64_t num_entries, uint64_t key_sizes[])
{
    for (uint64_t i = 0; i < num_entries; i++)
		hashmap_insert(hmap, keys[i], values[i], key_sizes[i]);
}

void _hashmap_insertss(hashmap(void*, void*) hmap, void* keys[], void* values[], uint64_t num_entries, uint64_t key_sizes)
{
    for (uint64_t i = 0; i < num_entries; i++)
        hashmap_insert(hmap, keys[i], values[i], key_sizes);
}

void hashmap_remove(hashmap(void*, void*) hmap, void* key, uint64_t key_size) {
    if (hmap->size == 0) {
        // Handle the case when the hash map is empty
        return;
    }

    uint64_t index = hash64(key, key_size) % hmap->size;
    entry* current = vector_get(hmap->buckets, index);
    entry* prev = NULL;

    while (current) {
        if (hashmap_compare_keys(current->key, key, key_size)) {
            if (prev != NULL) {
                prev->next = current->next;
            }
            else {
                vector_assign_data(hmap->buckets, current->next, index);
            }
            free(current);
            return;  // Entry removed
        }
        prev = current;
        current = current->next;
    }
}

void* hashmap_get(hashmap(void*, void*) hmap, ubyte* key, uint64_t key_size)
{
    if (hmap->size == 0)
        return NULL;  // The hash map is empty, so the key cannot be present

    uint64_t hash = hash64(key, key_size);
    uint64_t index = hash % hmap->size;

    // Search for the entry in the bucket
    entry* current = vector_get(hmap->buckets, index);

    uint64_t i = 0; // Counter to track position in the bucket
    while (current)
    {
        if (hashmap_compare_keys(current->key, key, key_size))
            return current->value;

        current = current->next;
        ++i;
    }

    return NULL;
}


void _hashmap_free(hashmap(void*, void*) hmap, void (*key_free)(void*), void (*value_free)(void*))
{
    for (uint64_t index = 0; index < hmap->size; index++)
    {
		entry* current = vector_get(hmap->buckets, index);

        _entry_free(current, key_free, value_free);
    }
}

void hashmap_free_d(hashmap(void*, void*) hmap)
{
    for (uint64_t index = 0; index < hmap->size; index++)
    {
        entry* current = vector_get(hmap->buckets, index);

        entry_free_d(current);
    }
}