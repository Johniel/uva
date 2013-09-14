#include <iostream>
#include <algorithm>

using namespace std;

string conv(string s)
{
  string t;
  t = s;
  t = "0" + t;;
  t.erase( t.begin() + t.size() - 1 );
  string u(s.size(), '0');
  for(int i=0; i<s.size(); ++i){
    if( t[i] != s[i] )u[i] = '1';
  }
  /*
  cout << "s : " << s << endl;
  cout << "t : " << t << endl;
  cout << "u : " << u << endl;
  */
  return u;
}

string rev(string s)
{
  string t(s.size(), ' ');  
  t[0] = s[0];
  for(int i=1; i<s.size(); ++i){
    if( t[i-1] != s[i] )t[i] = '1';
    else t[i] = '0';
  }
  //cout << s << " <=> " << t << endl;
  return t;
}

string add(string s, string t)
{
  //int mx = max(s.size(), t.size());
  string u(s.size(), '0');
  bool carry = false;
  //while( mx != s.size() ) s = "0" + s;
  while( t.size() < s.size() ) t = "0" + t;
  reverse( s.begin(), s.end() );
  reverse( t.begin(), t.end() );
  for(int i=0; i<s.size(); ++i){
    int a, b, c;
    a = s[i] - '0';
    b = t[i] - '0';
    c = carry;
    int d = a + b + c;
    u[i] = '0' + (bool)(d & 1);
    carry = d & 2;
  }
  //if(carry){ u += '1'; }
  reverse( u.begin(), u.end() );

  //reverse( s.begin(), s.end() ); reverse( t.begin(), t.end() );
  //cout << s << " + " << t << " = " << u << endl;

  return u;
}

int main(void)
{
  int n;
  string s;
  while( cin >> n >> s ){
    if(n == 0 && s == "0")break;
    string t;
    for(int i=0; (1 << i) <= n; ++i){
      if( n & (1 << i) )t += '1';
      else t += '0';
    }
    reverse( t.begin(), t.end() );
    cout << conv( add( rev( s ), t ) ) << endl;
    //cout << endl;
  }
  return 0;
}
