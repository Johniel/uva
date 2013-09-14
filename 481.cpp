#include <iostream>
#include <algorithm>

#define REP(i, n) for(int i=0; i<(int)n; i++)

using namespace std;

static const int INF = 1<<20;
static const int N = 190000;

int num[N];

void LIS(const int num[], const int size)
{

  int t[size];
  int ind[size];
  int len = INT_MIN;
  fill(t, t + size, INF);
  REP(i, size){
    int p = 0;
    while(p < size && t[p] <= num[i])p++;
    ind[i] = p;
    t[ ind[i] ] = num[i];
    len = max(len, ind[i]);
  }
  /*
  REP(i, size)cout << num[i] << ' ';cout << endl;
  REP(i, size)cout << t[i] << ' '; cout << endl;
  REP(i, size)cout << ind[i] << ' ';cout << endl;
  cout << len << endl;
  */
  cout << len << endl;
  cout << '-' << endl;
  int tmp = len;
  int result[len+1];
  REP(i, size)if(ind[size - 1 - i] == len)
    result[len--] = num[size - 1 - i];
  //  for (int i = size-1; i >= 0; --i)if (ind[i] == len) result[len--] = num[i];
  REP(i, tmp)
    cout << result[i] << endl;
  return ;
}

int main(void)
{
  int p = 0;
  while( scanf("%d", num+(p++) ) != -1);
  LIS(num, p-1);
  return 0;
}
