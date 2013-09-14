#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
  for(int n, m; cin >> n >> m; ){
    if(n < m)swap(n, m);
    cout << n * (m - 1) + (n - 1) << endl;
  }
  return 0;
}
