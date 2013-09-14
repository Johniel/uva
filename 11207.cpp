#include <iostream>
#include <algorithm>

using namespace std;

double  calc(double  h, double  w)
{
  double  mx = -1;
  {
    double  a = h / 4;
    double  b = w;
    mx = max(mx, min(a, b));
    //mx = max(mx, min(a, b) * min(a, b));
  }
  {
    double  a = h / 2;
    double  b = w / 2;
    mx = max(mx, min(a, b));
    //mx = max(mx, min(a, b) * min(a, b));
  }
  return mx;
}

int main(void)
{
  int n;
  while(cin >> n && n){
    double mx = -1;
    int idx;
    for(int i=0; i<n; ++i){
      double h, w;
      cin >> h >> w;
      double tmp = -1;
      tmp = max(tmp, calc(max(h, w), min(h, w)));
      tmp = max(tmp, calc(min(h, w), max(h, w)));
      if(mx < tmp){
        mx = tmp;
        idx = i;
      }
    }
    cout << idx+1 << endl;
  }
  return 0;
}
