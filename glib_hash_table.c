#include <glib.h>
typedef GHashTable * hash_t;
#define SETUP hash_t hash = g_hash_table_new(g_direct_hash, g_direct_equal);
#define INSERT_INTO_HASH(key, value) g_hash_table_insert(hash, GINT_TO_POINTER(key), &value)
#include "template.c"
