#include <iostream>
#include <algorithm>

using namespace std;

const int adj = 4;
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};

bool isIn(int i, int j, int h, int w)
{
  return !(i < 0 || h <= i || j < 0 || w <= j);
}

int turnLeft(int d)
{
  return (d + 3) % adj;
}

int turnRight(int d)
{
  return (d + 1) % adj;
}
#include <cstdio>
int main(void)
{
  for(int h, w; ; ){
    cin >> h >> w;
    if(h == 0 && w == 0)break;
    int maze[h][w], cnt[h][w];
    for(int i=0; i<h; ++i){
      for(int j=0; j<w; ++j){
	char c;
	cin >> c;
	maze[i][j] = c - '0';
	cnt[i][j] = 0;
      }
    }
    int i = h - 1, j = 0, dir = 1;
    while(true){
      //cout << i << ' ' << j << ' ' << dir << endl;
      int ni = i + di[dir], nj = j + dj[dir];
      if(!isIn(ni, nj, h, w) || maze[ni][nj]){
	dir = turnLeft(dir);
	continue;
      }
      int d = turnRight(dir);
      int mi = ni + di[d], mj = nj + dj[d];
      if(isIn(mi, mj, h, w) && !maze[mi][mj]){
	dir = turnRight(dir);
      }
      ++cnt[i][j];
      i = ni;
      j = nj;
      if(i == h-1 && j == 0)break;      
    }
    int result[5];
    fill(result, result + 5, 0);
    for(int i=0; i<h; ++i){
      for(int j=0; j<w; ++j){
	if(maze[i][j])continue;
	if(cnt[i][j] < 5){
	  ++result[cnt[i][j]];
	}
      }
    }
    for(int i=0; i<5; ++i){
      printf("%3d", result[i]);
    }
    cout << endl;
  }
  return 0;
}
