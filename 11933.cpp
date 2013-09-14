#include <iostream>

using namespace std;

typedef long long int lli;

int main(void)
{
  int n, a, b;
  while( cin >> n && n ){
    int cnt = 0;
    a = b = 0;
    for(int i=0; i<60; ++i){
      if( (1LL << i) > n )break;
      if( (1LL << i) & n ){
        if( cnt++ % 2 == 0 )a |= 1LL << i;
        else b |= 1LL << i;
      }
    }
    cout << a << ' ' << b << endl;
  }
  return 0;
}
/*
110110101

010010001
100100100
*/
