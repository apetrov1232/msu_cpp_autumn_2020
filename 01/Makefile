CC = g++

FLAGS = -std=c++17 -Wall

EXEC = test.exe
test: test.e
	./test.exe
test.e: task_1.cpp test_1.cpp	
	$(CC) $(FLAGS) test_1.cpp -o $(EXEC)
clean:
	rm test.exe
