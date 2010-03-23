#include <QHash>
typedef QHash<int, int> hash_t;
#define SETUP hash_t hash;
#define INSERT_INTO_HASH(key, value) hash.insert(key, value)
#include "template.c"
