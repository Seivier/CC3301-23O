#include <stdio.h>
#include <stdlib.h>

int bits1(int n);

int main(int argc, char* argv[]) {
  int x = atoi(argv[1]);
  printf("%x tiene %d bits en 1\n", x, bits1(x));
  return 0;
}

int bits1(int n) {
  int q = 0;
  while(n) {
    if (n&1) {
      q++;
    }
    n >>= 1;
  }
  return q;
}
