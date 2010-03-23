#include <google/dense_hash_map>
typedef google::dense_hash_map<int, int> hash_t;
#define SETUP hash_t hash; hash.set_empty_key(-1);
#define INSERT_INTO_HASH(key, value) hash.insert(hash_t::value_type(key, value))
#include "template.c"
