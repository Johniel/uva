#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <sstream>

using namespace std;

int main(void)
{ 
  string s;
  getline(cin, s);
  while(true){
    getline(cin, s);
    if(count(s.begin(), s.end(), '_') == s.size())break;
    int c = 0;
    for(int i=1; i<(int)s.size()-1; ++i){
      if(s[i] == '.')continue;
      if(i != 1)c <<= 1;
      if(s[i] == 'o')++c;
    }
    cout << (char)c << flush;
  }
  return 0;
}
