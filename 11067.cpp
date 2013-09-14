#include <iostream>
#include <algorithm>

#include <cstdio>

using namespace std;

const int H = 100 + 1, W = 100 + 1;

bool node[H][W];

struct Step{
  int i, j, step;
  Step(int _i, int _j, int s) : i(_i), j(_j), step(s) {}
};

inline bool isIn(int i, int j, int h, int w)
{
  return !(i < 0 || h <= i || j < 0 || w <= j);
}

#include <queue>
int solve(const int h, const int w)
{
  static const int adj = 2;
  static const int di[] = {0, 1}, dj[] = {1, 0};
  static int visited[H][W], cnt[H][W];
  queue<Step> q;  
  fill(&visited[0][0], &visited[H-1][W], (1 << 20));
  fill(&cnt[0][0], &cnt[H-1][W], 0);
  visited[0][0] = cnt[0][0] = 1;
  for(q.push(Step(0, 0, 1)); !q.empty(); q.pop()){
    Step p = q.front();
    if(visited[p.i][p.j] < p.step)continue;
    //cout << p.i << ' ' << p.j << endl;
    for(int d=0; d<adj; ++d){
      int ni = p.i + di[d], nj = p.j + dj[d];
      if(!isIn(ni, nj, h, w) || !node[ni][nj])continue;
      if(visited[ni][nj] > p.step + 1){
	cnt[ni][nj] = cnt[p.i][p.j];
	visited[ni][nj] = p.step + 1;
	q.push(Step(ni, nj, visited[ni][nj]));
      }
      else if(visited[ni][nj] == p.step + 1){
	cnt[ni][nj] += cnt[p.i][p.j];
      }
    }
  }
  /*
  for(int i=0; i<h; ++i){
    for(int j=0; j<w; ++j){
      printf("%3d", cnt[i][j]);
    }
    puts("");
  }
  */
  return visited[h-1][w-1] == (1 << 20)? -1 : cnt[h-1][w-1];
}

int main(void)
{
  for(int h, w; ; ){
    cin >> h >> w;
    if(h + w == 0)break;
    fill(&node[0][0], &node[H-1][W], true);
    int block;
    cin >> block;
    for(int i=0; i<block; ++i){
      int c, r;
      cin >> c >> r;
      node[c][r] = false;
    }
    int result = solve(h+1, w+1);
    if(result >= 1){
      cout << "There ";
      if(result == 1)cout << "is one path" ;
      else cout << "are " << result << " paths" ;
      cout << " from Little Red Riding Hood\'s ";
      cout << "house to her grandmother's house." << endl;
      
    }
    else cout << "There is no path." << endl;
  }
  return 0;
}
