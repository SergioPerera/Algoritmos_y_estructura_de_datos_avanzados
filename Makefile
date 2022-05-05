#Compilador
CC = g++
#Flags
CFLAGS = -I -Weffc++ -Wall -g


#Variables
EJECUTABLE = lifecycle

#En DEPSSRC va la dirección de los .h 
DEPSSRC = include

#En OBJSRC va la dirección de los .cc 
OBJSRC = src

#Dirección donde se ponen los .o
OBJDIR = build

#Dirección donde se ponen los ejecutables/archivos binarios
BINDIR = bin

################################################################################
##########################    NO TOCAR NADA DE ABAJO    ########################
################################################################################

############################# ARCHIVOS H #######################################
#En DEPS van los archivos .h
DEPS = $(DEPSSRC)/*.h

DEPSCPY = $(DEPS)
############################# ARCHIVOS CC ######################################
#Obtenemos los archivos .cc y le ponemos .o
AUX=$(OBJSRC)/*.cc
OBJ=$(shell echo $(AUX) | sed -r 's/.cc/.o/g' | sed -r 's/$(OBJSRC)/$(OBJDIR)/g')
############################# DIRECCIONES DE DESTINO ###########################


$(OBJDIR)/%.o: src/%.cc $(DEPS)
				$(CC) $(CFLAGS) -c -o $@ $<

$(BINDIR)/$(EJECUTABLE): $(OBJ)
				$(CC) -o $@ $^ $(CFLAGS)

	@echo ""
	@echo ARCHIVOS .o: $(OBJ)
	@echo ARCHIVOS .h: $(DEPSCPY)
	@echo ""


clean: 
				rm -rf $(OBJDIR)/*.o
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
move:
	mv *.o $(OBJDIR)/
	mv *.h $(DEPSSRC)/
	mv *.cc $(OBJSRC)/
upload:
	git add .
	git commit -m "BackUp"
	git push
pull:
	git pull