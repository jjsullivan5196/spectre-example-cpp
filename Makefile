spec: spec.cc
	clear
	clang++ -std=c++14 spec.cc -o spec
	./spec
	
orig: spectre.c
	clear
	clang spectre.c -o orig
	./orig
	
spec_c: spec_c.cc
	clear
	clang++ -std=c++14 spec_c.cc -o spec_c
	./spec_c

test_seq: array_seq.h test_array_seq.cc
	clear
	clang++ -std=c++14 test_array_seq.cc -o test_seq
	./test_seq
