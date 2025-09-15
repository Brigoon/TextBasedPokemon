CC      = g++
FLAGS   = -std=c++11 -Ilib -o main
SOURCES = $(wildcard src/*.cpp)

make: $(SOURCES)
	$(CC) $(SOURCES) $(FLAGS)

clean:
	rm main
