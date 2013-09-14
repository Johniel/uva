#include <iostream>
#include <algorithm>

using namespace std;

int conv(string s)
{
  int sum = 0;
  reverse(s.begin(), s.end());
  int base = 1;
  for(int i=0; i<s.size(); ++i, base *= 4){
    if(s[i] == 'U')sum += base * 1;
    else if(s[i] == 'C')sum += base * 2;
    else if(s[i] == 'D')sum += base * 3;
  }
  return sum;
}

int main(void)
{
  int tc;
  cout << "COWCULATIONS OUTPUT" << endl;
  for(cin >> tc; tc--; ){
    string num1, num2, ans;
    cin >> num1 >> num2;
    int n = conv(num1), m = conv(num2);
    for(int i=0; i<3; ++i){
      char c;
      cin >> c;
      if(c == 'A')m += n;
      else if(c == 'R')m /= 4;
      else if(c == 'L')m *= 4;
    }
    cin >> ans;
    cout << (m == conv(ans)? "YES" : "NO") << endl;
  }
  cout << "END OF OUTPUT" << endl;
  return 0;
}
