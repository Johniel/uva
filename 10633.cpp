#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef unsigned long long int ulli;
typedef long long int lli;

int main(void)
{
  for(ulli n; cin >> n && n; ){
    ulli m = 10ll * n / 9ll;
    vector<ulli> v;
    for(lli i=-10; i<=10; ++i){
      ulli o = m + i;
      if(o - o/10ll == n){
        v.push_back(o);
      }
    }
    sort(v.begin(), v.end());
    for(int i=0; i<v.size(); ++i){
      if(i)cout << ' ';
      cout << v[i];
    }
    cout << endl;
  }
  return 0;
}
