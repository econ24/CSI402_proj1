/* Eric Conklin
   ec181875
   econklin@albany.edu

   The purpose of this program is to evaluate the performance of two
   hash functions. The following information is calculated for each
   hash function:
   --size of hash table
   --number of non-empty lists
   --maximum number of nodes in lists
   --minimum number of nodes in non-empty lists
   --average number of nodes per non-empty lists

   This program opens an input text file whose first
   line is an integer representing the size of the hash table to be
   created. Subsequent lines consist of sysmbols to be inserted into
   the hash table. All calculated data is written as text to an output
   file.

   The following assumptions are made:
   --size of hash table is between 1 and 10,000 inclusive
   --there are no blank lines in input file
   --Each symbol has at least one character and at most 15 characters
   --Each character of a symbol is an upper or lower case letter, a
     digit or underscore
   --The symbols in the input file are distinct

   Two int arrays are generated, equal in size, to the required size of the
   hash tables, one for each hash function. Each integer value in the array
   is initialized to zero. As an index is generated by a hash function, the
   integer value in the corresponding int array is incremented by one. Each
   int array is then evaluated to calculate the required data. */

#include <stdio.h>
#include <stdlib.h>

/* include header file */
#include "p1_header.h"

/* main receives the following command line arguments:
   p1 -- name of executalbe file
   input_file -- an existing file that data is read from
   output_file -- creates this file for outputing data */

int main(int argc, char *args[]){
  FILE *inptr; /* input file pointer */
  FILE *outptr; /* output file pointer */

  int size; /* variable for size of hash tables */
  int i; /* loop counter */

  int *result1, *result2; /* int arrays analyzed to produce data */

  char line[SYMBOL_MAX_LENGTH]; /* string to hold strings read from
                                   input file */

  /* usage error check */
  if(argc != NUM_ARGS){
    puts("Usage: p1 input_file output_file");
    exit(1);
  }

  /* attempt to open files */
  if((inptr = fopen(args[INPUT_FILE_ARGV_INDEX], "r")) == NULL){
    printf("%s%s\n", "Unable to open input file = ", args[1]);
    exit(1);
  }

  if((outptr = fopen(args[OUTPUT_FILE_ARGV_INDEX], "w")) == NULL){
    printf("%s%s\n", "Unable to open output file = ", args[2]);
    exit(1);
  }

  /* read first line of input file for size of hash tables */
  fscanf(inptr, "%d", &size);

  /* allocate space for int arrays */
  if((result1 = (int*)calloc(size, sizeof(int))) == NULL){
    puts("ERROR!!! Your PC is OOM!!!");
    exit(1);
  }

  if((result2 = (int*)calloc(size, sizeof(int))) == NULL){
    puts("ERROR!!! Your PC is OOM!!!");
    exit(1);
  }

  /* main while loop. reads each line of input file until EOF reached */
  while(fscanf(inptr, "%s", line) != EOF){

    /* hash table 1 */
    /* call hash function to calculate hash table index */
    i = hash_example_one(line, size);

    /* increment int in array result1[i] by one */
    (*(result1 + i))++;

    /* repeat process for hash table 2 */
    i = hash_example_two(line, size);
    (*(result2 + i))++;
  }

  /* calculate results for function 1 */
  strcpy(line, "Function I");
  calc_data(line, &result1, size, outptr);

  /* calc results for function II */
  strcpy(line, "Function II");
  calc_data(line, &result2, size, outptr);

  /*free int arrays */
  free(result1);
  free(result2);

  /* close opened files */
  fclose(inptr);
  fclose(outptr);

  return(0);
}
