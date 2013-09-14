#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
  while(true){
    string s;
    cin >> s;
    if(s == "0")
      break;
    int sum = 0;
    reverse(s.begin(), s.end());
    for(int i=0; i<s.size(); ++i){
      sum += (s[i] - '0') * ((int)((unsigned)(1 << (i + 1))) - 1);
    }
    cout << sum << endl;
  }
  return 0;
}
