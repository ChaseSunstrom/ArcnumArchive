#include "hashmap.h"

#include <stdint.h>
#include <stdlib.h>

#define ROTL64(x, r) ((x << r) | (x >> (64 - r)))

static inline u64 getblock64(const u64* p, u64 i) 
{
    return p[i];
}

static inline u64 fmix64(u64 k) 
{
    k ^= (k >> 33);
    k *= 0xff51afd7ed558ccd;
    k ^= (k >> 33);
    k *= 0xc4ceb9fe1a85ec53;
    k ^= (k >> 33);

    return k;
}

u64 _hash64(byte* _data, u64 len) 
{
    const byte* data = _data;
    const u64 nblocks = len / 16;

    u64 h = 0xDEADBEEFDEADBEEFULL;

    const u64 c1 = 0x87c37b91114253d5;
    const u64 c2 = 0x4cf5ad432745937f;

    const u64* blocks = (const u64*)(data);

    for (int i = 0; i < nblocks; i++) {
        u64 k1 = getblock64(blocks, i * 2 + 0);
        u64 k2 = getblock64(blocks, i * 2 + 1);

        k1 *= c1; k1 = ROTL64(k1, 31); k1 *= c2; h ^= k1;

        h = ROTL64(h, 27); h += h; h = h * 5 + 0x52dce729;

        k2 *= c2; k2 = ROTL64(k2, 33); k2 *= c1; h ^= k2;

        h = ROTL64(h, 31); h += h; h = h * 5 + 0x38495ab5;
    }
    const byte* tail = (const byte*)(data + nblocks * 16);

    u64 k1 = 0;

    switch (len & 15) {
    case 15: k1 ^= ((u64)tail[14]) << 48;
    case 14: k1 ^= ((u64)tail[13]) << 40;
    case 13: k1 ^= ((u64)tail[12]) << 32;
    case 12: k1 ^= ((u64)tail[11]) << 24;
    case 11: k1 ^= ((u64)tail[10]) << 16;
    case 10: k1 ^= ((u64)tail[9]) << 8;
    case  9: k1 ^= ((u64)tail[8]) << 0;

        k1 *= c2;
        k1 = ROTL64(k1, 33);
        k1 *= c1;
        h ^= k1;
        //break;

        // Buffer overflow here, no idea why
    //case  8: k1 ^= ((u64)tail[7]) << 56;
    //case  7: k1 ^= ((u64)tail[6]) << 48;
    //case  6: k1 ^= ((u64)tail[5]) << 40;
    //case  5: k1 ^= ((u64)tail[4]) << 32;
    //case  4: k1 ^= ((u64)tail[3]) << 24;
    //case  3: k1 ^= ((u64)tail[2]) << 16;
    //case  2: k1 ^= ((u64)tail[1]) << 8;
    //case  1: k1 ^= ((u64)tail[0]) << 0;

        k1 *= c1;
        k1 = ROTL64(k1, 31);
        k1 *= c2;
        h ^= k1;
        break;
    };

    h ^= len;

    h += h;
    h = fmix64(h);

    h += h;
    h = fmix64(h);

    return h;


}

