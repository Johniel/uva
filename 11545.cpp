#include <iostream>
#include <algorithm>
#include <queue>

#define REP(i, n) for(int i=0; i<(int)n; ++i)

using namespace std;

static const int LEN = 1000;
static const int LIM = 17;
static const int INF = 1 << 30; 
static const int TIME = 24;

static char M[LEN];

inline bool isNight(int t)
{
  return t <= 6 || 18 <= t; 
}

inline
int dp(int src, int dst)
{ 
  static int table[LEN][LIM][TIME]; 
  fill(&table[0][0][0], &table[LEN-1][LIM-1][TIME], INF); 
  table[src][0][6] = 0;
  for(int pos = src; pos < dst; ++pos){
    REP(lim, 17)REP(time, TIME){
      if((table[pos][lim][time] == INF))continue;
      for(int rest = 0; rest < 24; rest += 8){	
	for(int dist = 1; dist < 17 && pos + dist <= dst; ++dist){
	  int t = (time + dist + rest) % TIME;
	  if(isNight(t) && M[pos + dist] == '*')break;
	  int l = (rest)? dist : lim + dist;
	  if(16 < l)break;
	  table[pos + dist][l][t] = min(table[pos + dist][l][t], 
					table[pos][lim][time] + dist + rest);
	}
	if(M[pos] == '*')break;
      }
    }      
  }
  //#define TEST
#ifdef TEST
  for(int i = src; i <= dst; ++i){    
    printf("%d %c\n", i, M[i]);
    printf("   ");
    for(int k = 0; k < 24; ++k)
      printf("%3d", k);
    printf("\n");
    for(int j = 0; j < 17; ++j){
      printf("%3d", j);
      for(int k = 0; k < 24; ++k){
	if(table[i][j][k] == INF)cout << "  _";
	else printf("%3d", table[i][j][k]);
      }
      printf("\n");
    }
  }  
#endif
  int m = INF;
  for(int i = 1; i < 17; ++i){    
    for(int j=0; j < 24; ++j)
      m = min(m, table[dst][i][j]);
  }
  return (m == INF)? -1 : m;
}

int main(void)
{
  int tc, cnt = 0;
  cin >> tc;
  cin.ignore();
  while(tc--){
    int dst, src;
    for(int i=0; ; ++i){
      char c;
      cin.get(c);
      if(c == '\n')break;
      else if(c == 'S')src = i;
      else if(c == 'D')dst = i;
      M[i] = c;
    }
    cout << "Case #" << ++cnt << ": " 
	 << dp(min(dst, src), max(dst, src)) << endl;
  }
  return 0;
}
