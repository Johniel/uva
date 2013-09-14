#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main(void)
{
  int n;
  while(cin >> n){
    int cnt = 0;
    double m = 1;
    for(int i=0; i<n; ++i){
      m /= 2.0;
      while(1 > m){
        ++cnt;
        m *= 10.0;
      }
    }
    printf("2^-%d = %.3lfe-%d\n", n, m, cnt);
  }
  return 0;
}
