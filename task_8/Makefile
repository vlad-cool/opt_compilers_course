.PHONY: all run

all: naive transpose a.txt b.txt

naive: naive.c
	/home/vlad/Programs/chibicc/chibicc naive.c -lm -o naive

transpose: transpose.c
	/home/vlad/Programs/chibicc/chibicc transpose.c -lm -o transpose

a.txt: gen.py
	./gen.py 256 > a.txt

b.txt: gen.py
	./gen.py 256 > b.txt

run: all
	time ./naive 256 128 > 1
	time ./transpose 256 128 > 2
