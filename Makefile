FLAGS= -Werror -c

main.exe: main.o
	g++ -o main.exe main.o

main.o: main.cpp
	g++ ${FLAGS} main.cpp