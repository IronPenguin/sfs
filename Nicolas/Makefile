CC = clang
CFLAGS = -Wall -Wextra -std=c99 -O2
DEP =
OGL = -lX11 -lGL -lGLU

all:
	$(CC) $(CFLAGS) $(OGL) $(DEP) main.c -o kobayashi 

clean::
	rm -f kobayashi
