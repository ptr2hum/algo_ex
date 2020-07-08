#include <stdlib.h>
#include <time.h>

void random_number(int * array, int num_array){
  srand(time(NULL));//seed
  for(int i = 0; i<num_array; i++){
    int x=100;
    while(x>99) x=1+rand()/((RAND_MAX + 1u)/99);
    array[i]=x;

  }

}
