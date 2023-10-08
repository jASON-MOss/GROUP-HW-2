CC = g++
CFLAGS = -g -Wall -Wextra


default: phonebook


phonebook:phonebook.o main.o
	$(CC) $(CFlags) -o phonebook phonebook.o main.o


phonebook.o:	phonebook.cpp phonebook.h
	$(CC) $(CFLAGS) -c phonebook.cpp


main.o:	main.cpp phonebook.h
	$(CC) $(CFLAGS) -c main.cpp


clean:
	$(RM) phonebook *.o *~
