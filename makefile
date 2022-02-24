CC = g++
CFLAGS = -I -Weffc++ -Wall -g
#En DEPS van los archivos .h
DEPS = /include/cell.h include/grid.h include/functions.h
#En OBJ van todos los .cc pero con .o
OBJ = src/cell.o src/grid.o src/main_life_game.o src/functions.o
#Dirección donde se ponen los .o
#$(OBJDIR)/
OBJDIR = "build"

$(OBJDIR)/%.o: %.cc $(DEPS)
				$(CC) -c -o $@ $< $(CFLAGS)

lifegame: $(OBJ)
				$(CC) -o $@ $^ $(CFLAGS)

clean: 
				rm -rf src/*.o
				rm gamelife
