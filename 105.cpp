#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
  const int N = 10000 + 1;
  int h[N];
  int l = 1 << 22;
  int r = 0;
  fill(h, h + N, 0);
  for(int a, b, c; cin >> a >> b >> c ; ){
    for(int i=a; i<c; ++i){
      h[i] = max(h[i], b);
    }
    l = min(l, a);
    r = max(r, c);
  }
  int curr = h[l];
  cout << l << ' ' << curr;
  for(int i=l+1; i<=r; ++i){
    if(curr != h[i]){
      curr = h[i];
      cout << ' ' << i << ' ' << curr;
    }
  }
  cout << endl;
  //cout << ' ' << r << ' ' << 0 << endl;
  return 0;
}
