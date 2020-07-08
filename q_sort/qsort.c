#include <stdio.h>
#include <stdlib.h>
#include "qsort.h"

/* swap : argument should be address */
#define swap(a,b) do{\
  int* _a =(a),*_b=(b);\
  int tmp =* _a;\
  *_a =* _b;\
  *_b = tmp;\
  }while(0);

void qsort_( const int * src, int num_src){
  /* if don't want to modify value of array, set qualifier const */
  /* set pivot */
  //  const size_t size = sizeof (int);
  /* pivot is right most element of src */
  int *pivot =(int*)&src[num_src-1]; /* ptr to array member */
  /* src is const. so should be cast */
  int * l_elem = (int*)src;
  int * r_elem = pivot-1;
  //  int* r_elem =pivot-1;// r_elem--;

  /* partition */
  while(l_elem<pivot){

    while((*l_elem <= *pivot)&&(l_elem<pivot)) l_elem++;
      
    if (*l_elem > *pivot) {
      swap(l_elem, r_elem);
      /* swap pivot with pivot-1 element when <, otherwise break partition */
      swap(r_elem, pivot);
      /* for(int i=0 ; i < num_src; i++) printf("%d ",src[i]);  */
      /* printf("\n"); */ 
      /* modify pivot */
      r_elem = --pivot-1;
      //  l_elem =(int*) src;

    }
  }
  /* end partition */

  int left_num = (pivot - src) ; /* current location of pivot */
  int right_num = num_src - left_num-1;
  /* left recursion */
  if(left_num >=2)   qsort_(src, left_num);
  /* Right recursion */
  if(left_num < num_src -2) qsort_(pivot+1, right_num); 
}


