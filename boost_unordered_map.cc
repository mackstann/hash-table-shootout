#include <boost/unordered_map.hpp>
typedef boost::unordered_map<int, int> hash_t;
#define SETUP hash_t hash;
#define INSERT_INTO_HASH(key, value) hash.insert(hash_t::value_type(key, value))
#include "template.c"
