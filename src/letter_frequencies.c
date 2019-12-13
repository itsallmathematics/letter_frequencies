#include "standard.h"
//#include "letter_frequencies.h"

void print_stats(size_t *frequencies);
void graph_frequencies(size_t *frequencies);
void print_tally(size_t number);

MAIN_A
{
    size_t frequencies[26] = {0};
    if(argc != 2)
    {
        printf("USAGE: %s somefile.txt\n", argv[0]);
        REF;
    }

    FILE* fp;

    fp = fopen(argv[1], "r");

    if(!fp)
    {
        fprintf(stderr, "Failed to open file %s\n", argv[1]);
        REF;
    }

    int c; //Needs to be int (not char) for EOF to work
    while((c = fgetc(fp)) != EOF)
    {
        if(c < 97) // if c is not between 'a' and 'z', is it between 'A' and 'Z'?
        {
            if(c < 65 || c > 90)
            {
                continue; // Skip it - it's not in sets A-Z or a-z
            }

            frequencies[c - 65]++;
        }
        else if(c > 122)
        {
            continue;
        }
        else
        {
            frequencies[c - 97]++;
        }

    }

    fclose(fp);

    print_stats(frequencies);
    graph_frequencies(frequencies);

    RES;
}

void print_stats(size_t *frequencies)
{
    IFN(frequencies)
    {
        ERR("print_stats: NULL input");
        return;
    }

    printf("==========FREQUENCIES==========\n"); //TODO: Create a macro for this with msg

    int i;
    for ( i = 0; i < 26; i++ )
      printf("%c: %lu\n", i+65, frequencies[i]); // Braces, i.e. {}, are actually just compound statements

    return;

}

void graph_frequencies(size_t *frequencies)
{
        IFN(frequencies)
    {
        ERR("graph_frequencies: NULL input");
        return;
    }

    printf("==========VISUAL==========\n"); //TODO: Create a macro for this with msg

    int i;
    for ( i = 0; i < 26; i++ ) {
      printf("%c: ", i+65);
      print_tally(frequencies[i]);
    }

    return;
}

void print_tally(size_t number)
{

    size_t bars = number / 5;

    while(bars > 0)
    {
        putchar('|');
        bars--;
    }
    putchar('\n');
    return;
}
