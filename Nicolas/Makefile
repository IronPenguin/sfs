CC = clang
CFLAGS = -Wall -Wextra -std=c99 -O2
DEP = main.c
OGLSDL = -lSDL -lSDL_ttf -lGL -lGLU
CIBLE = kobayashi

all:
	$(CC) $(DEP) -o $(CIBLE) $(CFLAGS) $(OGLSDL)

clean::
	rm -f kobayashi
