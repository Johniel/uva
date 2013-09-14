#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <sstream>
#include <utility>
#include <cstdio>
#include <cmath>
#include <climits>

#define REP(i, n) for(int i=0; i<n; ++i)

#define fr first 
#define sc second

using namespace std;

const int H = 64, W = 64;
bool visited[H][W];

const int TYPE_I = 0, TYPE_L = 1;
int type[H][W], sum;

const int U = 2, D = 3, R = 1, L = 0, EX = -1;

int di[] = {0, 0, -1, 1};
int dj[] = {-1, 1, 0, 0};

inline
bool is_in(int i, int j, int h, int w)
{
  return !(i < 0 || h <= i || j < 0 || w <= j);
}

#define NEXT(d)\
ni = i + di[d];\
nj = j + dj[d];\
if( !visited[ni][nj] && is_in(ni, nj, h, w))rec(ni, nj, h, w, d);\

inline
void rec(int i, int j, int h, int w, int p)
{
  if(i+1 == h && j+1 == w){
    ++sum;
    return ;
  }  
  visited[i][j] = true;
  int ni, nj;
  if(p == EX){
    NEXT(D);
    NEXT(R);
  }
  else{
    if(type[i][j] == TYPE_I){
      NEXT(p);
    }
    if(type[i][j] == TYPE_L){
      if(p == R || p == L){
	NEXT(U);
	NEXT(D);
      }
      else{
	NEXT(R);
	NEXT(L);
      }
    }
  }
  visited[i][j] = false;
  return ;
}

char f[4 * 64 + 1][4 * 64 + 1];
int tc, h, w, pi, pj;
int lh, lw;
int main(void)
{
  scanf("%d", &tc);
  while(tc--){
    scanf("%d %d\n", &h, &w);
    //int lh = 4 * h + 1; int lw = 4 * w + 1;
    lh = 4 * h + 1; lw = 4 * w + 1;
    REP(i, lh){
      REP(j, lw){	
	scanf("%c", &f[i][j]);
      }
      scanf("\n");
    }
    REP(i, h){
      REP(j, w){
	visited[i][j] = false;
	//int pi = i * 4 + 2; int pj = j * 4 + 2;
	pi = i * 4 + 2; pj = j * 4 + 2;
	type[i][j] = EX;
	//if(f[pi][pj] == ' '){type[i][j] = EX;}else 
	if(f[pi-1][pj] == f[pi+1][pj] || 
	   f[pi][pj-1] == f[pi][pj+1]){
	  if(f[pi][pj] != ' ')type[i][j] = TYPE_I;
	  //type[i][j] = TYPE_I;
	}
	else{
	  type[i][j] = TYPE_L;
	}
      }
    }
    if(type[h-1][w-1] == EX || type[0][0] == EX){
      puts("Number of solutions: 0");
      continue;
    }
    if(h == 1 && w == 1){
      puts("Number of solutions: 2");
      continue;
    }
    sum = 0;
    rec(0, 0, h, w, EX);
    printf("Number of solutions: %d\n", sum);
  }
  return 0;
}
