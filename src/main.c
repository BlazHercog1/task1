#include <stdlib.h>
#include <stdio.h>

struct Struktura {
    unsigned short index;
    char code[3];
    int units;
    double length;
};

void print_help(){
    printf("tableprint\n\n");
    printf("-h\n Izpis pomoci z zastavicami in njihovimi opisi\n");
    printf("-i <pot>\n Kot vhod program odpre in uporabi zbirko/napravo s podano potjo\n");
    printf("-o <pot>\n Kot izhod program odpre in uporabi zbirko/napravo s podano potjo\n");
}
main(int argc, char *argv[])
{
    printf("Hello world!\n");
    return EXIT_SUCCESS;
}
