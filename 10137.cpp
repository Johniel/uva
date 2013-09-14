#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main(void)
{
  const int N = 1000 + 1;
  long n;
  double v[N];
  while(cin >> n && n){
    double sum = 0;
    for(int i=0; i<n; ++i){
      cin >> v[i];
      sum += v[i];
    }
    double ave = sum / n, pos = 0, neg = 0;
    for(int i=0; i<n; ++i){
      double diff = (double) (long) ((v[i] - ave) * 100.0) / 100.0;
      if(diff < 0)neg += diff;
      else pos += diff;
    }    
    double mn = max(pos, -neg);
    //mn = -neg > pos ? -neg : pos;
    printf("$%.2lf\n", mn);    
  }
  return 0;
}
