CC = g++

FLAGS = -std=c++17 -Wall


all: Serializer.tpp
	$(CC) $(FLAGS) test_for_Serializer.cpp -o test.exe
test: test.exe
	./test.exe
clean:
	rm test.exe
	rm task.o