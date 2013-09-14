#include <iostream>

using namespace std;

int main(void)
{
  const int P = 1, N = 2, C = 4, F = 8;
  int tc;
  cin >> tc;
  cin.ignore();
  string s;
  while(tc--){
    getline(cin, s);
    int bs = 0, size = s.size();
    if(s == "1" || s == "4" || s == "78")bs |= P;
    else if(s[size-1] == '5' && s[size-2] == '3')bs |= N;
    else if(size >= 2 && s[0] == '9' && s[size-1] == '4')bs |= F;
    else if(size >= 3 && s[0] == '1' && s[1] == '9' && s[2] == '0')bs |= C;
    if(bs && ((bs ^ P) == 0))cout << '+' << endl;
    else if(bs && ((bs ^ N) == 0))cout << '-' << endl;
    else if(bs && ((bs ^ C) == 0))cout << '?' << endl;
    else if(bs && ((bs ^ F) == 0))cout << '*' << endl;
  }
  return 0;
}
