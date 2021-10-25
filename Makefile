all: clear run
run:
	gcc -o hanoi hanoi.c
clear:
	rm -f hanoi
