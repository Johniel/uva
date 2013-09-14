#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int BASE = 40 * 1000 + 1;
const int F = BASE * 2;
const int N = 40 + 1;

string test(int n)
{
  string s;
  for(int i=0; n >= (1 << i); ++i){
    if(n & (1 << i))s += '+';
    else s += '-';
  }
  return s;
}

void dp(int num[], int size, int f, int lim)
{  
  static bool t[N][F];
  static long long int bit[N][F];
  fill(&t[0][0], &t[size][lim + BASE], false);
  fill(&bit[0][0], &bit[size][lim + BASE], 0ll);
  t[0][0 + BASE] = true;  
  //reverse(num, num + size);
  for(int i=0; i<size; ++i){
    for(int j=0; j<F; ++j){
      if(!t[i][j])continue;      
      //cout << i << " : " << j-BASE << "  " << test(bit[i][j]) << endl;
      int n;
      n = j + num[i];
      if(0 <= n && n < F){
	t[i + 1][n] = true;
	bit[i + 1][n] |= bit[i][j] | (1ll << i);
      }
      n = j - num[i];
      if(0 <= n && n < F){
	t[i + 1][n] = true;
	bit[i + 1][n] |= bit[i][j];
      }
    }
  }
  if(t[size][+f + BASE] && t[size][-f + BASE]){
    for(int i=0; i<size; ++i){
      long long int a = bit[size][+f + BASE] & (1ll << i);
      long long int b = bit[size][-f + BASE] & (1ll << i);
      if(a == b){
	//cout << '?';
	printf("?");
      }
      else{
	//cout << (a ? '+' : '-') ;
	printf("%c", (a ? '+' : '-'));
      }
    }
    //cout << endl;
    puts("");
  }
  else{
    //cout << '*' << endl;
    puts("*");
  }
  return ;
}

int main(void)
{
  int num[1000 + 1];
  while(true){
    int n, f;
    int lim = 0;
    //cin >> n >> f;
    scanf("%d%d",  &n, &f);
    if(n == 0 && f == 0){
      break;
    }
    for(int i=0; i<n; ++i){
      //cin >> num[i];
      scanf("%d", num + i);
      lim += num[i];
    }
    dp(num, n, f, lim);
  }
  return 0;
}
