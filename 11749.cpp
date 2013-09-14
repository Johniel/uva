#include <iostream>
#include <algorithm>
#include <set>
#include <utility>
#include <vector>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

using namespace std;

struct Edge{
  int src, dst, cost;  
};

bool operator < (const Edge &a, const Edge &b)
{
  return a.cost > b.cost;
}

class DisjointSet{
public: 
  vector<int> rank, p;
  DisjointSet(int size){
    rank.resize(size, 0);
    p.resize(size, 0);
    REP(i, size){
      p[i] = i;
      rank[i] = 0;
    }
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

#include <map>
int main(void)
{
  const int EDGE = 1000000, NODE = 500;
  int node, edge, cnt[NODE];  
  while(true){
    cin >> node >> edge;
    if(node == 0 && edge == 0)break;
    vector<Edge> E;    
    fill(cnt, cnt + NODE, 0);
    for(int i=0; i<edge; ++i){
      int src, dst, cost;
      cin >> src >> dst >> cost;
      --src; --dst;
      Edge e;
      e.src = src; e.dst = dst; e.cost = cost;
      E.push_back(e);
    }
    DisjointSet ds(node);
    sort(E.begin(), E.end());   
    for(int i=0; i<E.size(); ++i){
      if(E[i].cost != E[0].cost)break;
      ds.join(E[i].src, E[i].dst);
    }
    for(int i=0; i<node; ++i)
      ++cnt[ds.find(i)];
    cout << *max_element(cnt, cnt + node) << endl;    
  }
  return 0;
}
