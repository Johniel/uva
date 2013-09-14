#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

inline bool eq(double a, double b)
{
  return fabs(a - b) < 1e-11;
}

int main(void)
{
  const double exp = M_E;
  for(int n; cin >> n; ){
    if(n == 0)break;    
    double lnn = log(n);
    for(int l=0; ; ++l){
      double em = pow(exp, lnn - l);      
      if(0 < em && em < 2){
	printf("%d %.8lf\n", l, - em + 1);
	break;
      }
    }
  }
  return 0;
}
