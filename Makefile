all: build/glib_hash_table build/stl_unordered_map build/boost_unordered_map build/google_sparse_hash_map build/google_dense_hash_map build/qt_qhash build/python_dict

build/glib_hash_table: src/glib_hash_table.c Makefile
	gcc -O2 `pkg-config --cflags --libs glib-2.0` src/glib_hash_table.c -o build/glib_hash_table

build/stl_unordered_map: src/stl_unordered_map.cc Makefile
	g++ -O2 src/stl_unordered_map.cc -o build/stl_unordered_map -std=c++0x

build/boost_unordered_map: src/boost_unordered_map.cc Makefile
	g++ -O2 src/boost_unordered_map.cc -o build/boost_unordered_map

build/google_sparse_hash_map: src/google_sparse_hash_map.cc Makefile
	g++ -O2 src/google_sparse_hash_map.cc -o build/google_sparse_hash_map

build/google_dense_hash_map: src/google_dense_hash_map.cc Makefile
	g++ -O2 src/google_dense_hash_map.cc -o build/google_dense_hash_map

build/qt_qhash: src/qt_qhash.cc Makefile
	g++ -O2 `pkg-config --cflags --libs QtCore` src/qt_qhash.cc -o build/qt_qhash

build/python_dict: src/python_dict.c Makefile
	gcc -O2 -I/usr/include/python2.6 -lpython2.6 src/python_dict.c -o build/python_dict
