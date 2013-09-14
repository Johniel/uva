#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1000000000 + 1;
const int F = 50;
int f[F], size = 2;
int sum[F];

string rec(int n)
{
  //cout << n << endl;
  if(n == 0)return "0";
  if(n == 1)return "1";
  if(n == 2)return "10";
  if(n < 0)return "@";
  for(int i=0; i<size; ++i){
    if(n <= sum[i]){
      int m = n - (sum[i-1]+1);
      string s = rec(m);
      while(s.size() < i)s = "0" + s;
      return "1" + s;
    }
  }
  return "";
}

int main(void)
{
  f[0] = f[1] = 1;
  for(int i=2; i<F; ++i){
    f[i] = f[i-1] + f[i-2];    
  }
  sum[0] = 1;
  for(int i=0; i<F; ++i){
    sum[i] = sum[i-1] + f[i];
    size = i;
  }

  int tc, n;
  cin >> tc;
  while(tc--){
    cin >> n;
    cout << rec(n) << endl;
  }
  return 0;
}
