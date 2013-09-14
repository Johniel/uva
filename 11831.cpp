#include <iostream>
#include <algorithm>

using namespace std;

const int H = 100, W = 100;

char g[H][W];

int sim(int pi, int pj, int h, int w, int dir, string s)
{
  const int adj = 4;
  const int di[] = {-1, 0, 1, 0};
  const int dj[] = {0, 1, 0, -1};
  int cnt = 0;
  for(int i=0; i<s.size(); ++i){
    if(s[i] == 'D')dir = (dir + 1) % adj;
    else if(s[i] == 'E')dir = (dir - 1 + adj) % adj;
    else if(s[i] == 'F'){
      int ni = pi + di[dir];
      int nj = pj + dj[dir];
      if(ni < 0 || h <= ni || nj < 0 || w <= nj)continue;
      if(g[ni][nj] == '#')continue;
      if(g[ni][nj] == '*'){
	++cnt;
	g[ni][nj] = '.';
      }
      pi = ni;
      pj = nj;
    }
  }
  return cnt;
}

int main(void)
{  
  while(true){
    int h, w, c;
    cin >> h >> w >> c;
    if(h == 0 && w == 0 && c == 0){
      break;
    }
    int pi, pj, dir;
    for(int i=0; i<h; ++i){
      for(int j=0; j<w; ++j){
	cin >> g[i][j];
	if(g[i][j] == 'N'){
	  dir = 0;
	  pi = i;
	  pj = j;
	}
	else if(g[i][j] == 'S'){
	  dir = 2;
	  pi = i;
	  pj = j;
	}
	else if(g[i][j] == 'L'){
	  dir = 1;
	  pi = i;
	  pj = j;
	}
	else if(g[i][j] == 'O'){
	  dir = 3;
	  pi = i;
	  pj = j;
	}
      }
    }
    string s;
    cin >> s;
    cout << sim(pi, pj, h, w, dir, s) << endl;
  }
  return 0;
}
