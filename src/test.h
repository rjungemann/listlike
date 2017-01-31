#ifndef TEST_H
#define TEST_H

#include "stdio.h"

#define test_start(a) \
  printf("# %s\n", a);
#define test_describe(a) \
  printf("## %s\n", a);
#define test_ok(a, b) \
  printf("%s %s\n", (a == 0) ? "-" : "+", b)
#define test_end() \
  printf("\n");

#endif
