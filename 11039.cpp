#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 500000;

struct Floor{
  int n, color;
  Floor(){}
  Floor(int _n, int _c) : n(_n), color(_c) {}
};

bool operator < (Floor a, Floor b)
{
  return a.n < b.n;
}

int cntHeight(Floor f[], int n, int color)
{
  int cnt = 0;
  for(int i=0; i<n; ++i){
    if(f[i].color == color){
      ++cnt;
      color = color ^ 1;
    }
  }
  return cnt;
}

int main(void)
{
  int tc;
  Floor f[N];
  for(cin >> tc; tc--; ){
    int n;
    cin >> n;
    for(int i=0; i<n; ++i){
      int m;
      cin >> m;
      f[i] = Floor(abs(m), m < 0);
    }
    sort(f, f + n);
    cout << max(cntHeight(f, n, false), cntHeight(f, n, true)) << endl;
  }
  return 0;
}
