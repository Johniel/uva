#include <iostream>

using namespace std;

int main(void)
{
  int tc;
  for(cin >> tc; tc--; ){
    string s[4];
    int n[8];
    for(int i=4; i--; ){
      cin >> s[i];
      n[i*2] = (s[i][0] - '0') * 2;
      n[i*2+1] = (s[i][2] - '0') * 2;
    }
    int sum = 0;
    for(int i=8; i--; )sum += n[i] / 10 + n[i] % 10;
    //cout << sum << endl;
    for(int i=4; i--; )sum += s[i][1] + s[i][3] - 2 * '0';
    //cout << sum << endl;
    cout << (sum%10? "Invalid" : "Valid") << endl;
  }
  return 0;
}
