#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
  double h, u, d, f;
  while(true){
    cin >> h >> u >> d >> f;
    if(h == 0)break;
    int day = 0;
    double sum = 0;
    double m = u * f / 100.;
    while(true){
      ++day;
      sum += u;
      //cout << sum << endl;
      if(h < sum){
	cout << "success on day " << day << endl;
	break;
      }
      u = max(u - m, 0.);
      sum -= d;
      //cout << sum << endl;
      if(sum < 0){
	cout << "failure on day " << day << endl;
	break;
      }
    }
  }
  return 0;
}
