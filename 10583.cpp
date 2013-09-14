//uva 11710
#include <iostream>
#include <vector>
#include <map>
#include <stack>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin(); i!=(c).end(); ++i)
#define ALL(c) (c).begin(),(c).end()

using namespace std;

static const int INF = (400 + 1) * (79800 + 1);
static const int FAIL = -1;

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

int main(void)
{
  int tc = 0;
  int n, m;
  while(true){
    cin >> n >> m;
    if(n == 0 && m == 0)break;
    DisjointSet ds(n);
    for(int i=0; i<m; ++i){
      int s, t;
      cin >> s >> t;
      ds.join(s-1, t-1);
    }
    int cnt = 0;
    for(int i=0; i<n; ++i){
      if(ds.p[i] == i)++cnt;
    }
    cout << "Case " << ++tc << ": " << cnt << endl;
  }
  return 0;
}
