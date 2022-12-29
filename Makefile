OBJS	= run_pokemon.o pokemon.o
SOURCE	= run_pokemon.cpp pokemon.cpp
HEADER	= pokemon.h
OUT	= ./a.out
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

run_pokemon.o: run_pokemon.cpp
	$(CC) $(FLAGS) run_pokemon.cpp 

pokemon.o: pokemon.cpp
	$(CC) $(FLAGS) pokemon.cpp 


clean:
	rm -f $(OBJS) $(OUT)