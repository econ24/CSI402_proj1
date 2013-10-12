/* Eric Conklin
   ec181875

   This function accepts an int array generated to represent
   a hash table and then evaluates the hash function that
   were used to create the arrays. All calculated data is
   written as text to an output file. */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void calc_data(char *name, int **ary, int size, FILE *ptr){
  int total;
  int non_empty;
  int max;
  int min;
  float ave;
  int i;


  /* find first non-zero position in ary to set as minimum
     and maximum length of non-empty linked list */

  for(i = 0; i < size; i++)
    if(*((*ary) + i) > 0){
      max = min = *((*ary) + i);
      break;
    }

  total = non_empty = 0;

  /* check ary and calculate data */

  for(i = 0; i < size; i++){
    if(*((*ary) + i) > 0){
      non_empty++;

      if(*((*ary) + i) < min)
        min = *((*ary) + i);

      if(*((*ary) + i) > max)
        max = *((*ary) + i);

      total += *((*ary) + i);
    }
  }

  /* calcualte average nodes per linked list */

  ave = (float)total / (float)non_empty;

  /* print results for hash function into output file */

  fprintf(ptr, "%s\n", name);
  fprintf(ptr, "%s%d\n", "Table size = ", size);
  fprintf(ptr, "%s%d\n", "Number of non-empty lists = ", non_empty);
  fprintf(ptr, "%s%d\n", "Maximum length of non-empty lists = ", max);
  fprintf(ptr, "%s%d\n", "Minimum length of non-empty lists = ", min);
  fprintf(ptr, "%s%.2f\n", "Average number of nodes per lists = ", ave);
}
