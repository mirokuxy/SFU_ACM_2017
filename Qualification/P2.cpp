#include <cstdio>

const int MAXN = 10 + 2;

char origin[MAXN][MAXN];
char moves[MAXN][MAXN];
char result[MAXN][MAXN];

int n;

void init() {
  scanf("%d", &n);
  for(int i=0; i<n; i++) {
    scanf("%s", origin[i]);
  }
  for(int i=0; i<n; i++) {
    scanf("%s", moves[i]);
  }
}

bool check_mine() {
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      if (moves[i][j] == 'x' && origin[i][j] == '*') {
        return true;
      }
    }
  }
  return false;
}

bool in_range(int i, int j) {
  if (0 <= i && i < n && 0 <= j && j < n) {
    return true;
  } else {
    return false;
  }
}

int count_neighbors(int i, int j) {
  const int steps[][2] = {  {-1, -1}, {-1, 0}, {-1, 1}, 
                      {0, -1}, {0, 1}, 
                      {1, -1}, {1, 0}, {1, 1} };
  int count = 0;
  for(const int* step : steps) {
    int ni = i + step[0];
    int nj = j + step[1];
    if (in_range(ni, nj) && origin[ni][nj] == '*') {
      count ++;
    }
  }
  return count;
}

void Work(bool isFirst) {
  init();
  bool mine_touched = check_mine();

  for (int i=0; i<n ;i++) {
    for (int j=0; j<n; j++) {
      if (mine_touched) {
        if (origin[i][j] == '*') {
          result[i][j] = '*';
        } else if (moves[i][j] == 'x') {
          result[i][j] = '0' + count_neighbors(i,j);
        } else {
          result[i][j] = '.';
        }
      } else { // not mined
        if (moves[i][j] == 'x') {
          result[i][j] = '0' + count_neighbors(i,j);
        } else {
          result[i][j] = '.';
        }
      }
    }
  }

  if (!isFirst) {
    printf("\n");
  }
  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      printf("%c", result[i][j]);
    }
    printf("\n");
  }
}

int main() {
  int cases;
  scanf("%d", &cases);

  for (int i=0; i<cases; i++) {
    Work(i==0);
  }

  return 0;
}