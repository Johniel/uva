#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdio>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()

using namespace std;

struct Edge{
  int src, dst;
  Edge(int s, int d) : src(s), dst(d) {}
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

bool operator < (Edge a, Edge b)
{
  if(a.src != b.src)return a.src < b.src;
  return a.dst < b.dst;
}

const int LIGHT = (1 << 10) + 1, ROOM = 10;

struct State{
  int l, r;
  vector<string> path;
  State(){}
  State(int _l, int _r) : l(_l), r(_r) {}
};

vector<string> bfs(const Graph &graph, const Graph &light, int src, int dst)
{
  const int size = graph.size();
  static bool visited[LIGHT][ROOM];
  static char tmp[250];

  if(size == 1){
    return vector<string>(1, "The problem can be solved in 0 steps:");
  }
  
  fill(&visited[0][0], &visited[LIGHT-1][ROOM], false);

  queue<State> q;    
  State ini(1 << src, src);  
  visited[ini.l][ini.r] = true;

  for(q.push(ini); !q.empty(); q.pop()){
    State s = q.front();

    if(s.r == dst && s.l == (1 << dst)){
      sprintf(tmp, "The problem can be solved in %d steps:", s.path.size());
      s.path.insert(s.path.begin(), string(tmp));
      return s.path;
    }

    FOR(e, graph[s.r]){
      if(!(s.l & (1 << e->dst)))continue;
      if(visited[s.l][e->dst])continue;
      visited[s.l][e->dst] = true;
      State t = s;
      t.r = e->dst;
      sprintf(tmp, "Move to room %d.", e->dst + 1);
      t.path.push_back(string(tmp));
      q.push(t);
    }

    FOR(e, light[s.r]){
      State t = s;
      int msk = 1 << e->dst;
      if(t.r == e->dst)continue;
      t.l ^= msk;
      if(visited[t.l][t.r])continue;
      visited[t.l][t.r] = true;
      if(t.l & msk){
	sprintf(tmp, "Switch on light in room %d.", e->dst + 1);
      }
      else{
	sprintf(tmp, "Switch off light in room %d.", e->dst + 1);
      }
      t.path.push_back(string(tmp));
      q.push(t);
    }
  }

  return vector<string>(1, "The problem cannot be solved.");
}

int main(void)
{
  int tc = 0;
  for(int r, s, d; ; ){
    cin >> r >> d >> s;
    if((r | s | d) == 0)break;    
    int src, dst;
    Graph graph(r), light(r);
    for(int i=0; i<d; ++i){
      cin >> src >> dst;
      --src, --dst;
      graph[src].push_back(Edge(src, dst));
      graph[dst].push_back(Edge(dst, src));
    }
    for(int i=0; i<s; ++i){
      cin >> src >> dst;
      --src, --dst;
      light[src].push_back(Edge(src, dst));
    }

    for(int i=0; i<r; ++i){
      sort(ALL(graph[i]));
      sort(ALL(light[i]));
    }

    cout << "Villa #" << ++tc << endl;
    vector<string> path = bfs(graph, light, 0, r-1);
    REP(i, path.size()){
      if(i)cout << "- ";
      cout << path[i] << endl;
    }
    cout << endl;
  }
  return 0;
}
