#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
  int num[10000];
  while(true){
    string s;
    cin >> s;
    if(s == "0")break;
    reverse(s.begin(), s.end());
    bool flg = true;
    int c = s[0];
    for(int i=0; i<s.size(); ++i)
      num[(int)s.size() - 1 - i] = s[i];
    if(flg)cout << s << "is a multiple of 11." << endl;
    else cout << s << << endl;
  }
  return 0;
}
