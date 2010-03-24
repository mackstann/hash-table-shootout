#include <inttypes.h>
#include <google/sparse_hash_map>
typedef google::sparse_hash_map<int64_t, int64_t> hash_t;
#define SETUP hash_t hash; hash.set_deleted_key(-1);
#define INSERT_INTO_HASH(key, value) hash.insert(hash_t::value_type(key, value))
#define DELETE_FROM_HASH(key) hash.erase(key)
#include "template.c"
