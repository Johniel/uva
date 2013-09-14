#include <iostream>
#include <algorithm>

using namespace std;

bool parser(string s)
{
  int m = 0, e = 0;
  int mi, ei;
  for(int i=0; i<s.size(); ++i){
    if(s[i] != '?' && s[i] != 'M' && s[i] != 'E')
      return false;
    if(s[i] == 'M'){
      if(m)return false;
      ++m;
      mi = i;
    }
    if(s[i] == 'E'){
      if(e)return false;
      ++e;
      ei = i;
    }
  }
  if(m && e){
    if(ei + 1 < s.size() && mi < ei){
      int x = mi;
      int y = ei - mi - 1;
      int z = (int)s.size() - ei - 1;
      //cout << s << endl; cout << x << ' ' << y << ' ' << z << endl;
      return x && y && z && x + y == z;
    }
  }
  return false;
}

int main(void)
{
  int tc;
  for(cin >> tc; tc--; ){
    string s;
    cin >> s;
    cout << (parser(s)? "theorem" : "no-theorem" ) << endl;
  }
  return 0;
}
