# Makefile para P2E6
# ejecutar desde la terminal escribiendo "make" 
# genera automáticamente el ejecutable del programa

FLAGS = -Wall -Wextra -Werror -std=c99

programa: main.o glist.o contacto.o sglist.o
	$(CC) -o $@ $^ $(FLAGS)

main.o: main.c glist.h contacto.h sglist.h
	$(CC) -c $< $(FLAGS)

glist.o: glist.c glist.h
	$(CC) -c $< $(FLAGS)

contacto.o: contacto.c contacto.h
	$(CC) -c $< $(FLAGS)

sglist.o: sglist.c sglist.h
	$(CC) -c $< $(FLAGS)

clean:
	rm *.o
	rm programa

.PHONY = clean