#include <iostream>
#include <algorithm>

using namespace std;

const int FIB = 45;
int fib[FIB];

string conv(int n)
{
  string s;
  for(int i=FIB-1; ; --i){
    if(i < 2)break;
    if(fib[i] <= n){
      n -= fib[i];
      s += '1';
    }
    else if(s.size()){
      s += '0';
    }
  }
  return s;
}

int main(void)
{
  int tc;
 
  fib[0] = 0;
  fib[1] = fib[2] = 1;
  for(int i=3; i<FIB; ++i){
    fib[i] = fib[i-2] + fib[i-1];
  }

  for(cin >> tc; tc--; ){
    int n;
    cin >> n;
    cout << n << " = " << conv(n) << " (fib)" << endl; 
  }
  return 0;
}
