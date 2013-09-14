#include <iostream>
#include <math.h>

using namespace std;

int main(void)
{
  for(int n; cin >> n && n; ){
    int m = (n - 1960) / 10;
    double w = 4 * pow(2, m);
    double sum = 0;
    for(double i=1; ; ++i){
      sum += log2(i);
      if(w <= sum){
        cout << i-1 << endl;
        break;
      }
    }
  }
  return 0;
}
