CC = g++

FLAGS = -std=c++17 -Wall


all: BigInt_class.cpp
	$(CC) $(FLAGS) -c BigInt_class.cpp -o task.o
	$(CC) $(FLAGS) task.o test_for_BigInt.cpp -o test.exe
test: test.exe
	./test.exe
clean:
	rm test.exe
	rm task.o