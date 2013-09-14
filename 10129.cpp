//uva 10129
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

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

class DisjointSet{
public: 
  vector<int> rank, p;
  DisjointSet(int size){
    rank.resize(size, 0);
    p.resize(size, 0);
  }
  void make(int a){
    rank[a] = 0;
    p[a] = a;
  }
  void join(int a, int b){
    link(find(a), find(b));
  }
  int find(int a){
    return (a == p[a])? a : p[a] = find(p[a]);
  }
  bool isSameSet(int a, int b){
    return find(a) == find(b);
  }
  void link (int a, int b){
    if(rank[a] > rank[b])
      p[b] = a;
    else{
      p[a] = b;
      if(rank[a] == rank[b])
	rank[b]++;
    }
  }
};

const int size = 'z' + 1, income = 0, outgo = 1;

bool isConnected(const Graph &G)
{
  static bool visited[size];
  int src;  
  for(int i=0; i<size; ++i){
    visited[i] = !G[i].size();
    if(G[i].size())src = i;
  }
  stack<int> S;
  visited[src] = true;
  for(S.push(src); !S.empty(); ){
    int node = S.top();
    S.pop();    
    FOR(e, G[node]){
      if(visited[e->dst])continue;
      S.push(e->dst);
      visited[e->dst] = true;
    }
  }
  return count(visited, visited + size, true) == size;
}

int main(void)
{
  int tc, degree[size][2];
  for(cin >> tc; tc--; ){
    int n;
    Graph G(size);
    fill(&degree[0][0], &degree[size-1][2], 0);
    cin >> n;    
    for(int i=0; i<n; ++i){
      string s;
      cin >> s;
      int h = s[0], t = s[(int)s.size() - 1];      
      ++degree[h][income];
      ++degree[t][outgo];
      G[h].push_back(Edge(h, t));
      G[t].push_back(Edge(t, h));
    }    
    int src = 0, dst = 0, odd = 0;
    for(int i=0; i<size; ++i){
      if(degree[i][income] == 0 && degree[i][outgo] == 0)continue;
      if(degree[i][income] == degree[i][outgo])++odd;
      else if(degree[i][income] - degree[i][outgo] ==  1)++src;
      else if(degree[i][income] - degree[i][outgo] == -1)++dst;
      else src += 2;
    }

    bool flg = isConnected(G);

    //cout << src << ' ' << dst << ' ' << odd << endl;

    if(n == 1 || (flg && src == dst & src < 2)){
      cout << "Ordering is possible." << endl;
    }
    else cout << "The door cannot be opened." << endl;
  }
  return 0;
}
