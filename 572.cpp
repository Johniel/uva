#include <iostream>
#include <algorithm>

using namespace std;

const int H = 100 + 1, W = 100 + 1;

char g[H][W];

const int adj = 8;
const int di[] = {0, 0, -1, -1, -1, 1, 1, 1};
const int dj[] = {-1, 1, -1, 0, 1, -1, 0, 1};

inline
bool isIn(int i, int j, int h, int w)
{
  return !(i < 0 || h <= i || j < 0 || w <= j);
}

void rec(int i, int j, int h, int w)
{
  g[i][j] = '*';
  for(int d=0; d<adj; ++d){
    int ni = i + di[d];
    int nj = j + dj[d];
    if(isIn(ni, nj, h, w) && g[ni][nj] == '@'){
      rec(ni, nj, h, w);
    }
  }
  return ;
}

int main(void)
{
  for(int h, w; ; ){
    cin >> h >> w;
    if(h + w == 0)break;
    for(int i=0; i<h; ++i){
      for(int j=0; j<w; ++j){
	cin >> g[i][j];
      }
    }
    int sum = 0;
    for(int i=0; i<h; ++i){
      for(int j=0; j<w; ++j){
	if(g[i][j] == '@'){
	  rec(i, j, h, w);
	  ++sum;
	}
      }
    }
    cout << sum << endl;
  }
  return 0;
}
