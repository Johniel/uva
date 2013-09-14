#include <iostream>
#include <algorithm>
#include <cstdio>

#define REP(i, n) for(int i=0; i<(int)n; ++i)

using namespace std;

static const int H = 40, W = 90, adj = 4;
static const int di[] = {0, 0, -1, 1};
static const int dj[] = {-1, 1, 0, 0};

char G[H][W];
int len[H];
bool visited[H][W];

inline
bool isIn(int i, int j, int h)
{
  return !(i < 0 || h <= i || j < 0 || len[i] <= j);
}

void floodFill(int pi, int pj, int h, char c)
{
  visited[pi][pj] = true;
  G[pi][pj] = c;
  REP(d, adj){
    int ni = pi + di[d], nj = pj + dj[d];
    if(isIn(ni, nj, h) && !visited[ni][nj] && G[ni][nj] == ' ')
      floodFill(ni, nj, h, c);
  }
  return ;
}

int main(void)
{
  while(!cin.eof()){
    int cnt = 0;
    string s;
    fill(len, len + H, 0);
    fill(&visited[0][0], &visited[H-1][W], false);
    for(;; ++cnt){
      getline(cin, s);
      s += '\0';
      REP(i, s.size())G[cnt][i] = s[i];
      len[cnt] = strlen(G[cnt]);
      if(count(s.begin(), s.end(), '_') == (int)s.size() - 1)break; 
      if(len && count(G[cnt], G[cnt] + len[cnt], '-') == len[cnt])break;	
    }
    REP(i, cnt-1){
      REP(j, len[i]){
	if(!visited[i][j] && G[i][j] != ' ' && G[i][j] != 'X'){
	  floodFill(i, j, cnt+1, G[i][j]);
	}
      }
    }
    REP(i, cnt+1){
      int s = 79 - len[i];
      printf("%s", G[i]);
      REP(j, s)printf(" ");
      printf("\n");
    }
  }
  return 0;
}
