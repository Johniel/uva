//n log n LIS
#include <iostream>
#include <algorithm>
#include <climits>

#define REP(i, n) for(int i=0; i<(int)n; i++)

using namespace std;

static const int INF = INT_MAX;
static const int N = 2000000;

int num[N];

int LIS(const int num[], const int size)
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
  int tmp = len;
  /*
  int result[len+1];
  REP(i, size)if(ind[size-1-i] == len)result[len--] = num[size-1-i];
  REP(i, tmp+1)printf("%d\n", result[i]);
  */
  return tmp+1;
}

int main(void)
{
  int tc = 0;
  while(true){
    int size = 0;
    while(true){
      cin >> num[size];
      if(num[size] < 0)break;
      ++size;
    }
    if(size == 0)break;
    if(tc)cout << endl;
    reverse(num, num + size);
    cout << "Test #" << ++tc << ":" << endl;
    cout << "  maximum possible interceptions: " << flush;
    cout << LIS(num, size) << endl;
  }
  return 0;
}
