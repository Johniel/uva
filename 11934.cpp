#include <iostream>

#define f(n) (a * n * n + b * n + c)

using namespace std;

typedef long long int lli;

int main(void)
{
  lli a, b, c, d, L;
  while( cin >> a >> b >> c >> d >> L && (a | b | c | d | L) ){
    int cnt = 0;
    for(lli i=0; i<=L; ++i){
      if( f(i) % d == 0 )++cnt;
    }
    cout << cnt << endl;
  }
  return 0;
}
