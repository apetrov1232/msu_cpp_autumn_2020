CC = g++

FLAGS = -std=c++17 -Wall


all: task.o
	$(CC) $(FLAGS) task.o test_for_BigInt.cpp -o test.exe
task.o: BigInt_class.cpp
	$(CC) $(FLAGS) -c BigInt_class.cpp -o task.o
test: test.exe
	./test.exe
clean:
	rm test.exe
	rm task.o