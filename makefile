CC      = g++
FLAGS   = -std=c++11 -o main
SOURCES = main.cpp monster.cpp battleEngine.cpp

make: $(SOURCES)
	$(CC) $(SOURCES) $(FLAGS)

clean:
	rm main