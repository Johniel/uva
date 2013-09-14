#include <iostream>

using namespace std;

inline
string conv(int n)
{
  string s;
  for(;3 <= n; n /= 3)
    s += '0' + n%3;
  s += '0' + n;
  reverse(s.begin(), s.end());
  return s;
}

int main(void)
{
  string s;
  while(true){
    int n;
    cin >> s;
    if(s[0] == '-')break;    
    sscanf(s.c_str(), "%d", &n);
    cout << conv(n) << endl;
  }
  return 0;
}
