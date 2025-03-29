.PHONY: all clean

all: tableprint

tableprint: obj/main.o
	gcc -o tableprint obj/main.o
	
obj/main.o: src/main.c
	mkdir -p obj
	gcc -c -o obj/main.o src/main.c
	
clean:
	rm -fr obj/
	rm -f tableprint