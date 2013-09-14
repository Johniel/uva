#include <cstdio>
#include <cmath>

using namespace std;

int main(void)
{
  double n, m;
  while(scanf("%lf%lf", &n, &m) != EOF){
    printf("%.0lf\n", pow(m, 1.0/n));
  }
  return 0;
}
