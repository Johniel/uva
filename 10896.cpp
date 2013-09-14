#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

int main(void)
{
  const int C = 26;
  char c[C];
  for(int i=0; i<C; ++i){
    c[i] = 'a' + i;
  }
  int tc;
  cin >> tc;
  cin.ignore();
  while(tc--){
    string s, t, r;
    getline(cin, s);
    getline(cin, t);
    istringstream iss(s);
    for(string u; iss >> u; ){
      if( u.size() != t.size() )continue;
      bool flg = true;
      for(int i=0; i<u.size(); ++i){
        int a = u[i] - t[i];
        int b = u[0] - t[0];
        if(a < 0)a += 26;
        if(b < 0)b += 26;
        flg = flg && a == b;
      }
      if(flg){
        int diff = u[0] - t[0];
        if(diff < 0)diff += 26;
        r += (char)('a' + diff);
      }
    }
    sort( r.begin(), r.end() );
    cout << r << endl;
  }
  return 0;
}
