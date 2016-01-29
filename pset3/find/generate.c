/**
 * generate.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Generates pseudorandom numbers in [0,LIMIT), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 */
 
#define _XOPEN_SOURCE

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// constant
// limit is the size of an integer to 2 bytes so it works for all systems - 16-bit system
// The value of an integer however is 4 bytes for this computer - 32 bit system
#define LIMIT 65536
// #define LIMIT 4294967296

int main(int argc, string argv[])
{
    // TODO: comment me
    // Prompt the user to include at least one integer argument
    if (argc != 2 && argc != 3)
    {
        printf("Usage: generate n [s]\n");
        return 1;
    }

    // TODO: comment me
    // This first argument is the quanity of numbers the user wants
    // It is a char that is converted in to integer using ASCII conversions
    int n = atoi(argv[1]);

    // TODO: comment me
    // Determine seed value.
    // If seed value, then convert it integer using ASCII.
    // If no seed value, use time to create the integer
    // srand48 accepts a seed option and sets `drand48()`
    // without this, drand48() would always return the
    // same sequence of #s: 0.000000, 0.000985, ...
    if (argc == 3)
    {
        srand48((long int) atoi(argv[2]));
    }
    else
    {
        srand48((long int) time(NULL));
    }

    // TODO: comment me
    // multiple by the limit in order to get a number between 0 and limit
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", (int) (drand48() * LIMIT));
    }

    // success
    return 0;
}