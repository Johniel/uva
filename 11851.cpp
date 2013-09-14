#include <iostream>
#include <algorithm>
#include <cstdio>
#include <set>
#include <map>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()

#define key first
#define val second

using namespace std;

typedef long long int lli;

const int V = 24 + 1;

map<lli, lli>::iterator itr, itr0, itr1;
set< pair<lli, lli> > vis[V];
pair<lli, lli> tmp;
lli diff, calc;

void rec(lli v[], lli a, lli b, int depth, const int &size, map<lli, lli> &m)
{
  tmp = make_pair(max(a, b), min(a, b));
  if(vis[depth].count(tmp))return ;
  vis[depth].insert(tmp);
  if(size == depth){
    calc = a + b;
    diff = calc - min(a, b);
    itr = m.find(diff);
    if(itr == m.end())m.insert( make_pair(diff, calc) );
    else itr->val = max(itr->val, calc);
  }
  else{
    rec(v, a + v[depth], b, depth + 1, size, m);
    rec(v, a, b + v[depth], depth + 1, size, m);
    rec(v, a, b, depth + 1, size, m);
  }
  return ;
}

int main(void)
{
  lli v[V], sum, mx;
  int i, n;
  map<lli, lli> p, q;
  while(scanf("%d", &n) && n){
    sum = 0;
    for(i = 0; i<n; ++i){
      scanf("%Ld", v + i);
      sum += v[i];
    }

    p.clear();
    fill(vis, vis + n, set< pair<lli, lli> >());
    rec(v, 0, 0, 0, n/2, p);

    q.clear();
    fill(vis, vis + n, set< pair<lli, lli> >());
    rec(v+n/2, 0, 0, 0, n-n/2, q);

    continue;

    mx = -1;
    for(itr0 = p.begin(); itr0 != p.end(); ++itr0){
      itr1 = q.find(itr0->key);
      if(itr1 == q.end())continue;
      mx = max(mx, itr0->val + itr1->val);
    }
    printf("%Ld\n", sum - mx);
  }
  return 0;
}
