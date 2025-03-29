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

void print_csv(struct Struktura str, FILE *out){
    fprintf(out, "%u, \"%.*s\", %d, %.6f\n", str.index, 3, str.code, str.units, str.length);
}

void print_table(struct Struktura str, FILE *out){
    fprintf(out, "%-5u | %-3.3s | %10d | %8.4f\n", str.index, str.code, str.units,str.length);
}

main(int argc, char *argv[])
{
    printf("Hello world!\n");
    return EXIT_SUCCESS;
}
