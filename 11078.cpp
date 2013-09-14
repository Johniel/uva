#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
  int tc;
  cin >> tc;
  while(tc--){
    int n;
    cin >> n;
    int m[n];
    for(int i=0; i<n; ++i){
      cin >> m[i];      
    }
    int mx = m[0];
    int r = -(1 << 23);
    for(int i=1; i<n; ++i){
      r = max(r, mx - m[i]);
      mx = max(mx, m[i]);
    }
    cout << r << endl;
  }
  return 0;
}

