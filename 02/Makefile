CC = g++

FLAGS = -std=c++17 -Wall


all: task.o
	$(CC) $(FLAGS) task.o test_for_parser.cpp -o test.exe
task.o: parser.cpp
	$(CC) $(FLAGS) -c parser.cpp -o task.o
test: test.exe
	./test.exe
clean:
	rm test.exe
	rm task.o
	rm ans*.txt