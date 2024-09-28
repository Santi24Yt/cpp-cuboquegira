CC = g++
LIBS = -lsfml-system -lsfml-window -lsfml-graphics
INCLUDES = -I./include/
DFLAGS = -Wall -Werror
CFLAGS = -xc++ -std=c++11
SOURCES = ./src/*.cpp
OUT = cubo

all: lspflags compile

compile:
	$(CC) $(SOURCES) $(INCLUDES) $(LIBS) $(DFLAGS) $(CFLAGS) -o $(OUT)

lspflags:
	echo $(INCLUDES) $(LIBS) $(DFLAGS) $(CFLAGS) | sed "s/ /\n/g" > compile_flags.txt

