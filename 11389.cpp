#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
  int n, d, r;
  while(cin >> n >> d >> r && n){
    int m[n], a[n];
    for(int i=0; i<n; ++i){
      cin >> m[i];
    }
    for(int i=0; i<n; ++i){
      cin >> a[i];
    }
    sort(m, m + n);
    sort(a, a + n);
    reverse(a, a + n);
    int sum = 0;
    for(int i=0; i<n; ++i){
      sum += max(a[i] + m[i] - d, 0) * r;
    }
    cout << sum << endl;
  }
  return 0;
}
 
