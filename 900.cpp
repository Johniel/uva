#include <iostream>

using namespace std;

typedef long long int lli;

int main(void)
{
  const int N = 50 + 2;
  lli num[N];
  num[0] = num[1] = 1;

  for(int i=2; i<N; ++i){
    num[i] = num[i - 1] + num[i - 2];
  }

  for(int n; ; ){
    cin >> n;
    if(n == 0)break;
    cout << num[n] << endl;
  }
  return 0;
}
