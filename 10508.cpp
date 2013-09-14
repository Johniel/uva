#include <iostream>
#include <vector>
#include <set>

#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

using namespace std;

struct Edge{
  int src, dst, label;
  Edge(int s, int d, int l) : src(s), dst(d), label(l) {}
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

bool rec(int node, bool visited[], string s[], int size, int depth, const Graph &g)
{
  cout << s[node] << endl;
  if(depth+1 == size){
    return true;
  }
  FOR(e, g[node]){
    if(visited[e->label])continue;
    visited[e->label] = true;
    if(rec(e->dst, visited, s, size, depth + 1, g)){
      return true;
    }
    visited[e->label] = false;
  }
  return false;
}

int calc(string s, string t, int l)
{
  int p = -1, cnt = 0;
  for(int i=0; i<l; ++i){
    if(s[i] == t[i])continue;
    ++cnt;
    p = i;
  }
  return cnt == 1 ? p : -1;
}

int main(void)
{
  for(int n, l; cin >> n >> l; ){
    string s[n];
    bool visited[l];
    Graph graph(n);
    fill(visited, visited + l, false);
    for(int i=0; i<n; ++i){
      cin >> s[i];
    }
    for(int i=0; i<n; ++i){
      for(int j=i+1; j<n; ++j){
	int label = calc(s[i], s[j], l);
	if(label < 0)continue;
	graph[i].push_back(Edge(i, j, label));
	graph[j].push_back(Edge(j, i, label));
      }
    }
    for(int i=0; i<n; ++i){
      if(rec(i, visited, s, n, 0, graph))break;
    }
  }
  return 0;
}
