#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

const int G = 100 + 1;
char g[G][G];

int h, w;

bool inside(int i, int j)
{
  return !(i < 0 || j < 0 || h <= i || w <= j);
}

int rec(int i, int j, int d, char c)
{  
  for(int k=0; k<d; ++k){
    if(!inside(i + k, j))return d - 2;   
    if(      g[i + k][j] != c)return d - 2;

    if(!inside(i + k, j + d - 1))return d - 2;
    if(      g[i + k][j + d - 1] != c)return d - 2;    

    if(!inside(i, j + k))return d - 2;
    if(      g[i][j + k] != c)return d - 2;

    if(!inside(i + d - 1, j + k))return d - 2;
    if(      g[i + d - 1][j + k] != c)return d - 2;
  }
  if(!inside(i-1, j-1))return d;
  return rec(i - 1, j - 1, d + 2, c);
}

int solve(int r, int c)
{
  if(!inside(r, c))return 0;
  if(!inside(r-1, c-1))return 1;
  return rec(r-1, c-1, 3, g[r][c]);
}

int main(void)
{
  int tc;
  for(cin >> tc; tc--; ){
    int q;
    cin >> h >> w >> q;
    cin.ignore();
    for(int i=0; i<h; ++i){
      string s;
      getline(cin, s);
      for(int j=0; j<s.size(); ++j){
	g[i][j] = s[j];
      }
    }
    cout << h << ' ' << w << ' ' << q << endl;
    while(q--){
      int r, c;
      cin >> r >> c;
      cout << solve(r, c) << endl;
    }
  }
  return 0;
}
