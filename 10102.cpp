#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main(void)
{
  int size;
  const int inf = 1 << 22;
  while(cin >> size){
    int g[size][size];
    int w[size][size];
    bool vis[size][size];
    for(int i=0; i<size; ++i){
      for(int j=0; j<size; ++j){
        char c;
        cin >> c;
        g[i][j] = c - '0';
      }
    }
    int mx = -1;
    for(int i=0; i<size; ++i){
      for(int j=0; j<size; ++j){        
        if(g[i][j] != 1)continue;
        //cout << "############################   " << i << ' ' << j << endl;
        fill(&vis[0][0], &vis[size-1][size], false);
        queue< pair<int, int> > q;
        vis[i][j] = true;     
        w[i][j] = 0;
        int mn = 1 << 22;
        for(q.push(make_pair(i, j)); q.size(); q.pop()){
          pair<int, int> n = q.front();
          //cout << n.first << " : " << n.second << endl;
          if(g[n.first][n.second] == 3){
            mn = min(mn, w[n.first][n.second]);
            continue;
          }
          const int adj = 4;
          const int di[] = {0, 0, -1, 1};
          const int dj[] = {-1, 1, 0, 0};
          for(int d=0; d<adj; ++d){
            int ni = n.first + di[d];
            int nj = n.second + dj[d];
            if(ni < 0 || nj < 0)continue;
            if(size <= ni || size <= nj)continue;           
            if(vis[ni][nj])continue;
            vis[ni][nj] = true;
            w[ni][nj] = w[n.first][n.second] + 1;
            q.push(make_pair(ni, nj));
          }
        }
        mx = max(mx, mn);
      }
    }
    cout << mx << endl;
  }
  return 0;
}
