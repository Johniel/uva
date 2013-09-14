/*
  http://www.algorithmist.com/index.php/UVa_10790
*/

#include <iostream>

using namespace std;

int main(void)
{
  int n, m;
  int tc = 0;
  while( cin >> n >> m && (n | m) ){
    long long int a = n;
    long long int b = m;
    unsigned long long int r = 1;
    r *= a;
    r *= b;
    r *= a - 1;
    r *= b - 1;
    r /= 4;
    cout << "Case " << ++tc << ": " << r << endl;
  }
  return 0;
}
