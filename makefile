STR: main.o
	g++ main.cpp -o STR

main.o: main.cpp
	g++ -c main.cpp

clean:
	delete main.o	
