CC = g++
CFLAGS = -I -Weffc++ -Wall -g
#En DEPS van los archivos .h
DEPS = /include/cell.h include/grid.h include/cell.h
#En OBJ van todos los .cc pero con .o
OBJ = src/cell.cc src/grid.cc src/main_life_game.cc

%.o: %.cc $(DEPS)
				$(CC) -c -o $@ $< $(CFLAGS)

lifegame: $(OBJ)
				$(CC) -o $@ $^ $(CFLAGS)

clean: 
				rm -rf *.o
				rm gamelife
