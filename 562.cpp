#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
  int tc;
  cin >> tc;
  while(tc--){
    int n, a = 0, b = 0;
    cin >> n;
    int num[n];
    for(int i=0; i<n; ++i)cin >> num[i];
    sort(num, num + n);
    a = num[0];
    for(int i=1; i<n; ++i){
      if(a < b)a += num[i];
      else b += num[i];
    }
    cout << max(a, b) - min(a, b) << endl;
  }
  return 0;
}
