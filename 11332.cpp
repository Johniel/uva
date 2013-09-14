#include <iostream>
#include <algorithm>

using namespace std;

int f(int n)
{
  int re  = 0;
  while(n >= 10){
    re += n % 10;
    n /= 10;
  }
  re += n;
  return (re < 10)? re : f(re);
}

int main(void)
{
  while(true){
    int n;
    cin >> n;
    if(n == 0)break;
    cout << f(n) << endl;
  }
  return 0;
}
