#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>

using namespace std;

const int H = 8, W = 8;

inline
bool isIn(int h, int w)
{
  return !(h < 0 || H <= h || w < 0 || W <= w);
}

int bfs(int h1, int w1, int h2, int w2)
{
  static const int adj = 8;
  static const int di[] = {0, 0, -1, -1, -1, 1, 1, 1};
  static const int dj[] = {-1, 1, -1, 0, 1, -1, 0, 1};
  static int visited[H][W];
  queue< pair<int, int> > Q;
  fill(&visited[0][0], &visited[H-1][W], 0);
  visited[h1][w1] = 1;
  for(Q.push(make_pair(h1, w1)); !Q.empty(); Q.pop()){
    pair<int, int> p = Q.front();
    if(p.first == h2 && p.second == w2)break;
    for(int d=0; d<adj; ++d){      
      for(int l=1; ; ++l){
	int ni = p.first  + di[d] * l;
	int nj = p.second + dj[d] * l;
	if(isIn(ni, nj)){
	  if(visited[ni][nj])continue;
	  visited[ni][nj] = visited[p.first][p.second] + 1;
	  Q.push(make_pair(ni, nj));
	}
	else break;
      }
    }
  }
  /*
  for(int i=0; i<H; ++i){
    for(int j=0; j<W; ++j){
      printf("%3d ", visited[i][j]);
    }
    printf("\n");
  }
  */
  return visited[h2][w2] - 1;
}

int main(void)
{
  for(int h1, w1, h2, w2; ; ){
    cin >> h1 >> w1 >> h2 >> w2;
    if(h1 + w1 + h2 + w2 == 0)break;
    cout << bfs(h1-1, w1-1, h2-1, w2-1) << endl;
  }
  return 0;
}
