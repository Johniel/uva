#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
  int tc, cnt = 0;
  for(cin >> tc; tc--; ){
    double d, v, u;
    cin >> d >> v >> u;
    cout << "Case " << ++cnt << ": ";
    if(u == 0 || v == 0 || u <= v){
      puts("can't determine");
      continue;
    }
    double t1 = d / u;
    double t2 = d / sqrt(u * u - v * v);
    printf("%.3lf\n", fabs(t1 - t2));
  }
  return 0;
}
