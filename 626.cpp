#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

const int N = 100 + 1;

int adj[N][N];
bool visited[N];
int cnt;
int path[3];

set< pair<pair<int, int>, int> > s;

void rec1(int node, int size, int d)
{  
  path[d] = node;
  if(d == 2){
    if(adj[path[2]][path[0]]){
      ++cnt;
      s.insert(make_pair(make_pair(path[0]+1, path[1]+1), path[2]+1));
    }
    return ;
  }
  visited[node] = true;
  for(int i=node+1; i<size; ++i){
    if(adj[node][i] == 0)continue;
    if(visited[i])continue;
    rec1(i, size, d + 1);
  }
  visited[node] = false;
  return ;
}

void rec2(int node, int size, int d)
{  
  path[d] = node;
  if(d == 2){
    if(adj[path[2]][path[0]]){
      ++cnt;
      s.insert(make_pair(make_pair(path[0]+1, path[1]+1), path[2]+1));
    }
    return ;
  }
  visited[node] = true;
  for(int i=node-1; 0<=i; --i){
    if(adj[node][i] == 0)continue;
    if(visited[i])continue;
    rec2(i, size, d + 1);
  }
  visited[node] = false;
  return ;
}

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()

#define fr first 
#define sc second

int main(void)
{  
  int n;
  while(cin >> n){
    for(int i=0; i<n; ++i){
      visited[i] = false;
      for(int j=0; j<n; ++j){
	cin >> adj[i][j];
      }
    }
    s.clear();
    cnt = 0;
    for(int i=0; i<n; ++i){
      rec1(i, n, 0);
    } 
    for(int i=n-1; 0<=i; --i){
      rec2(i, n, 0);
    }    
    FOR(i, s){
      cout << i->fr.fr << ' ' << i->fr.sc << ' ' << i->sc << endl;
    }
    cout << "total:" << cnt << endl;
    cout << endl;
  }
  return 0;
}
