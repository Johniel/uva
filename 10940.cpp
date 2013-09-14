#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main(void)
{
  int n;
  while(cin >> n && n){
    int m = 1;
    while(m < n){
      m = m << 1;
    }
    if(n == m){
      cout << n << endl;
    }
    else{
      cout << m - (m - n) * 2 << endl;
    }
  }
  return 0;
}
