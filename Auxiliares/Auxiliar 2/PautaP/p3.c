#include <stdio.h>

unsigned repBits(unsigned x, int i, int k, unsigned val);

int main() {

	printf("repBits(0x5555FFFF, 8, 12, 0x123) == 0x%X\n", repBits(0x5555FFFF, 8, 8, 0x123));

}

unsigned repBits(unsigned x, int i, int k, unsigned val) {
  int mask = (~(-1<<k))<<i;
  x &= ~mask;
  val <<= i;
  val &= mask;
  return val | x;
}