u64* _hash128(byte* _data, u64 len) 
{
    const byte* data = _data;
    const u64 nblocks = len / 16;

    u64* out = malloc(sizeof(u64) * 2);

    u64 h1 = 0xDEADBEEFDEADBEEFULL;
    u64 h2 = 0xDEADBEEFDEADBEEFULL;

    const u64 c1 = 0x87c37b91114253d5;
    const u64 c2 = 0x4cf5ad432745937f;

    const u64* blocks = (const u64*)(data);

    for (int i = 0; i < nblocks; i++) {
        u64 k1 = getblock64(blocks, i * 2 + 0);
        u64 k2 = getblock64(blocks, i * 2 + 1);

        k1 *= c1; k1 = ROTL64(k1, 31); k1 *= c2; h1 ^= k1;

        h1 = ROTL64(h1, 27); h1 += h2; h1 = h1 * 5 + 0x52dce729;

        k2 *= c2; k2 = ROTL64(k2, 33); k2 *= c1; h2 ^= k2;

        h2 = ROTL64(h2, 31); h2 += h1; h2 = h2 * 5 + 0x38495ab5;
    }

    const byte* tail = (const byte*)(data + nblocks * 16);

    u64 k1 = 0;
    u64 k2 = 0;

    switch (len & 15) {
    case 15: k2 ^= ((u64)tail[14]) << 48;
    case 14: k2 ^= ((u64)tail[13]) << 40;
    case 13: k2 ^= ((u64)tail[12]) << 32;
    case 12: k2 ^= ((u64)tail[11]) << 24;
    case 11: k2 ^= ((u64)tail[10]) << 16;
    case 10: k2 ^= ((u64)tail[9]) << 8;
    case  9: k2 ^= ((u64)tail[8]) << 0;
        k2 *= c2; k2 = ROTL64(k2, 33); k2 *= c1; h2 ^= k2;

    case  8: k1 ^= ((u64)tail[7]) << 56;
    case  7: k1 ^= ((u64)tail[6]) << 48;
    case  6: k1 ^= ((u64)tail[5]) << 40;
    case  5: k1 ^= ((u64)tail[4]) << 32;
    case  4: k1 ^= ((u64)tail[3]) << 24;
    case  3: k1 ^= ((u64)tail[2]) << 16;
    case  2: k1 ^= ((u64)tail[1]) << 8;
    case  1: k1 ^= ((u64)tail[0]) << 0;
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

entry* entry_new(generic key, generic value)
{
    entry* _entry = ALLOC(entry);
    _entry->key = key;
	_entry->value = value;
	_entry->next = NULL;
	return _entry;
}

 bool _hashmap_compare_keys(byte* key1, byte* key2, u64 key_size)
{
    byte* k1_b = key1;
	byte* k2_b = key2;

    for (u64 i = 0; i < key_size; i++)
        if (k1_b[i] != k2_b[i])
            return false;
    return true;
}

hashmap(generic, generic) hashmap_default()
{
    hashmap(generic, generic) hmap = ALLOC(_hashmap);
    hmap->size = 0;
    hmap->buckets = vector_default();
    return hmap;
}

hashmap(generic, generic) _hashmap_new(entry* entries, u64 num_entries)
{
	hashmap(generic, generic) hmap = hashmap_default();
    _hashmap_insert_entries(hmap, entries, num_entries);
	return hmap;
}

void hashmap_insert(hashmap(generic, generic) hmap, byte* key, byte* value)
{
    hmap->size++;
    u64 hash = hash64(key);
    u64 index = hash % hmap->size;

    entry* new_entry = entry_new(key, value);

    entry* current = vector_get(hmap->buckets, index);

    if (current == NULL) 
        vector_insert(hmap->buckets, index, new_entry);
    
    else 
    {
        while (current->next != NULL)
            current = current->next;
        
        current->next = new_entry;
    }
}

void _hashmap_insert_entries(hashmap(generic, generic) hmap, entry* entries, u64 num_entries)
{
    for (u64 i = 0; i < num_entries; ++i)
        hashmap_insert(hmap, entries[i].key, entries[i].value);
}

void hashmap_remove(hashmap(generic, generic) hmap, generic key)
{
    u64 index = hash64(key) % hmap->size;

    // Locate the bucket
    entry* current = vector_get(hmap->buckets, index);
    entry* prev = NULL;

    // Search for the entry in the linked list
    while (current != NULL)
    {
        if (hashmap_compare_keys(current->key, key))
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

generic hashmap_get(hashmap(generic, generic) hmap, byte* key)
{
    u64 index = hash64(key) % hmap->size;

    // Search for the entry in the bucket
    entry* current = vector_get(hmap->buckets, index);

    while (current != NULL) 
    {
        if (hashmap_compare_keys(current->key, key)) 
            return current->value;

        current = current->next;
    }

    // Key not found
    return NULL;
}