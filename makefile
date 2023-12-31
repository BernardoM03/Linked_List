CC=g++
EXE=asn5

$(EXE)main: linked_list.o linked_list.h test_linked_list.o node.h
	$(CC) linked_list.o test_linked_list.o -o $(EXE)

linked_list.o: linked_list.cpp
	$(CC) -c linked_list.cpp

test_linked_list.o: test_linked_list.cpp
	$(CC) -c test_linked_list.cpp
