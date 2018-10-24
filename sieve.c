#include "sieve.h"

int sieve(int targetPrime){
  if(targetPrime == 1)return 2;
  int size;
  double targetlog = log(targetPrime);
  if (targetPrime > 5000) size = (int)(0.575 * targetPrime * targetlog);
  else size = (int)(.65 * targetPrime * targetlog) + 10 ;
  char * arr =  calloc(size/8, sizeof(char)) ;
  int index = 0;
  int num = 3;
  int counter = 0;
  int stop = (int)(sqrt(2 * size));
  while(num <= stop){
    if(!(arr[index/8]&1 << index%8)){
        counter++;
        int innerind;
        for(innerind = index + counter * num; innerind < size; innerind += num){
          arr[innerind/8] |= 1 << innerind%8;
        }
    }
        index++;
        num+=2;
  }
  counter =1;
  num = 3;
  for(index = 0; index < size; index++){
    if(!(arr[index/8]&1 << index%8))counter++;
    if(counter == targetPrime){
      return num;
    }
    num+=2;
  }
}
