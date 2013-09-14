#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()

using namespace std;

static const int NODE = 27 * 27;

typedef vector< vector<int> > Graph;

bool bfs(const Graph &G, int src, int dst, int p[])
{
  static bool visited[NODE];
  queue<int> Q;
  fill(visited, visited + NODE, false);
  for(Q.push(src); !Q.empty(); Q.pop()){
    int n = Q.front();
    FOR(e, G[n]){
      if(visited[*e])continue;
      Q.push(*e);
      p[*e] = n;
      visited[*e] = true;
      if(*e == dst)return true;
    }    
  }
  return false;
}

int main(void)
{
  int n, p[NODE];
  bool flg = true;
  string name[NODE];
  while(cin >> n){
    string src, dst;
    int cnt = 0;
    Graph G(NODE);
    map<string, int> M;
    if(flg)flg = false;
    else cout << endl;
    REP(i, n){
      cin >> src >> dst;
      if(M[src] == 0){
	M[src] = ++cnt;
	name[cnt] = src;
      }
      if(M[dst] == 0){
	M[dst] = ++cnt;
	name[cnt] = dst;
      }
      int s = M[src], d = M[dst];
      G[s].push_back(d);
      G[d].push_back(s);
    }
    cin >> src >> dst;
    int s = M[src], d = M[dst];
    if(s == d && d != 0){
      cout << src << ' ' << dst << endl;
    }
    else if(s == 0 || d == 0 || !bfs(G, d, s, p)){    
      cout << "No route" << endl;
    }
    else{
      for(int i=s; i != d; i = p[i]){
	cout << name[i] << ' ' << name[p[i]] << endl;
      }
    }
  }
  return 0;
}
