//uva 11710
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin(); i!=(c).end(); ++i)
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
  int n, m;
  while(cin >> n >> m && (n | m)){
    map<string, int> no;
    string s, t;
    int cnt = 0;
    DisjointSet ds(n);
    int size[n];
    for(int i=0; i<n; ++i){
      cin >> s;
      no[s] = cnt++;
      ds.make(i);
      size[i] = 0;
    }
    for(int i=0; i<m; ++i){
      cin >> s >> t;
      ds.join(no[s], no[t]);
    }
    for(int i=0; i<n; ++i){
      ++size[ds.find(i)];
    }
    cout << *max_element(size, size + n) << endl;
  }
  return 0;
}
