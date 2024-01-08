#include "hashmap.h"

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

uint64_t _hash64(byte* _data, uint64_t len) 
{
    const byte* data = _data;
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
    const byte* tail = (const byte*)(data + nblocks * 16);

    uint64_t k1 = 0;

    switch (len & 15) 
    {
    case 15: k1 ^= ((uint64_t)tail[14]) << 48;
    case 14: k1 ^= ((uint64_t)tail[13]) << 40;
    case 13: k1 ^= ((uint64_t)tail[12]) << 32;
    case 12: k1 ^= ((uint64_t)tail[11]) << 24;
    case 11: k1 ^= ((uint64_t)tail[10]) << 16;
    case 10: k1 ^= ((uint64_t)tail[9]) << 8;
    case  9: k1 ^= ((uint64_t)tail[8]) << 0;

        k1 *= c2;
        k1 = ROTL64(k1, 33);
        k1 *= c1;
        h ^= k1;
    };

    h ^= len;

    h += h;
    h = fmix64(h);

    h += h;
    h = fmix64(h);

    return h;
}

uint64_t* _hash128(byte* _data, uint64_t len) 
{
    const byte* data = _data;
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

    const byte* tail = (const byte*)(data + nblocks * 16);

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

 bool hashmap_compare_keys(byte* key1, byte* key2, uint64_t key_size)
{
    byte* k1_b = key1;
	byte* k2_b = key2;

    for (uint64_t i = 0; i < key_size; i++)
        if (k1_b[i] != k2_b[i])
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

void hashmap_insert(hashmap(void*, void*) hmap, byte* key, byte* value, uint64_t key_size)
{
    uint64_t index;
    uint64_t hash = hash64(key);
    if (hmap->size == 0)
        index = 0;  // or any other default index when size is zero
    else
        index = hash % hmap->size;

    entry* new_entry = entry_new(key, value, key_size);

    entry* current = vector_get(hmap->buckets, index);

    if (!current) 
        vector_assign_data(hmap->buckets, new_entry, index);
    
    else 
    {
        while (current->next)
            current = current->next;
        
        current->next = new_entry;
    }
    hmap->size++;
}

void _hashmap_insert_entries(hashmap(void*, void*) hmap, entry* entries, uint64_t num_entries, uint64_t key_sizes[])
{
    for (uint64_t i = 0; i < num_entries; ++i)
        hashmap_insert(hmap, entries[i].key, entries[i].value, key_sizes[i]);
}

void _hashmap_inserts(hashmap(void*, void*) hmap, void* keys[], void* values[], uint64_t num_entries, uint64_t key_sizes[])
{
    for (uint64_t i = 0; i < num_entries; i++)
		hashmap_insert(hmap, keys[i], values[i], key_sizes[i]);
}

void hashmap_remove(hashmap(void*, void*) hmap, void* key, uint64_t key_size)
{
    uint64_t index = hash64(key) % hmap->size;

    // Locate the bucket
    entry* current = vector_get(hmap->buckets, index);
    entry* prev = NULL;

    // Search for the entry in the linked list
    while (current != NULL)
    {
        if (hashmap_compare_keys(current->key, key, key_size))
        {
            // Entry found, remove it from the linked list
            if (prev != NULL)
                prev->next = current->next;
            else
                vector_assign_data(hmap->buckets, current->next, index);

            // Free the memory occupied by the entry
            free(current);
            hmap->size--;

            vector_remove(hmap->buckets, index);

            return;  // Entry removed, exit the function
        }

        // Move to the next entry in the linked list
        prev = current;
        current = current->next;
    }
}

void* hashmap_get(hashmap(void*, void*) hmap, byte* key, uint64_t key_size)
{
    uint64_t index;
	uint64_t hash = hash64(key);

    if (hmap->size == 0)
        index = 0;  // or any other default index when size is zero
    else
        index = hash % hmap->size;

    // Search for the entry in the bucket
    entry* current = vector_get(hmap->buckets, index);

    while (current != NULL) 
    {
        if (hashmap_compare_keys(current->key, key, key_size)) 
            return current->value;

        current = current->next;
    }

    // Key not found
    return NULL;
}