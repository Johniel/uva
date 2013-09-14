#include <iostream>

using namespace std;

typedef long long int lli;

const int N = 40 + 1;

int main(void)
{
  lli num[N], tc, n;
  fill(num, num + N, -1);
  num[0] = 1;
  num[1] = 1;
  num[2] = 5;
  for(int i=3; i<N; ++i){
    num[i] = num[i-1] + 4 * num[i-2] + 2 * num[i-3];
  }
  for(cin >> tc; tc--; ){
    cin >> n;
    cout << num[n] << endl;
  }
  return 0;
}
