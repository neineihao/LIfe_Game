LifeGame : Life.o main.o
	g++ Life.o main.o -o LifeGame
Life.o : Life.cpp Life.h
	g++ -c Life.cpp
main.o : main.cpp
	g++ -c main.cpp
clean :
	rm *.o
