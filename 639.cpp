#include <iostream>
#include <algorithm>

using namespace std;

char g[4][4];
int b[4][4]; 

char c[4][4];

inline
void f(int i, int j, int size, int n)
{
  const int di[] = {0, 0, -1, 1};
  const int dj[] = {-1, 1, 0, 0};
  for(int e = 0; e < 4; ++e){
    for(int d = 1; ; ++d){
      int ni = i + di[e] * d;
      int nj = j + dj[e] * d;
      if(ni < 0 || nj < 0)break;
      if(size <= ni || size <= nj)break;
      if(g[ni][nj] == 'X')break;
      b[ni][nj] += n;
    }
  }
  b[i][j] += n;
  return ;
}

void output(int size)
{
  for(int i = 0; i < size; ++i){
    for(int j = 0; j < size; ++j){
      if(g[i][j] == 'X')cout << 'X';
      else if(c[i][j] == 'O')cout << '@';
      else cout << b[i][j] ;
    }
    cout << endl;
  }
  cout << endl;
  return ;
}

inline
void bt(int size, int &sum, int i, int j, int d)
{  
  sum = max(sum, d);  
  for(; i < size; ++i){
    for(; j < size; ++j){
      if(b[i][j] || g[i][j] == 'X')continue;
      f(i, j, size, +1);
      c[i][j] = 'O';
      bt(size, sum, i, j+1, d + 1);
      c[i][j] = '.';
      f(i, j, size, -1);
    }
    j = 0;
  }
  return ;
}

int main(void)
{
  for(int n; cin >> n && n; ){
    for(int i=0; i<n; ++i){
      for(int j=0; j<n; ++j){
	cin >> g[i][j];
	b[i][j] = false;
	c[i][j] = '.';
      }
    }
    int sum = 0;
    bt(n, sum, 0, 0, 0);
    cout << sum << endl;
  }
  return 0;
}
