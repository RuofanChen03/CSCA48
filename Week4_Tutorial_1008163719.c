#include <stdio.h>

/*
  1. What is an array?
  A: Fixed size of consecutive memory boxes containing values of the the same data type

  2. What is a string?
  A: A null terminated character array; null terminator: '\0'

*/


// Write a function called StringBeans!
// StringBeans swaps letters in given strings based on entries of replArray
void StringBeans(char one[100], char two[100], int repl[10]){
  for(int i = 0; i < 10; i++){
    int r = repl[i];
    char temp = one[r];
    one[r] = two[r];
    two[r] = temp;
  }
}


int main(void) {
  char oneStr[100] = "aaaaaaaaaaa";
  char twoStr[100] = "bbbbbbbbbbb";

  // int replArray[10] = {0, 1, 2, 3, 2, 1, 6, 4, 2, 3};
  // for (int i = 0; i < 10; i++){
  //   int r = replArray[i];
  //   printf("%d\n", replArray[r]);
  // }

  StringBeans(oneStr, twoStr, replArray);
  printf("%s\n%s\n", oneStr, twoStr);

  return 0;
}