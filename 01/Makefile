CC = g++

FLAGS = -std=c++17 -Wall

all: task_1.cpp
	$(CC) $(FLAGS) -c task_1.cpp -o task
test: test.exe
	./test.exe
test.exe: test_1.cpp
	$(CC) $(FLAGS) test_1.cpp -o test.exe
clean:
	rm test.exe
	rm task.o
