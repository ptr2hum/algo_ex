/* this is quick sort by jake  */
#include <stdio.h>
#include "random.h"
#include "qsort.h"

void print_array(char*, const int * ptr, int cnt);

#define NUMBER_OF_ITEM	10
int main(void){
  /* random number generated for a test of quick sort */
  int rnum_test[NUMBER_OF_ITEM];
  random_number(rnum_test,NUMBER_OF_ITEM);
  print_array("",rnum_test,NUMBER_OF_ITEM);

  qsort_(rnum_test, NUMBER_OF_ITEM);

  print_array("",rnum_test,NUMBER_OF_ITEM);
  return 0;
}

void print_array(char* fmt,const int *array, int num_array){
  for(int i=0; i< num_array; i++){
    printf("%d ",array[i]);
  }
  printf("\n");
}

  
