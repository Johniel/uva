#include <iostream>
#include <algorithm>

using namespace std;

const int inf = 1 << 22;
const int N = 50 + 2 + 1;
int num[N];
int t[N][N];
int n, m;

int rec(int i, int j)
{
  if(i + 1 == j)return 0;
  if(t[i][j] != inf)return t[i][j];
  int mn = inf;
  for(int k=i+1; k<j; ++k){
    mn = min(mn, rec(i, k) + rec(k, j) + num[j] - num[i]);
  }
  return t[i][j] = mn;
}

int main(void)
{
  while(cin >> n >> m){
    for(int i=0; i<m; ++i){
      cin >> num[i];
    }
    num[m++] = 0;
    num[m++] = n;
    sort(num, num + m);
    fill(&t[0][0], &t[N-1][N], inf);
    for(int i=0; i+1<m; ++i){
      t[i][i + 1] = 0;
    }
    cout << "The minimum cutting is " << rec(0, m-1) << "." << endl;
  }
  return 0;
}
