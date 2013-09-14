#include <iostream>
#include <algorithm>
#include <set>

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()

using namespace std;

#include <cstdio>

int main(void)
{
  char name[51][51], c;
  int tc = 0, n, h, w;
  pair<int, int> p[26];
  while(true){
    scanf("%d", &n);
    if(n == 0)break;
    fill(&name[0][0], &name[51-1][51], 0);
    for(int i=0; i<n; ++i){
      scanf(" %c %d %d", &c, &w, &h);
      name[w][h] = c;
      //p[i] = make_pair(w, h);
      p[i].first = w; p[i].second = h;
    }
    set<string> ans;
    for(int i=0; i<n; ++i){
      for(int j=0; j<n; ++j){
	if(i == j)continue;
	if(!name[p[i].first][p[j].second])continue;
	if(!name[p[j].first][p[i].second])continue;
	if(p[i].second > p[j].second && p[i].first  < p[j].first){
	  string s;
	  s += name[p[i].first][p[i].second];
	  s += name[p[j].first][p[i].second];
	  s += name[p[j].first][p[j].second];
	  s += name[p[i].first][p[j].second];
	  ans.insert(s);
	}
      }
    }
    printf("Point set %d:", ++tc);
    if(ans.size()){
      puts("");
      int cnt = 0;
      FOR(i, ans){
	if(cnt && cnt % 10 == 0)cout << endl;
	++cnt;
	printf(" %s", i->c_str());
      }
      puts("");
    }
    else{
      puts(" No rectangles");
    }
  }
  return 0;
}

