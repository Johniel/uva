#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int input(void)
{
  int sum = 0, w = 1;  
  for(int i=0; i<9; ++i){
    char c;
    cin >> c;
    if(c == '1')sum += w;
    w <<= 1;
  }
  return sum;
}

int f(int n)
{
  static bool g[3][3], h[3][3];
  static const int adj = 4;
  static const int di[] = {0, 0, -1, 1}; 
  static const int dj[] = {-1, 1, 0, 0};
  int m = 0, cnt;  
  cnt = 0;
  for(int i=0; i<3; ++i){
    for(int j=0; j<3; ++j){
      g[i][j] = n & (1 << cnt);
      ++cnt;
    }
  }
  //#define TEST
#ifdef TEST
  for(int i=0; i<3; ++i){
    for(int j=0; j<3; ++j){
      cout << g[i][j];
    }
    cout << endl;
  }
  cout << endl;
#endif
  for(int i=0; i<3; ++i){
    for(int j=0; j<3; ++j){
      int tmp = 0;
      for(int d=0; d<adj; ++d){
	int ni = i + di[d];
	int nj = j + dj[d];
	if(ni < 0 || 3 <= ni)continue;
	if(nj < 0 || 3 <= nj)continue;
	tmp += g[ni][nj];
      }
      h[i][j] = tmp % 2;
    }
  }
#ifdef TEST
  for(int i=0; i<3; ++i){
    for(int j=0; j<3; ++j){
      cout << h[i][j];
    }
    cout << endl;
  }
  cout << endl;
#endif
  cnt = 0;
  for(int i=0; i<3; ++i){
    for(int j=0; j<3; ++j){
      m +=  h[i][j] * (1 << cnt);
      ++cnt;
    }
  }
  return m;
}

int solve(int n)
{
  if(n == 0 || n == (1 << 10) - 1)return -1;
  map<int, int> visited;
  visited[n] = 0;
  for(int i=0; ; ++i){
    n = f(n);
    if(n == 0 || n == (1 << 10) - 1)return i;
    map<int, int>::iterator itr = visited.find(n);
    if(itr != visited.end())return itr->second;
  }
  return -2;
}

int main(void)
{
  int tc;
  for(cin >> tc; tc--; cout << solve(input()) << endl);
  return 0;
}
