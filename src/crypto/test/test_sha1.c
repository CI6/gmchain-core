#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "crypto/sha1.c"

void test_sha1() {
  char const string[] = "ci6ci6";
  char const expect[] = "74f9e9124d77895a16c189703cc45166ad083fc6";
  char result[21];
  char hexresult[41];
  // sha1 calculate, save sha1-value to result
  Sha1(result, string, strlen(string));
  Sha1Hex(hexresult, result);
  printf("%s , %d", hexresult, strncmp(hexresult, expect, 40) == 0);
}
