#include <inttypes.h>
#include <google/sparse_hash_map>
typedef google::sparse_hash_map<int64_t, int64_t> hash_t;
typedef google::sparse_hash_map<const char *, int64_t> str_hash_t;
#define SETUP hash_t hash; hash.set_deleted_key(-1); \
              str_hash_t str_hash; str_hash.set_deleted_key("");
#define INSERT_INT_INTO_HASH(key, value) hash.insert(hash_t::value_type(key, value))
#define DELETE_INT_FROM_HASH(key) hash.erase(key)
#define INSERT_STR_INTO_HASH(key, value) str_hash.insert(str_hash_t::value_type(key, value))
#define DELETE_STR_FROM_HASH(key) str_hash.erase(key)
#include "template.c"
