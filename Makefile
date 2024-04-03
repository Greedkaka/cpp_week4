FLAGS= -Werror -c

main.exe: main.o database.o
	g++ -o main.exe *.o

main.o: main.cpp
	g++ ${FLAGS} main.cpp

database.o: database.cpp
	g++ ${FLAGS} database.cpp