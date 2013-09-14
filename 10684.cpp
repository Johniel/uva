#include <iostream>
#include <algorithm>

using namespace std;

typedef long long int lli;

int main(void)
{
  lli num[10000 + 1];
  for(int n; ; ){
    cin >> n;
    if(n == 0)break;
    for(int i=0; i<n; ++i){
      cin >> num[i];
    }
    for(int i=1; i<n; ++i){
      num[i] = max(num[i], num[i] + num[i - 1]);
    }
    int r =  *max_element(num, num + n);
    if(0 < r)cout << "The maximum winning streak is " << r << '.' << endl;
    else cout << "Losing streak." << endl;
  }
  return 0;
}
