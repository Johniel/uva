//n log n LIS
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <climits>

#define REP(i, n) for(int i=0; i<(int)n; i++)

using namespace std;

static const int INF = INT_MAX;
static const int N = 2000000;

int num[N];

void LIS(int size)
{
  int t[size];
  int ind[size];
  int len = INT_MIN;
  fill(t, t + size, INF);
  REP(i, size){
    ind[i] = distance(t, lower_bound(t, t + size, num[i]));
    t[ ind[i] ] = num[i];
  }
  len = *max_element(ind, ind + size);
  /*
  REP(i, size)cout << num[i] << ' ';cout << endl;
  REP(i, size)cout << t[i] << ' '; cout << endl;
  REP(i, size)cout << ind[i] << ' ';cout << endl;
  cout << len << endl;
  */
  cout << len + 1 << endl;return;
  int tmp = len;
  int result[len+1];
  REP(i, size)if(ind[size-1-i] == len)result[len--] = num[size-1-i];
  REP(i, tmp+1)printf("%d\n", result[i]);
  return ;
}

int main(void)
{
  int n;
  cin >> n;
  int m[n];
  for(int i=0; i<n; ++i){
    cin >> m[i];
  }
  while(!cin.eof()){
    for(int i=0; i<n; ++i){
      if(!(cin >> num[m[i]-1]))return 0;
    }    
    LIS(n);
  }
  return 0;
}
