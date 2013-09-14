#include <iostream>
#include <algorithm>

using namespace std;

const int H = 8 + 1, W = 8 + 1;
int h, w;
char g[H][W];
bool vis[H][W];

const string s = "IEHOVA#";

string p[H * W];
int size;

string dir[] = {"forth", "left", "right"};
int di[] = {-1, 0, 0};
int dj[] = {0, -1, 1};

bool rec(int i, int j, int d)
{
  if(g[i][j] == '#')return true;
  for(int k=0; k<3; ++k){
    int ni = i + di[k];
    int nj = j + dj[k];
    if(ni < 0 || nj < 0)continue;
    if(h <= ni || w <= nj)continue;
    if(g[ni][nj] != s[d])continue;
    if(rec(ni, nj, d + 1)){
      p[size++] = dir[k];
      return true;
    }
  }
  return false;
}

int main(void)
{
  int tc;
  cin >> tc;
  while(tc--){
    cin >> h >> w;
    for(int i=0; i<h; ++i){
      for(int j=0; j<w; ++j){
        cin >> g[i][j];
      }
    }
    for(int i=0; i<h; ++i){
      for(int j=0; j<w; ++j){
        if(g[i][j] == '@'){
          size = 0;
          rec(i, j, 0);
          i = j = 1 << 22;
        }
      }
    }
    reverse(p, p + size);
    for(int i=0; i<size; ++i){
      if(i)cout << ' ';
      cout << p[i];
    }
    cout << endl;
  }
  return 0;
}
