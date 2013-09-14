//uva 11351
#include <iostream>

using namespace std;

int Josephus(int n, int s)
{
  if (n == 0) return 0; 
  else return (s + Josephus(n - 1, s) ) % n ;//0~n-1
  
}

int main(void)
{
  int tc, cnt = 0;
  for(cin >> tc; tc--; ){
    int n, m;
    cin >> n >> m;
    cout << "Case " << ++cnt << ": " << Josephus(n, m)+1 << endl;
  }
  return 0;
}
