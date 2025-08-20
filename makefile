CC      = g++
FLAGS   = -std=c++11 -Wall -Wextra -pedantic -O2
SOURCES = main.cpp monster.cpp battleEngine.cpp rng.cpp types.cpp
OVERWORLD_SRC = overWorld/overWorld.cpp

all: pokemon overworld

pokemon: $(SOURCES)
	$(CC) $(SOURCES) $(FLAGS) -o pokemon.exe

overworld: $(OVERWORLD_SRC)
	$(CC) $(OVERWORLD_SRC) $(FLAGS) -o overworld.exe

clean:
	rm -f pokemon.exe overworld.exe *.o
