#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int intpow(int a, int b){
  int i, result = 1;
  for( i = 0 ; i < b ; ++i )
    result *= a;
  return result;
}

struct BigNumber {
  int sign; // 0 = plus ; 1 = minus
  int wordcount;
  int words[]; //each word contains 9 decimal place of the number.
};

struct BigNumber * init(int sign, char * number) {
  int i, j, temp, stringlen = strlen(number);
  int len = stringlen / 9 + (stringlen % 9 == 0 ? 0 : 1);
  struct BigNumber * bignumber = malloc(sizeof(struct BigNumber) + len * sizeof(int)); // allocates space for BigNumber
  bignumber->sign = sign;
  bignumber->wordcount = len;
  for( i = 0 ; i < len - 1 ; ++i ) {
    temp = 0;
    for( j = 0 ; j < 9 ; ++j )
      temp += (number[stringlen - 9 * (i + 1) + j] - '0') * intpow(10, 8 - j);
    bignumber->words[i] = temp;
  }
  temp = 0;
  int last_word_len = stringlen % 9;
  if(last_word_len == 0)
    last_word_len = 9;
  for( i = 0 ; i < last_word_len ; ++i )
    temp += (number[i] - '0') * intpow(10, last_word_len - 1 - i);
  bignumber->words[len - 1] = temp;
  return bignumber;
}

void printBigNumber(struct BigNumber * bignumber) {
  if(bignumber->wordcount == 1 && bignumber->words[0] == 0)
    printf("0\n");
  else {
    printf("%s", bignumber->sign == 0 ? "" : "-");
    int i, j, first_word_len = floor(log10(abs(bignumber->words[bignumber->wordcount - 1]))) + 1;;
    char temp[first_word_len];
    sprintf(temp, "%d", bignumber->words[bignumber->wordcount - 1]);
    printf("%s", temp);
    for( i = bignumber->wordcount - 2 ; i >= 0 ; --i ) {
      char temp2[9];
      sprintf(temp2, "%d", bignumber->words[i]);
      int word_len = strlen(temp2);
      for( j = 0 ; j < word_len ; ++j )
        temp2[j + 9 - word_len] = temp2[j];
      for( j = 0 ; j < 9 - word_len ; ++j )
        temp2[j] = '0';
      printf("%s", temp2);
    }
    printf("\n");
  }
}

int main() {
  struct BigNumber * test = init(0, "42");
  printBigNumber(test);
  return 0;
}
