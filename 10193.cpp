#include <iostream>
#include <algorithm>

using namespace std;

int B2D(string s)
{
  int sum = 0;
  reverse(s.begin(), s.end());
  for(int i=0, b=1; i<s.size(); ++i, b*=2){
    if(s[i] == '1')sum += b;
  }
  return sum;
}

int gcd(int a, int b)
{
  return a%b? gcd(b, a%b) : b;
}

int main(void)
{
  const string R1 = "All you need is love!";
  const string R2 = "Love is not all you need!";
  int tc, cnt = 0;
  for(cin >> tc; tc--; ){
    string s, t;
    cin >> s >> t;
    int n = B2D(s), m = B2D(t);
    cout << "Pair #" << ++cnt << ": " << flush;
    if((n == 0 && m == 1) || (n == 1 && m == 0)){
      cout << R2 << endl;
    }
    else if(n == 0 || m == 0){
      cout << R1 << endl;
    }
    else if(true){
      int num = gcd(max(n, m), min(n, m));
      cout << (num != 1? R1 : R2) << endl;
    }
  }
  return 0;
}
