#include <Python.h>
typedef PyObject * hash_t;
#define SETUP \
    Py_Initialize(); \
    hash_t hash = PyDict_New(); \
    PyObject * py_int_value = PyInt_FromLong(0);
#define INSERT_INT_INTO_HASH(key, value) do { \
        PyObject * py_int_key = PyInt_FromLong(key); /* leak */ \
        PyDict_SetItem(hash, py_int_key, py_int_value); \
    } while(0)
#define DELETE_INT_FROM_HASH(key) do { \
        PyObject * py_int_key = PyInt_FromLong(key); /* leak */ \
        PyDict_DelItem(hash, py_int_key); \
    } while(0)
#define INSERT_STR_INTO_HASH(key, value) do { \
        PyDict_SetItemString(hash, key, py_int_value); \
    } while(0)
#define DELETE_STR_FROM_HASH(key) do { \
        PyDict_DelItemString(hash, key); \
    } while(0)
#include "template.c"
