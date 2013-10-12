/* Eric Conklin
   ec181875 */

/* symbolic constants */

#define SYMBOL_MAX_LENGTH 16     /* max length of hash table symbols */
#define NUM_ARGS 3               /* correct number of command line arguments */
#define INPUT_FILE_ARGV_INDEX 1  /* index in argv of input file */
#define OUTPUT_FILE_ARGV_INDEX 2 /* index in argv of output file */

/* function prototypes */

int hash_example_one(char*, int);
int hash_example_two(char*, int);
void calc_data(char*, int**, int, FILE*);
