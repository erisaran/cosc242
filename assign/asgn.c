/**
   242 assignment application file.
   Entry point for the program. Creates a hash table and fills it with words
   from a input file.
   Without arguments it will read from stdin and print out words that are not
   found in the file.
   Allows the user to choose robust containers, to specify the hash table size,
   to print out the contents of the hash table and to output timing information
   and number of words not found in the table.
   @author Ben Dutton,  Alexander Dooley,  Murdoch Braid.
*/

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>
#include "mylib.h"
#include "htable.h"
#include <time.h>

#define BUFF_SIZE 256
#define DEFAULT_HASH_SIZE 3877

/**
   Method to print out user instructions.
*/
void print_help(){
    printf("Optional arguments are : \n\
-r Uses a robust chaining method which is a red-black tree container type. \n\
-s <table-size> Sets size of the Hash Table. Default size is 3877.\n\
-p Prints the Hash Table to stdout with each non-empty container on a line.\n\
   The program wont read anything from stdin when this is used.\n");
    printf("-i Prints info to stderr about time taken to fill the table\
and search it\n\
   and also shows how many words were typed in that were not in the table.\n\
-h Prints out this help message. \n");
}
    
/**
   Main method for the program. Creates a hash table, reads a file, takes a
   series of arguments from the user.
   @param argc number of arguments.
   @param argv array of arguments given by the user on the command line.
   @return Run success.
*/
int main(int argc, char **argv) {
    htable h; /* creates a variable to hold a hash table. */
    FILE *f; /* creates a variable to hold a file. */
    char word[BUFF_SIZE]; /* creates a string to hold input words. */
    int size; /* variable to hold user specified size. */
    int r = 0, s = 0, p =0, i = 0; /* initialises variable to track arg use. */
    const char *opstring = "rs:pih"; /* defines which arguments are used. */
    char option; 
    clock_t start = clock(), end = clock(); /*initialises a clock object. */
    double fill = 0, search = 0; /* records time taken */
    int unknown = 0; /* counts unknown words. */

   
    
    /** This while loop manages the user arguments.
        -r enables robust containers using a rbt.
        -s allows the user to specify a hash table size.
        -p prints out the non-null containers.
        -i prints out timing info, and unknown word count.
        -h or undefined argument causes a help message to be output.
    */
    while ((option = getopt(argc, argv, opstring)) != EOF) {
        
        switch (option) {
            case 'r':
                r = 1;
                break;
            case 's':
                s = 1;
                size = atoi(optarg);
                break;
            case 'p':
                p = 1;
                break;
            case 'i':
                i = 1;
                break;
            case 'h':
                print_help();
                return EXIT_SUCCESS;
                break;
            default:
                print_help();
                return EXIT_SUCCESS;
                break;
        }
    }

    /* This if block check to see if the file is present. */
    if ((f = fopen(argv[optind], "r")) == NULL) {
        fprintf(stderr, "%s can't find file %s\n", argv[0], argv[optind]);
        return EXIT_FAILURE;
    }
    
    /* This if checks to see if there is a user specified table size else it
       uses the default size */
    if (s == 1) {
        h = htable_new(size, r);
    } else {
        h = htable_new(DEFAULT_HASH_SIZE, r);
    }

    /* This if checks to see if the user has requested timing and unknown info.
     */
    if (i == 1) {
        start = clock();
    }
    /* This while loop will insert each word from the input file into the
       hash table */
    while (getword(word, sizeof word, f) != EOF) {
        htable_insert(h, word);
        
    }
    /* If timing info was specified the clock will now end. */
    if (i == 1) {
        end = clock();
        fill = (end - start) / (double)CLOCKS_PER_SEC;
    }
    
    fclose(f); /* closes the input file */

    /* If the print argument is used the hash tables contents will be printed
       and the program will not ask for user input. If no print argument is
       used then it will ask the user to type in text and output words that
       are not in the hash table.*/
    if (p == 1) {
        htable_print(h, stdout);
    } else {
        if (i == 1) {
            start = clock();
        }
        while (getword(word, sizeof word, stdin) != EOF) {
            if (htable_present(h, word) == 0) {
                printf("%s\n", word);
                unknown++;
            }
        }
        if (i == 1) {
            end = clock();
            search = (end - start) / (double) CLOCKS_PER_SEC;
        }
    }

    /* If timing and unknown words info was specified by the user this info
       will be output to stderr. */
    if (i == 1) {
        fprintf(stderr,
                "Fill time : %f \nSearch time : %f \nUnknown words : %d \n",
                fill, search, unknown);
    }
    
    htable_free(h); /* frees all the memory used by the hash table */
    
    return EXIT_SUCCESS;
}
