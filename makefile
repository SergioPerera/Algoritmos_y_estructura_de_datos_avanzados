CC = g++
CFLAGS = -I -Weffc++ -Wall -g


############################# ARCHIVOS H ###################################
#En DEPSSRC va la dirección de los .h 
DEPSSRC = include
#En DEPS van los archivos .h
DEPS = $(addprefix $(DEPSSRC)/, cell.h grid.h functions.h)

############################# ARCHIVOS CC ###################################
#En OBJSRC va la dirección de los .cc 
OBJSRC = src
#En OBJ van todos los .cc pero con .o
# OBJ = $(OBJSRC)/cell.o $(OBJSRC)/grid.o $(OBJSRC)/main_life_game.o $(OBJSRC)/functions.o
OBJ = $(addprefix $(OBJSRC)/, cell.o grid.o functions.o functions.o main_life_game.o)

############################# DIRECCIONES DE DESTINO ###################################
#Dirección donde se ponen los .o
OBJDIR = build
#Dirección donde se ponen los ejecutables/archivos binarios
BINDIR = bin

%.o: %.cc $(DEPS)
				$(CC) $(CFLAGS) -c -o $@ $<

$(BINDIR)/lifegame: $(OBJ)
				$(CC) -o $@ $^ $(CFLAGS)

clean: 
				rm -rf src/*.o
cleaner:
				rm -rf bin/lifegame
