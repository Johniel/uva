#include <iostream>
#include <vector>
#include <algorithm>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()

using namespace std;

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

int main(void)
{
  int tc;
  cin >> tc;
  while(tc--){
    int node, edge;
    cin >> node >> edge;
    bool used[node];
    int v[node], sum[node];
    DisjointSet ds(node);
    fill(used, used + node, false);
    REP(i, node){
      cin >> v[i];
      ds.make(i);
    }
    REP(i, edge){
      int src, dst;
      cin >> src >> dst;
      ds.join(src, dst);
    }
    REP(i, node){
      int r = ds.find(i);
      if(!used[r]){
	used[r] = true;
	sum[r] = v[i];
      }
      else
	sum[r] += v[i];
    }
    bool flg = true;
    REP(i, node && flg){
      if(used[i])
	flg = (sum[i] == 0);
    }
    if(flg)cout << "POSSIBLE" << endl;
    else cout << "IMPOSSIBLE" << endl;
  }
  return 0;
}
