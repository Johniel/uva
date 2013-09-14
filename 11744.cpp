#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
  int tc;
  for(cin >> tc; tc--; ){
    string a, b, c, d;
    c.resize(31);
    d.resize(31);
    bool flg = false;
    for(cin >> a >> b; true; ){
      if(flg)b = "overflow";   
      cout << a << ' ' << b << endl;
      if(flg || count(b.begin(), b.end(), '0') == b.size())break;
      for(int i=31; i--; ){
	c[i] = '0' + (a[i] != b[i]);
	d[i] = '0' + (a[i] == '1' && b[i] == '1');
      }      
      a = c;
      flg = (d[0] == '1');
      for(int i=0; i<30; ++i)
	b[i] = d[i+1];
      b[30] = '0';
    }    
    if(tc)cout << endl;
  }
  return 0;
}
