#include <iostream>
#include <algorithm>
#include <vector>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()

using namespace std;

typedef vector<int> Edges;
typedef vector<Edges> Graph;

const int NODE = 1000 + 1000 + 1;

const int B = 0, C = 1, E = 2;

int color[NODE];
bool visited[NODE];

inline int rev(int c)
{
  return c ^ 1;
}

bool dp(vector< pair<int, int> > &v, int size, int bull)
{  
  const int TABLE = NODE / 2 + 1;
  static bool t[TABLE][TABLE];
  fill(&t[0][0], &t[TABLE-1][TABLE], false);

  //FOR(p, v)cout << p->first << ' '<< p->second << endl;

  REP(i, v.size()){
    if(i == 0){
      t[0][v[0].first] = true;
      t[0][v[0].second] = true;
      continue;
    }    
    REP(j, size){
      if(t[i-1][j]){
	t[i][j + v[i].first] = true;
	t[i][j + v[i].second] = true;
      }
    } 
  }
  
  //REP(i, 10){ REP(j, 10)cout << t[i][j] << ' '; cout << endl; }
  
  return t[v.size()-1][bull];
}

bool rec(const Graph &G, int node, int c, int cnt[])
{
  int next = rev(c);
  visited[node] = true;
  FOR(e, G[node]){
    if(color[*e] == c)return false;
    if(visited[*e])continue;    
    color[*e] = next;
    if(!rec(G, *e, next, cnt))return false; 
  }  
    ++cnt[c];
  return true;
}

bool solve(const Graph &G, int b, int c)
{
  int size = G.size(), cnt[2];
  if(size == 0)return true;
  fill(color, color + size, E);
  fill(visited, visited + size, false);
  vector< pair<int, int> > v;
  REP(i, size){
    if(visited[i])continue;
    cnt[0] = cnt[1] = 0;
    if(!rec(G, i, color[i] = B, cnt))return false;
    v.push_back(make_pair(cnt[0], cnt[1]));
  }
  return dp(v, size, b);
}

int main(void)
{
  int tc, bull, cow, edge, src, dst;
  for(cin >> tc; tc--; ){
    cin >> bull >> cow >> edge;
    Graph G(bull + cow);    
    REP(i, edge){
      cin >> src >> dst;
      --src; 
      --dst;
      G[src].push_back(dst);
      G[dst].push_back(src);
    }
    cout << (solve(G, bull, cow)? "yes" : "no") << endl;
  }
  return 0;
}
