#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
  int tc;
  cin >> tc;
  while(tc--){
    long long n;
    cin >> n;
    n *= 567;  //cout << n << endl;
    n /= 9;    //cout << n << endl;
    n += 7492; //cout << n << endl;
    n *= 235;  //cout << n << endl;
    n /= 47;   //cout << n << endl;
    n -= 498;  //cout << n << endl;
    n %= 100;
    n /= 10;
    if(n < 0)n *= -1;
    cout << n << endl;

  }
  return 0;
}
