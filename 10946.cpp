#include <iostream>
#include <algorithm>
#include <vector>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()

using namespace std;

const int N = 50 + 1;
char T[N][N];

bool isIn(int i, int j, int h, int w)
{
  return !(i < 0 || h <= i || j < 0 || w <= j);
}

void rec(int i, int j, int h, int w, int &cnt, char t)
{
  const int adj = 4;
  const int di[] = {0, 0, -1, 1}, dj[] = {-1, 1, 0, 0};
  ++cnt;
  T[i][j] = '.';
  for(int d=0; d<adj; ++d){
    int ni = i + di[d], nj = j + dj[d];
    if(isIn(ni, nj, h, w) && T[ni][nj] == t)
      rec(ni, nj, h, w, cnt, t);
  }
  return ;
}

bool cmp(pair<int, char> a, pair<int, char> b)
{
  if(a.first != b.first)return a.first > b.first;
  return a.second < b.second;
}

int main(void)
{
  for(int h, w, tc = 0; ; ){
    vector< pair<int, char> > S;
    cin >> h >> w;
    if(w + h == 0)break;
    for(int i=0; i<h; ++i){
      for(int j=0; j<w; ++j){
	cin >> T[i][j];
      }
    }
    for(int i=0; i<h; ++i){
      for(int j=0; j<w; ++j){
	if(T[i][j] != '.'){
	  char tmp = T[i][j];
	  int cnt = 0;
	  rec(i, j, h, w, cnt, tmp);
	  S.push_back(make_pair(cnt, tmp));
	}
      }
    }
    cout << "Problem " << ++tc << ":" << endl;
    sort(ALL(S), cmp);
    FOR(i, S){
      cout << i->second << ' ' << i->first << endl;
    }
  }
  return 0;
}
