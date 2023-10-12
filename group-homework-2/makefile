CC = g++
CFLAGS = -g -Wall -Wextra


default: library


library:library.o main.o
	$(CC) $(CFlags) -o library library.o main.o


library.o:	library.cpp library.h
	$(CC) $(CFLAGS) -c library.cpp


main.o:	main.cpp library.h
	$(CC) $(CFLAGS) -c main.cpp


clean:
	$(RM) library *.o *~
