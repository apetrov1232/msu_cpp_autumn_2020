CC = g++

FLAGS = -std=c++17 -Wall


all: task.o
	$(CC) $(FLAGS) task.o test_for_matrix.cpp -o test.exe
task.o: matrix_class.cpp
	$(CC) $(FLAGS) -c matrix_class.cpp -o task.o
test: test.exe
	./test.exe
clean:
	rm test.exe
	rm task.o