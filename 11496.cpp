#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
  for(int n; cin >> n && n; ){
    int w[n];
    int cnt = 0;
    for(int i=0; i<n; ++i){
      cin >> w[i];
    }
    for(int i=0; i<n; ++i){
      int l = (i + n - 1) % n;
      int r = (i + 1) % n;
      if((w[i] < w[l] && w[i] < w[r]) || 
	 (w[i] > w[l] && w[i] > w[r])){
	++cnt;
      }
    }
    cout << cnt << endl;
  }
  return 0;
}
