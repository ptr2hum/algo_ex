/* my answer on the problem 'Key to Knowledge' from https:// www.somiopo.net/problem/1032g
 */

#include <stdio.h>
#include <stdlib.h>

void print_bit(int a);

typedef struct {
  int a;
  int score;
}answer;

#define n 3 //number of students
#define m 5 // number of answers : it's not used...

int main(void){
  answer answers[n] = {{0b01101,4},{0b10100,3},{0b00011,3}};

  size_t s_answers = n;

  int solutions[10];
  int count =0;

  int solution_MAX = 0b100000;

  for(int solution =0; solution < solution_MAX; solution++){
    int score = 0;

    for(int i = 0; i < s_answers ; i++){
      score = 0;
       int scored = (~(solution ^ answers[i].a)) & 0b11111;
      for( int c =1 ; c < solution_MAX ; c <<= 1){
	score += c& scored ? 1 : 0;
      }
      if (score != answers[i].score){
	score = 0;
	break;
      }
    }
    if (score != 0)solutions[count++] = solution;
  }
  printf("%d\n",count);
  if(count == 0) printf("no solution\n");
  else{
    for(int i = 0 ; i < count ; i++){
      print_bit(solutions[i]);
      printf("\n");
    }
  }
  return 0;
}

void print_bit(int integer){
  int mask = 0b10000;
  do{
    printf("%d", integer & mask ? 1 :0);
    mask >>=1;
  }while(mask);
  
}
