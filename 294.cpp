#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

inline
int div(int n)
{  
  int cnt = 0;
  int m = sqrt(n);
  for(int i=1; i<=m; ++i){
    if(n % i == 0)cnt += 2;
  }  
  if(m * m == n)--cnt;
  return cnt;
}

int main(void)
{
  int tc;
  cin >> tc;
  while(tc--){
    int a, b;
    int mx = 0, v;
    cin >> a >> b;
    for(int i=a; i<=b; ++i){
      int tmp = div(i);
      if(tmp > mx){
        mx = tmp;
        v = i;
      }
    }
    cout << "Between " << a << " and " << b << ", " << v 
         << " has a maximum of " << mx << " divisors." << endl;
  }
  return 0;
}
