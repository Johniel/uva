#include <iostream>
#include <algorithm>
#include <set>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()

using namespace std;

const int H = 30 * 2, W = 30 + 1;
const int N = 50 * H * 2 + 50;

int g[H][W];
bool t[H][W][N];

#include <cmath>

int dp(const int w)
{
  const int base = N / 2, h = w * 2 - 1;
  fill(&t[0][0][0], &t[H-1][W-1][N], false);
  t[0][0][+g[0][0] + base] = true;
  t[0][0][-g[0][0] + base] = true;
  int l = 1;
  for(int i=0; i<2*w-1-1; ++i){
    if(i<w-1){
      for(int j=0; j<l; ++j){
	for(int n=0; n<N; ++n){
	  if(t[i][j][n]){
	    //cout << "1st " << i << ' ' << j << ' ' << n - base << endl;
	    t[i+1][j+1][n + g[i+1][j+1]] = true;
	    t[i+1][j+1][n - g[i+1][j+1]] = true;
	    t[i+1][j][n + g[i+1][j]] = true;
	    t[i+1][j][n - g[i+1][j]] = true;
	  }
	}
      }
      ++l;
    }
    else{
      for(int j=0; j<l; ++j){
	for(int n=0; n<N; ++n){
	  if(t[i][j][n]){
	    //cout << "2nd " << i << ' ' << j << ' ' << n - base << endl;
	    if(j){
	      t[i+1][j-1][n + g[i+1][j-1]] = true;
	      t[i+1][j-1][n - g[i+1][j-1]] = true;
	    }
	    t[i+1][j][n + g[i+1][j]] = true;
	    t[i+1][j][n - g[i+1][j]] = true;	    
	  }	  
	}
      }
      --l;
    }
  }
  int re = 1 << 20, tmp = 1 << 20;
  for(int i=0; i<N; ++i){
    if(t[w*2-1-1][0][i] && tmp >= abs(i-base)){
      re = i - base;
      tmp = abs(i - base);
    }
  }
  return re;
}

int main(void)
{
  for(int w; cin >> w; ){
    if(w == 0)break;    
    int l = 1;
    for(int i=0; i<w*2-1; ++i){
      if(i<w-1){
	for(int j=0; j<l; ++j){
	  cin >> g[i][j];
	}
	++l;
      }
      else{
	for(int j=0; j<l; ++j){
	  cin >> g[i][j];
	}
	--l;
      }    
    }
    cout << dp(w) << endl;
  }
  return 0;
}
