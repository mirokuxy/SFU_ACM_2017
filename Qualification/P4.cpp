#include <cstdio>
#include <cstring>

const int MAX_LEN = 1000 + 5;
char line[MAX_LEN];

bool work() {
  scanf("%s", line);
  const int len = strlen(line);
  if (len == 1 && line[0] == '0') {
    return false;
  }

  int res = 0;
  int multi = 1;
  for (int i=0; i<len; i++) {
    const char c = line[i];
    const int digit = c - '0';
    multi *= -1;
    res += digit * multi;
    //printf("res = %d, digit = %d, multi = %d\n", res, digit, multi);
  }
  //printf("%d\n", res);
  bool dividable = res % 11 == 0;

  printf("%s is%s a multiple of 11.\n", line, dividable ? "" : " not");
  return true;
}

int main() {
  while (work()) {};

  return 0;
}