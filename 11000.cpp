#include <iostream>

using namespace std;

typedef long long int lli;

int main(void)
{
  lli v[50];
  v[0] = v[1] = 1;
  for(int i=2; i<50; ++i)v[i] = v[i-1] + v[i-2]; 
  for(int n; cin >> n && 0 <= n;) 
    cout << v[n+1]-1 << ' ' << v[n+2]-1 << endl;
  return 0;
}
