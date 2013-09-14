#include <iostream>

using namespace std;

int main(void)
{
  int tc;
  cin >> tc;
  while(tc--){
    int e, f, c, sum = 0;
    cin >> e >> f >> c;
    e += f;
    while(c <= e){
      ++sum;
      e -= c;
      ++e;
    }
    cout << sum << endl;
  }
  return 0;
}
