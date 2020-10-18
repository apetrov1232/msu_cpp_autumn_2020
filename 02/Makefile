CC = g++

FLAGS = -std=c++17 -Wall


all: task.o
	$(CC) $(FLAGS) task.o test_2.cpp -o test.exe
task.o: task_2.cpp
	$(CC) $(FLAGS) -c task_2.cpp -o task.o
test: test_2.cpp task.o
	./test.exe
clean:
	rm test.exe
	rm task.o
	rm ans*.txt