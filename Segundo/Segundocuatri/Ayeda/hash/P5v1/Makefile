CC = g++
CFLAGS = -std=c++14 -g -Wall
DEPS = Dispfuc.hpp Hasht.hpp List.hpp
OBJ = Hasht.o main_hasht.o

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
main_hasht: $(OBJ) main_hasht.cpp
	$(CC) -o $@ $^ $(CFLAGS)
clean:
	rm Hasht *.o
