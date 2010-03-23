all: glib_hash_table stl_unordered_map boost_unordered_map google_sparse_hash_map google_dense_hash_map qt_qhash python_dict

glib_hash_table: glib_hash_table.c Makefile
	gcc -O2 `pkg-config --cflags --libs glib-2.0` glib_hash_table.c -o glib_hash_table

stl_unordered_map: stl_unordered_map.cc Makefile
	g++ -O2 stl_unordered_map.cc -o stl_unordered_map -std=c++0x

boost_unordered_map: boost_unordered_map.cc Makefile
	g++ -O2 boost_unordered_map.cc -o boost_unordered_map

google_sparse_hash_map: google_sparse_hash_map.cc Makefile
	g++ -O2 google_sparse_hash_map.cc -o google_sparse_hash_map

google_dense_hash_map: google_dense_hash_map.cc Makefile
	g++ -O2 google_dense_hash_map.cc -o google_dense_hash_map

qt_qhash: qt_qhash.cc Makefile
	g++ -O2 `pkg-config --cflags --libs QtCore` qt_qhash.cc -o qt_qhash

python_dict: python_dict.c Makefile
	gcc -O2 -I/usr/include/python2.6 -lpython2.6 python_dict.c -o python_dict
