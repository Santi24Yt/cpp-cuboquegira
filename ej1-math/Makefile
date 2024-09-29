CC = g++
LIBS =
INCLUDES =
# -Wall -Werror
DFLAGS = -Wall
CFLAGS = -xc++ -std=c++11
SOURCES = *.cpp
OUT = math

all: lspflags compile

compile:
	$(CC) $(SOURCES) $(INCLUDES) $(LIBS) $(DFLAGS) $(CFLAGS) -o $(OUT)

lspflags:
	echo $(INCLUDES) $(LIBS) $(DFLAGS) $(CFLAGS) | sed "s/ /\n/g" > compile_flags.txt

check: runpipe compare

checkog: runpipe compareog

runpipe:
	./$(OUT) > Obtenido.txt

compare:
	git --no-pager diff --no-index ResultadosMod.txt Obtenido.txt > diferencia.diff

compareog:
	git --no-pager diff --no-index Resultados.txt Obtenido.txt > diferencia.diff
