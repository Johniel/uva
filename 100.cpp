#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

int main(void)
{
  int n, m;
  while( cin >> n && cin >> m){
    int cnt,re = INT_MIN;
    cout << n << ' ';
    cout << m << ' ';
    if( n > m )swap(n,m);
    for(int i=n; i<=m; i++ ){
      cnt = 0;
      n = i;
      while( n != 1){
        cnt++;
        if( n%2 == 1)
          n = n * 3 + 1;
        else
          n = n / 2;
      }
      if( cnt <= (int)pow(2.0,32.0)-1 )
        re  = max(re, cnt);
    }
    cout << re+1 << endl;
  }
  return 0;
}
