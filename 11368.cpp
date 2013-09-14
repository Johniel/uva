#include <iostream>
#include <algorithm>
#include <map>
#include <cstdio>
#include <map>

#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

using namespace std;

inline
bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
  if(a.first != b.first)return a.first < b.first;
  return a.second > b.second;
}

int main(void)
{
  const int N = 20000 + 1;
  int tc;
  pair<int, int> p[N];
  int vis[N];
  scanf("%d", &tc);
  while(tc--){
    int n, r = 0;
    scanf("%d", &n);
    for(int i=0;i <n;++i){
      vis[i] = false;
      pair<int, int> tmp;
      scanf("%d%d", &tmp.first, &tmp.second);
      p[i] = tmp;
    }

    sort(p, p + n, cmp);
    
    r = 0;
    for(int i=0; i<n; ++i){
      if(vis[i])continue;
      vis[i] = true;
      ++r;
      int k = i;
      for(int j=i+1; j<n; ++j){
        if(vis[j])continue;
        if(p[k].first < p[j].first && p[k].second < p[j].second){
          vis[j] = true;
          k = j;
        }
      }
    }
    
    printf("%d\n", r);
  }
  return 0;
}
