#include <iostream>
#include <algorithm>

using namespace std;

const int G = 15 + 1;
const int inf = 1 << 22;

int g[G][G], p[G][G];

inline
bool inside(int i, int j, int size)
{
  return !(i < 0 || size <= i || j < 0 || size <= j);
}

int surround(int i, int j, int size)
{
  const int adj = 4;
  const int di[] = {0, 0, -1, 1};
  const int dj[] = {-1, 1, 0, 0};
  
  int sum = 0;
  for(int d=0; d<adj; ++d){
    int ni = i + di[d];
    int nj = j + dj[d];
    if(!inside(ni, nj, size))continue;
    sum += p[ni][nj];
  }
  return sum;
}

int make(int size)
{
  int sum = 0;
  for(int i=0; i+1<size; ++i){
    for(int j=0; j<size; ++j){
      int s = surround(i, j, size);
      if(s % 2)p[i+1][j] = 1;        
    }
  }
  for(int i=0; i<size; ++i){
    for(int j=0; j<size; ++j){
      int s = surround(i, j, size);
      if(s % 2)return inf;
      if(p[i][j] == 0 && g[i][j] == 1)return inf;
      if(p[i][j] == 1 && g[i][j] == 0)++sum;
    }
  }
  return sum;
}

int solve(int size)
{
  int mn = inf;
  for(int i = 0; i < (1 << size); ++i){
    bool flg = true;
    fill(&p[0][0], &p[size-1][size], 0);
    for(int j = 0; j < size; ++j){
      bool bit = i & (1 << j);
      if(g[0][j] && !bit){ flg = false; break; }
      p[0][j] = bit;
    }
    if(flg)mn = min(mn, make(size));
  }
  return mn == inf ? -1 : mn;
}

int main(void)
{
  int tc, cnt = 0, n;
  for(cin >> tc; tc--; ){
    cin >> n;
    for(int i=0; i<n; ++i){
      for(int j=0; j<n; ++j){
        cin >> g[i][j];
      }
    }
    cout << "Case " << ++cnt << ": " << solve(n) << endl;
  }
  return 0;
}
