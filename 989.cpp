#include <iostream>
#include <algorithm>

#define REP(i, n) for(int i=0; i<(int)n; ++i)

using namespace std;

static const int N = 10;
static const int M = 3;
static const int EMPTY = 0;

int field[N][N];
bool column[N][N], row[N][N], block[M][M][N];

void output(int n)
{
  REP(i, n*n){
    REP(j, n*n){
      cout << field[i][j];
      if(j+1 != n*n)cout << ' ' ;
    }
    cout << endl;
  }
  return ;
}

bool BT(const int &i, const int &j, const int &size, int cnt)
{
  int nj = (j + 1)%(size*size);
  int ni = (nj == 0)? i+1 : i;
  if(cnt == 0){
    output(size);
    return true;
  }
  else if(field[i][j] != EMPTY){
    if(BT(ni, nj, size, cnt-1))
      return true;
  }
  else for(int k=0 + 1; k<9 + 1; ++k){
    if(column[i][k] && row[j][k] && block[i/size][j/size][k]){
      column[i][k] = row[j][k] = block[i/size][j/size][k] = false;
      field[i][j] = k;
      if(BT(ni, nj, size, cnt-1))return true;
      field[i][j] = EMPTY;
      column[i][k] = row[j][k] = block[i/size][j/size][k] = true;
    }
  }
  return false;
}

int main(void)
{
  int n, tc = 0;
  while(cin >> n){
    if(tc++)cout << endl;
    REP(i, n*n)REP(j, n*n)cin >> field[i][j];
    fill(&column[0][0], &column[N-1][N], true);
    fill(&row[0][0], &row[N-1][N], true);
    fill(&block[0][0][0], &block[M-1][M-1][N], true);
    REP(i, n*n)REP(j, n*n)
      column[i][field[i][j]] = row[j][field[i][j]] = block[i/n][j/n][field[i][j]] = false;
    if(BT(0, 0, n, n*n*n*n) == false)cout << "NO SOLUTION" << endl;
  }
  return 0;
}
