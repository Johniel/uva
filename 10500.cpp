#include <iostream>
#include <algorithm>

using namespace std;

const int H = 11, W = 11;

const int FAR = 0, LOOKED = 1, VISITED = 2;

char maze[H][W];
int cell[H][W];

int adj = 4;
int di[] = {-1, 0, 1, 0};
int dj[] = {0,  1, 0, -1};

inline
bool isIn(int i, int j, int h, int w)
{
  return !(i < 0 || h <= i || j < 0 || w <= j);
}

inline
void look(int i, int j, int h, int w)
{  
  cell[i][j] = VISITED;
  for(int d=0; d<adj; ++d){
    int ni = i + di[d], nj = j + dj[d];
    if(isIn(ni, nj, h, w))
      cell[ni][nj] = max(cell[ni][nj], LOOKED);
  }
  return ;
}

int sim(int h, int w, int pi, int pj)
{
  int cnt = 0, dir = 0, flg = 0;
  fill(&cell[0][0], &cell[h-1][w], FAR);

  while(flg + cnt+1 < h * w){    
    look(pi, pj, h, w);    
    bool flg = true;
    for(int d = 0; d<adj; ++d){
      int ni = pi + di[d], nj = pj + dj[d];
      if(!isIn(ni, nj, h, w))continue;
      if(maze[ni][nj] == 'X')continue;
      if(cell[ni][nj] == VISITED)continue;
      pi = ni;
      pj = nj;
      ++cnt;	
      flg = false;
      break;
    }
    if(flg)break;
  }
  return cnt;
}

int main(void)
{
  bool flg = true;
  for(int h, w; ; ){
    cin >> h >> w;
    if(h + w == 0)break;
    cout << endl;
    int pi, pj;
    cin >> pi >> pj;
    for(int i=0; i<h; ++i){
      for(int j=0; j<w; ++j){
	cin >> maze[i][j];
      }
    }
    int re = sim(h, w, pi - 1, pj - 1);
    cout << '|';
    for(int j=0; j<w; ++j){
      cout << "---|";
    }
    cout << endl;
    for(int i=0; i<h; ++i){
      cout << '|';
      for(int j=0; j<w; ++j){
	cout << ' ' << (cell[i][j]? maze[i][j] : '?') << " |" ;
      }
      cout << endl;
      cout << '|';
      for(int j=0; j<w; ++j){
	cout << "---|";
      } 
      cout << endl;
    }
    cout << endl;
    cout << "NUMBER OF MOVEMENTS: " << re << endl;
  }
  return 0;
}
