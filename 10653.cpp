#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>

using namespace std;

const int H = 1000 + 1;
const int W = 1000 + 1;

namespace Q{
  pair<int, int> q[H * W];
  int head, tail;
  int size = H * W;
inline
  void init(void){
    head = tail = 0;
  }
inline
  void push(pair<int, int> p){
    q[tail] = p;
    tail = ++tail % size;
  }
inline
  pair<int, int> front(void){
    return q[head];
  }
inline
  void pop(void){
    head = ++head % size;
  }
inline
  bool empty(void){
    return head == tail;
  }
};

bool g[H][W];

inline
int bfs(int h, int w, pair<int, int> src, pair<int, int> dst)
{
  const int adj = 4;
  const int di[] = {0, 0, -1, 1};
  const int dj[] = {-1, 1, 0, 0};
  static int c[H][W];
  Q::init();
  g[src.first][src.second] = false;
  c[src.first][src.second] = 0;
  for(Q::push(src); !Q::empty(); Q::pop()){
    pair<int, int> n = Q::front();
    for(int d=0; d<adj; ++d){
      int ni = n.first + di[d];
      int nj = n.second + dj[d];
      if(ni < 0 || nj < 0)continue;
      if(h <= ni || w <= nj)continue;
      if(!g[ni][nj])continue;
      g[ni][nj] = false;
      Q::push(make_pair(ni, nj));
      c[ni][nj] = c[n.first][n.second] + 1;
    }
  }
  return c[dst.first][dst.second];
}

int main(void)
{
  int h, w;
  while(true){
    scanf("%d%d", &h, &w);
    if(h == 0 && w == 0)break;
    fill(&g[0][0], &g[h-1][w], true);
    int m;
    cin >> m;
    for(int i=0; i<m; ++i){
      int r, b;
      scanf("%d%d", &r, &b);
      while(b--){
	int c;
	scanf("%d", &c);
	g[r][c] = false;
      }
    }
    pair<int, int> src, dst;
    scanf("%d%d", &src.first, &src.second);
    scanf("%d%d", &dst.first, &dst.second);
    printf("%d\n", bfs(h, w, src, dst));
  }
  return 0;
}
