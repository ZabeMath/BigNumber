#include <stdio.h>
#include <stdlib.h>

struct BigNumber {
  int sign; // 0 = plus ; 1 = minus
  int wordcount;
  int words[]; //each word contains 1 (future plan: 9) decimal place of the number.
};

struct BigNumber * init(int sign, char * number) {
  int i, len = strlen(number);
  struct BigNumber * bignumber = malloc(sizeof(struct BigNumber) + len * sizeof(int)); // allocates space for BigNumber
  bignumber->sign = sign;
  bignumber->wordcount = len;
  for( i = 0 ; i < len ; ++i ) {
    bignumber->words[len - 1 - i] = number[i] - '0'; // Convert char array to integer array
  }
  return bignumber;
}

int printBigNumber(struct BigNumber * bignumber) {
  int i;
  for( i = bignumber->wordcount - 1 ; i >= 0 ; --i ) {
    printf("%d", bignumber->words[i]);
  }
  printf("\n");
  return 0;
}

int main() {
  struct BigNumber * test = init(0, "42");
  printBigNumber(test);
  return 0;
}
