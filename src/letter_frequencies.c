#include "standard.h"
#include "letter_frequencies.h"

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
    printf("A: %lu\n", frequencies[0]);
    printf("B: %lu\n", frequencies[1]);
    printf("C: %lu\n", frequencies[2]);
    printf("D: %lu\n", frequencies[3]);
    printf("E: %lu\n", frequencies[4]);
    printf("F: %lu\n", frequencies[5]);
    printf("G: %lu\n", frequencies[6]);
    printf("H: %lu\n", frequencies[7]);
    printf("I: %lu\n", frequencies[8]);
    printf("J: %lu\n", frequencies[9]);
    printf("K: %lu\n", frequencies[10]);
    printf("L: %lu\n", frequencies[11]);
    printf("M: %lu\n", frequencies[12]);
    printf("N: %lu\n", frequencies[13]);
    printf("O: %lu\n", frequencies[14]);
    printf("P: %lu\n", frequencies[15]);
    printf("Q: %lu\n", frequencies[16]);
    printf("R: %lu\n", frequencies[17]);
    printf("S: %lu\n", frequencies[18]);
    printf("T: %lu\n", frequencies[19]);
    printf("U: %lu\n", frequencies[20]);
    printf("V: %lu\n", frequencies[21]);
    printf("W: %lu\n", frequencies[22]);
    printf("X: %lu\n", frequencies[23]);
    printf("Y: %lu\n", frequencies[24]);
    printf("Z: %lu\n", frequencies[25]);
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
    printf("A: "); print_tally(frequencies[0]);
    printf("B: "); print_tally(frequencies[1]);
    printf("C: "); print_tally(frequencies[2]);
    printf("D: "); print_tally(frequencies[3]);
    printf("E: "); print_tally(frequencies[4]);
    printf("F: "); print_tally(frequencies[5]);
    printf("G: "); print_tally(frequencies[6]);
    printf("H: "); print_tally(frequencies[7]);
    printf("I: "); print_tally(frequencies[8]);
    printf("J: "); print_tally(frequencies[9]);
    printf("K: "); print_tally(frequencies[10]);
    printf("L: "); print_tally(frequencies[11]);
    printf("M: "); print_tally(frequencies[12]);
    printf("N: "); print_tally(frequencies[13]);
    printf("O: "); print_tally(frequencies[14]);
    printf("P: "); print_tally(frequencies[15]);
    printf("Q: "); print_tally(frequencies[16]);
    printf("R: "); print_tally(frequencies[17]);
    printf("S: "); print_tally(frequencies[18]);
    printf("T: "); print_tally(frequencies[19]);
    printf("U: "); print_tally(frequencies[20]);
    printf("V: "); print_tally(frequencies[21]);
    printf("W: "); print_tally(frequencies[22]);
    printf("X: "); print_tally(frequencies[23]);
    printf("Y: "); print_tally(frequencies[24]);
    printf("Z: "); print_tally(frequencies[25]);
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