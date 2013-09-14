#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

static const int PRICE = 30000 + 1;
static const int COIN = 5;

typedef long long int lli;

lli table[COIN][PRICE];

inline void dp(void)
{
  int c[COIN] = {1, 5, 10, 25, 50};
  for(int i=0; i < PRICE; ++i)table[0][i] = 1;
  for(int i=0; i<COIN; ++i)table[i][0] = 1;
  for(int i=1; i<COIN; ++i){
    for(int j=1; j<PRICE; ++j){
      table[i][j] = table[i - 1][j];
      for(int k=1; (c[i] * k) <= j; ++k){
	table[i][j] += table[i-1][j - c[i] * k];
      }
    }
  }
  return ;
}

inline lli total(int w)
{
  return table[COIN - 1][w];
}

int main(void)
{
  int n;
  lli t;
  dp();
  while(cin >> n){
    t = total(n);
    cout << "There ";
    if(t != 1)cout << "are " << t << " ways to produce ";
    else cout << "is only 1 way to produce ";
    cout << n << " cents change." << endl;
  }
  return 0;
}

