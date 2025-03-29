#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>

typedef struct {
    unsigned short index;
    char code[3];
    int units;
    double length;
}__attribute__ ((packed)) Struktura;

void print_help(){
    printf("tableprint\n\n");
    printf("-h\n Izpis pomoci z zastavicami in njihovimi opisi\n");
    printf("-i <pot>\n Kot vhod program odpre in uporabi zbirko/napravo s podano potjo\n");
    printf("-o <pot>\n Kot izhod program odpre in uporabi zbirko/napravo s podano potjo\n");
}

void print_csv(Struktura str, FILE *out){
    fprintf(out, "%u, \"%.*s\", %d, %.6f\n", str.index, 3, str.code, str.units, str.length);
}

void print_table(Struktura str, FILE *out){
     fprintf(out, "%-5u | %-3.3s | %10d | %8.4f\n", str.index, str.code, str.units, str.length);
}

int main(int argc, char *argv[])
{
    char *input_path = NULL; 
    char *output_path = NULL;
    FILE *input = stdin;
    FILE *output = stdout;

    //obdelujemo argumente
    for(int i = 1; i < argc; i++){
        if (strcmp(argv[i], "-h") == 0)
        {
            print_help();
            return 0;
        } else if (strcmp(argv[i], "-i") == 0 && i + 1 < argc){
            input_path = argv[++i];
        } else if (strcmp(argv[i], "-o") == 0 && i + 1 < argc)
        {
            output_path = argv[++i];
        }  
    }
    if (input_path)
    {
        input = fopen(input_path, "rb");
        if (!input)
        {
            fprintf(stderr, "Napaka pri pisanju v datoteko\n");
            return 1;
        }
    }

    if (output_path)
    {
        struct stat buffer;
        if(stat(output_path, &buffer) == 0){
            fprintf(stderr, "Napaka pri pisanju v datoteko\n");
            return 1;
        }
        output = fopen(output_path, "w");
        if (!output)
        {
            fprintf(stderr, "Napaka pri pisanju v datoteko\n");
            return 1;
        }
    }

    int terminal_output = isatty(fileno(output));

    Struktura str;
    while (fread(&str, sizeof(Struktura), 1, input) == 1)
    {
        if (terminal_output){
            print_table(str, output);
        }
        else{
            print_csv(str, output);
        }
    }
    
    if (input != stdin)
    {
        fclose(input);
    }
    
    if (output != stdout)
    {
        fclose(output);
    }
    return 0;
}
