#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <vector>

using namespace std;

const int N = 100 + 1;

int size;
int g[N][N];

int bfs(int a, int b, int c)
{
  queue< pair<int, int> > q;
  map< pair<int, int>, int > w;
  pair<int, int> ini = make_pair(a, b);
  w[ini] = 0;
  for(q.push(ini); q.size(); q.pop()){
    pair<int, int> p = q.front();
    int cost = w[p];
    if(p.first == c || p.second == c)return cost;
    for(int j=1; j<=size; ++j){
      int tmp;
      pair<int, int> n;
      tmp = g[p.second][p.first];
      n = make_pair(p.first, tmp);
      if(tmp && w.find(n) == w.end()){
        w[n] = cost + 1;
        q.push(n);
      }
      tmp = g[p.first][p.second];
      n = make_pair(tmp, p.second);
      if(tmp && w.find(n) == w.end()){
        w[n] = cost + 1;
        q.push(n);
      }
      
    }
  }
  return -1;
}

int main(void)
{
  while(cin >> size && size){
    fill(&g[0][0], &g[size-1][size], 0);
    for(int i=1; i<=size; ++i){
      for(int j=1; j<=size; ++j){
        cin >> g[i][j];
      }
    }    

    /*
    for(int i=1; i<=size; ++i){
      cout << i << " : ";
      for(int j=1; j<=size; ++j){
        cout << g[i][j] << ' ';
      }
      cout << endl;
    }
    */
    
    int a, b, c;
    cin >> a >> b >> c;
    int r = bfs(a, b, c);
    static int cnt = 0;
    cout << "Game #" << ++cnt << endl;
    if(r < 0)cout << "Destination is Not Reachable !" << endl;
    else cout << "Minimum Number of Moves = " << r << endl;
    cout << endl;
  }
  return 0;
}
