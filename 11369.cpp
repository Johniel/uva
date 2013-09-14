#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
  int tc, num[20000];
  for(cin >> tc; tc--; ){
    int n;
    cin >> n;
    for(int i=0; i<n; ++i){
      cin >> num[i];
    }
    int sum = 0;
    sort(num, num + n);
    reverse(num, num + n);
    for(int i=2; i<n; i+=3){
      sum += num[i];
    }
    /*
    for(int i=0; i<n; i+=3){
      sum += min(min(num[i + 1], num[i + 2]), num[i]);
    }
    */
    cout << sum << endl;
  }
  return 0;
}
