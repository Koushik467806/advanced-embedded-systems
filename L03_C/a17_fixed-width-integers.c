#include <stdio.h>
#include <stdint.h>

// To keep a same size everywhere

int main() {
  int8_t a = 100; // 8-bit integer
  int16_t b = 30000; // 16-bit integer
  int32_t c = 2000000; // 32-bit integer
  int64_t d = 9000000000; // 64-bit integer
  uint8_t e = 5; // unsigned 8-bit (%u)
  uint16_t f = 10000; // unsigned 16-bit (%u)
  uint32_t g = 102030159; // unsigned 32-bit (%u)
  uint64_t h = 1326574683452; // unsigned 64-bit (%llu)

  printf("%d\n", a);
  printf("%d\n", b);
  printf("%d\n", c);
  printf("%lld\n", d); // use %lld for 64-bit
  return 0;
}

// Use these when size is very important