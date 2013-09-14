#include <iostream>

using namespace std;

typedef long long int lli;

int Xn(int x, int &d)
{
  return (x == 1)? 1 : (x & 1)? Xn(3*x+1, ++d) : Xn(x/2, ++d);
}

int main(void)
{
  while(true){
    lli n, m;
    scanf("%llu%llu", &n, &m);
    if(n == 0 && m == 0)
      break;
    if(n > m)swap(n, m);
    lli r = 0, l = -1;
    for(lli i=n; i<=m; ++i){
      lli d = 1;
      for(lli t = i; ; ++d){
	//cout << t << endl;
	t = (t & 1)? 3 * t + 1 : t / 2;
	if(t == 1)break;
      }
      if(l < d){
	l = d;
	r = i;
      }
    }
    printf("Between %llu and %llu, %llu generates the longest sequence of %d values.\n", n, m, r, l);
  }
  return 0;
}
