#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct S{
  int i, j;
  int bi, bj;
  S(){}
  S(int _i, int _j, int _bi, int _bj) 
    : i(_i), j(_j), bi(_bi), bj(_bj) {}
};

const int inf = 1 << 27;
const int H = 20 + 1;
const int W = 20 + 1;

char g[H][W];
int c[H][W][H][W];
bool vis[H][W][H][W];

inline
bool inside(int i, int j, int h, int w)
{
  return !(i < 0 || j < 0 || h <= i || w <= j);
}

int bfs(int h, int w)
{
  queue<S> q;
  S ini, fin;
  fill( &c[0][0][0][0], &c[h-1][w-1][h-1][w], inf);
  fill( &vis[0][0][0][0], &vis[h-1][w-1][h-1][w], false);
  for(int i=0; i<h; ++i){
    for(int j=0; j<w; ++j){      
      if( g[i][j] == '@' ){
        ini.i = i;
        ini.j = j;
      }
      else if( g[i][j] == 'x' ){
        ini.bi = i;
        ini.bj = j;
      }
      else if( g[i][j] == 'b' ){
        fin.bi = i;
        fin.bj = j;
      }
      else if( g[i][j] == 'd' ){
        fin.i = i;
        fin.j = j;
      }
    }
  }
  const int adj = 4;
  const int di[] = {0, 0, -1, 1};
  const int dj[] = {-1, 1, 0, 0};
  vis[ini.i][ini.j][ini.bi][ini.bj] = true;
  c[ini.i][ini.j][ini.bi][ini.bj] = 0;
  for( q.push(ini); q.size(); q.pop() ){
    S n = q.front();
    for(int d=0; d<adj; ++d){
      int ni = n.i + di[d];
      int nj = n.j + dj[d];
      if( !inside(ni, nj, h, w) )continue;
      if( g[ni][nj] == '#' )continue;
      if( ni == n.bi && nj == n.bj ){
        int bi = n.i + di[d] * 2;
        int bj = n.j + dj[d] * 2;
        if( !inside(bi, bj, h, w) )continue;
        if( g[bi][bj] == '#' )continue;
        if( g[bi][bj] == 'd' )continue;
        if( vis[ni][nj][bi][bj] )continue;
        vis[ni][nj][bi][bj] = true;
        c[ni][nj][bi][bj] = c[n.i][n.j][n.bi][n.bj] + 1;
        q.push( S(ni, nj, bi, bj) );
      }
      else{
        if( vis[ni][nj][n.bi][n.bj] )continue;
        if( g[ni][nj] == 'd' && ( fin.bi != n.bi || fin.bj != n.bj) )continue;
        vis[ni][nj][n.bi][n.bj] = true;
        c[ni][nj][n.bi][n.bj] = c[n.i][n.j][n.bi][n.bj] + 1;
        q.push( S(ni, nj, n.bi, n.bj) );
      }
    }
  }

  return c[fin.i][fin.j][fin.bi][fin.bj];
}

int main(void)
{
  int h, w;
  while( cin >> h >> w && (h | w) ){
    for(int i=0; i<h; ++i){
      for(int j=0; j<w; ++j){
        cin >> g[i][j];
      }
    }
    int r = bfs(h, w);
    if( r == inf )cout << "No Way!" << endl;
    else cout << r << endl;
  }
  return 0;
}
