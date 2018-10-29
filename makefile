all: random.c
	gcc random.c

run: a.out
	./a.out

clear: a.out
	rm a.out
	rm txt.txt
	clear
