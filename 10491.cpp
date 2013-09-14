#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int main(void)
{
  for(int car, cow, show; cin >> cow >> car >> show; ){
    double p = 0, T = car + cow;
    double ts = T - 1 - show;
    p += (double)(car / T) * ((double)(car - 1) / ts);
    p += (double)(cow / T) * ((double)(  car  ) / ts);
    printf("%.5lf\n", p);
  }
  return 0;
}
