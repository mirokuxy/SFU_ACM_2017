#include <cstdio>
#include <algorithm>

int c;
int n;

int work() {
  int min_area = 0;
  for (int a=1; a*a*a <= n; a++) {
    if (n % a != 0) {
      continue;
    }
    const int bc = n / a;
    for (int b=a; b*b <= bc; b++) {
      if (bc % b != 0) {
        continue;
      }
      const int c = bc / b;
      const int area = 2 * (a*b + a*c + b*c);
      min_area = min_area == 0 ? area : std::min(min_area, area);
    }
  }
  return min_area;
}

int main() {
  scanf("%d", &c);
  for (int i=0; i<c; i++) {
    scanf("%d", &n);
    const int area = work();
    printf("%d\n", area);
  }

  return 0;
}