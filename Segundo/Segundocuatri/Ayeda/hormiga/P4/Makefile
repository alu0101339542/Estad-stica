CC = g++
CFLAGS = -std=c++14 -g -Wall
DEPS = hormiga.hpp mundo.hpp mundofinito.hpp mundoinfinito.hpp celda.hpp universo.hpp
OBJ = hormiga.o main_hormiga.o movimiento.o movimientoinversa.o movimientolangton.o mundofinito.o mundoinfinito.o mundo.o

%.o: %.cc $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
main_hormiga: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
clean:
	rm hormiga *.o
