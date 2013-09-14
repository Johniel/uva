#include <iostream>
#include <algorithm>
#include <set>
#include <queue>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()

using namespace std;

void solve(int team[], int table[], int n, int m)
{
  set<int> s[n];
  queue<int> q[m];
  pair<int, int> t[m];
  REP(i, m){
    t[i] = make_pair(table[i], i + 1);
  }
  sort(t, t + m);
  reverse(t, t + m);
  REP(i, m){
    //cout << t[i].second << ' ' << t[i].first << endl;
    REP(j, t[i].first){
      q[i].push(t[i].second);
    }
  }
  REP(i, m){
    REP(j, n && q[i].size()){
      if(s[j].size() == team[j])continue;
      s[j].insert(q[i].front());
      q[i].pop();
    }
  }
  bool flg = true;
  REP(i, n){
    if(team[i] != s[i].size()){
      flg = false;
      break;
    }
  }
  if(!flg)cout << 0 << endl;
  else{
    cout << 1 << endl;
    REP(i, n){
      FOR(j, s[i]){
	if(j != s[i].begin())cout << ' ';
	cout << *j ;
      }
      cout << endl;
    }
  }
  return ;
}

int main(void)
{
  while(true){
    int n, m;
    cin >> n >> m;
    if(n == 0 && m == 0)break;
    int team[n], table[m];
    REP(i, n)cin >> team[i];
    REP(i, m)cin >> table[i];
    solve(team, table, n, m);
  }
  return 0;
}
