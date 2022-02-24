#Compilador
CC = g++
#Flags
CFLAGS = -I -Weffc++ -Wall -g

AUX=$(ls -1 src | sed -e 's/\..*$//')
#Variables
EJECUTABLE = lifegame

#En DEPSSRC va la dirección de los .h 
DEPSSRC = include

#En OBJSRC va la dirección de los .cc 
OBJSRC = src

############################# ARCHIVOS H ###################################
#En DEPS van los archivos .h
DEPS = $(DEPSSRC)/*.h

############################# ARCHIVOS CC ###################################

#En OBJ van todos los .cc pero con .o
OBJ = $(addprefix $(OBJSRC)/, cell.o grid.o functions.o functions.o main_life_game.o)

############################# DIRECCIONES DE DESTINO ###################################
#Dirección donde se ponen los .o
OBJDIR = build
# $(OBJDIR)
#Dirección donde se ponen los ejecutables/archivos binarios
BINDIR = bin

%.o: %.cc $(DEPS)
				$(CC) $(CFLAGS) -c -o $@ $<

$(BINDIR)/$(EJECUTABLE): $(OBJ)
				$(CC) -o $@ $^ $(CFLAGS)


clean: 
				rm -rf src/*.o
cleaner:
				rm -rf bin/*
template:
				mkdir bin
				mkdir build
				mkdir include
				mkdir src
aux:
	@echo "--------------------"
	@echo $(AUX)
	@echo "--------------------"

