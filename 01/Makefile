CC = g++

FLAGS = -std=c++17 -Wall


all: task.o
task.o: task_1.cpp
	$(CC) $(FLAGS) -c task_1.cpp -o task.o
test: test_1.cpp task.o
	$(CC) $(FLAGS) task.o test_1.cpp -o test.exe
	./test.exe
clean:
	rm test.exe
	rm task.o