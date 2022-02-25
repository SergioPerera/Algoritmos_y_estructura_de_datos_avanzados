#Compilador
CC = g++
#Flags
CFLAGS = -I -Weffc++ -Wall -g


#Variables
EJECUTABLE = lifegame

################################################################################
##########################    NO TOCAR NADA DE ABAJO    ########################
################################################################################

#En DEPSSRC va la dirección de los .h 
DEPSSRC = include

#En OBJSRC va la dirección de los .cc 
OBJSRC = src

############################# ARCHIVOS H #######################################
#En DEPS van los archivos .h
DEPS = $(DEPSSRC)/*.h

DEPSCPY = $(DEPS)
############################# ARCHIVOS CC ######################################
#Obtenemos los archivos .cc y le ponemos .o
AUX=$(OBJSRC)/*.cc
OBJ=$(shell echo $(AUX) | sed -r 's/.cc/.o/g')

############################# DIRECCIONES DE DESTINO ###########################
#Dirección donde se ponen los .o
OBJDIR = build

#Dirección donde se ponen los ejecutables/archivos binarios
BINDIR = bin


%.o: %.cc $(DEPS)
				$(CC) $(CFLAGS) -c -o $@ $<


$(BINDIR)/$(EJECUTABLE): $(OBJ)
				$(CC) -o $@ $^ $(CFLAGS)

	@echo ""
	@echo ARCHIVOS .o: $(OBJ)
	@echo ARCHIVOS .h: $(DEPSCPY)
	@echo ""


clean: 
				rm -rf src/*.o
cleaner:
				rm -rf bin/*
template:
				mkdir bin
				mkdir build
				mkdir include
				mkdir src
	@echo "Plantilla creada correctamente"
show:
	@echo $(AUX)
	@echo $(OBJ)
	@echo $(DEPSCPY)



