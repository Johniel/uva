#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int main(void)
{
  double s, r;
  for(; cin >> r >> s;){
    printf("%.3lf\n", s * r * r * sin(M_PI / s) * cos(M_PI / s));
  }
  return 0; 
}
