#include <iostream>
#include <cstdio>

using namespace std;

typedef long long int lli;

inline
lli calcSum(int b, int e)
{
  lli x = e * (e - 1) / 2;
  lli y = b * (b - 1) / 2;
  return x - y;
}

int main(void)
{
  lli n;
  while(cin >> n){
    if(n == -1)break;
    
    while(true){
      lli r1 = 1, l1 = n;
      lli c1 = (r1 + l1) / 2;
    }
    
    for(int i=1; i<=n; ++i){
      for(int j=i; j<=n; ++j){
	lli tmp = calcSum(i, j+1);
	if(n < tmp)break;
	if(n == tmp){
	  cout << n << " = " << i << " + ... + " << j << endl;
	  i = j = 1 << 30;
	}
      }
    }
  }
  return 0;
}

