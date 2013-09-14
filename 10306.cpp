#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <queue>

using namespace std;

const int inf = 1 << 22;

pair<int, int> p[41];

int bfs(int s, int size)
{
  queue< pair<int, int> > q;
  int w[310][310], mn = inf;
  fill(&w[0][0], &w[310-1][310], -1);
  w[0][0] = 0;
  for(q.push( make_pair(0, 0) ); q.size(); q.pop()){
    pair<int, int> n = q.front();
    for(int i=0; i<size; ++i){
      int ni = n.first + p[i].first;
      int nj = n.second + p[i].second;
      if(s < ni || s < nj)continue;
      if( w[ ni ][ nj ] != -1 )continue;
      w[ ni ][ nj ] = w[ n.first ][ n.second ] + 1;
      if( s * s == ni * ni + nj * nj){
        mn = min( mn, w[ni][nj] ) ;
      }
      q.push( make_pair(ni, nj) );
    }
  }
  return mn;
}

int main(void)
{
  int tc;
  cin >> tc;    
  while( tc-- ){
    int m, s;
    cin >> m >> s;
    for(int i=0; i<m; ++i){
      cin >> p[i].first >> p[i].second;
    }
    int r = bfs(s, m);
    if( r == inf )cout << "not possible" << endl;
    else cout << r << endl;
  }
  return 0;
}
