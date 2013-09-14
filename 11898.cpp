#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

using namespace std;

const int Ai = 10000 + 1;
vector<int> v[Ai];
int a, b;

inline
int next(int i)
{
  for(; i < Ai; ++i){
    FOR(j, v[i]){
      if(a <= *j && *j <= b)return i;
    }
  }
  return -1;
}

int main(void)
{
  int tc, m, c, r, i, j, q;
  scanf("%d", &tc);
  while(tc--){
    scanf("%d", &m);
    for(i=0; i<m; ++i){
      scanf("%d", &r);
      v[r].push_back(i);
    }
    scanf("%d", &q);
    while(q--){
      scanf("%d%d", &a, &b);     

      if(10001 <= b - a){
	puts("0");
	continue;
      }

      --a; --b;      

      c = 1 << 22;

      int l, r = 0, cnt;
      while(true){
	l = next(r);
	if(l == -1)break;
	cnt = 0;
	FOR(i, v[l]){
	  if(a <= *i && *i <= b){
	    ++cnt;
	    if(cnt == 2)break;
	  }
	}
	if(1 < cnt){
	  c = 0;
	  break;
	}
	if(l + 1 == Ai)break;
	r = next(l + 1);
	if(r == -1)break;
	c = min(c, r - l);	
      }
      printf("%d\n", c);      
    }
    fill(v, v + Ai, vector<int>());
  }
  return 0;
}
