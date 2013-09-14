#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()

using namespace std;

int order[100 + 1][100 + 1];

void calc(int g, int p, vector<int> v)
{
  set<int> win;
  int sum[p];
  pair<int, int> rank[p];
  fill(sum, sum + p, 0);
  for(int i=0; i<g; ++i){
    for(int j=0; j<p && j<v.size(); ++j){
      //cout << order[i][j] << " add " << v[j] << endl;
      sum[order[i][j]] += v[j];
    }
  }
  for(int i=0; i<p; ++i){
    rank[i].first = sum[i];
    rank[i].second = i;
  }
  sort(rank, rank + p);
  reverse(rank, rank + p);
  /*
  for(int i=0; i<p; ++i){
    cout << rank[i].first << " : " << rank[i].second << endl;
  }
  */
  for(int i=0; i<p && rank[i].first == rank[0].first; ++i){
    win.insert(rank[i].second);
  }
  FOR(i, win){
    if(i != win.begin())cout << ' ';
    cout << *i + 1;
  }
  cout << endl;
  return ;
}

int main(void)
{
  while(true){
    int g, p;
    cin >> g >> p;
    if(g == 0 && p == 0)break;
    for(int i=0; i<g; ++i){
      for(int j=0; j<p; ++j){
	int r;
	cin >> r;
	order[i][r-1] = j;
      }
    }
    int score;
    cin >> score;
    for(int i=0; i<score; ++i){
      int n;
      cin >> n;
      vector<int> v;
      for(int j=0; j<n; ++j){
	int m;
	cin >> m;
	//cout << m << ' ';
	v.push_back(m);
      }
      //cout << endl;
      calc(g, p, v);
    }
  }
  return 0;
}
