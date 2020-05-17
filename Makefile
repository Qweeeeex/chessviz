g = g++
CFLAGS = -Wall -Werror -MP -MMD -std=c++14

.PHONY: clean run all

all: ./bin/chessviz.exe

-include build/src/*.d

./bin/chessviz.exe: ./build/main.o ./build/draw.o ./build/source.o
	$(g) $(CFLAGS) -o ./bin/chessviz.exe ./build/main.o ./build/source.o ./build/draw.o -lm

./build/main.o: ./src/main.cpp ./src/header.h
	$(g) $(CFLAGS) -o build/main.o -c src/main.cpp -lm

./build/draw.o: ./src/draw.cpp ./src/header.h
	$(g) $(CFLAGS) -o ./build/draw.o -c ./src/draw.cpp -lm

./build/source.o: ./src/source.cpp ./src/header.h
	$(g) $(CFLAGS) -o ./build/source.o -c ./src/source.cpp -lm

test: bin/chessviz-test

bin/chessviz-test: build/test/main.o build/source.o
			$(g) -o bin/chessviz-test build/test/main.o build/source.o

build/test/main.o: test/main.cpp
			$(g) $(CFLAGS) -o build/test/main.o -c test/main.cpp

testRun:
			./bin/chessviz-test

clean:
	rm -rf build/*.o build/*.d build/test/*.o build/test/*.d

run:
	./bin/chessviz.exe
