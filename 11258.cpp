#include <iostream>
#include <algorithm>
#include <climits>
#include <cstdio>

using namespace std;

typedef long long int lli;

inline
lli atol(string s)
{
  lli sum = 0;
  if(10 < s.size())return 4294967296ll;
  sscanf(s.c_str(), "%Ld", &sum);
  return sum;
  reverse(s.begin(), s.end());
  for(int i=0; i<s.size(); ++i){
    sum = sum * 10 + (lli)(s[i] - '0');
  }
  return sum;
}

const lli MAX = 2147483647ll;
const int T = 200 + 10;  
static lli t[T][T];

lli dp(string s)
{

  t[0][0] = 0;
  s = "0" + s;
  for(int i=0; i<=s.size(); ++i){
    for(int j=0; j<=i; ++j){
      if(t[i][j] < 0)continue;
      t[i+1][j] = 0; // no split
      string a = s.substr(j + 1, i - j + 1);
      lli n = atol(a);
      if(n <= (lli)INT_MAX){
        t[i+1][i] = max(t[i+1][i], t[i][j] + n);
        cout << j << ":" << i << " === " << a 
             << " # " << t[i+1][i] << " -- " << endl;
      }
    }
  }
  cout << "s : " << s << "  s.size() = " << s.size() << endl;
  lli mx = 0;
  mx = t[ s.size() ][ s.size() + 1 ];
  return mx;
}

lli rec(string s, int last, int curr)
{  
  //cout << last << ' ' << curr << endl;
  if( t[last][curr] != -MAX )return t[last][curr];
  if( curr == s.size() ){
    string tmp = s.substr(last);
    lli n = atol( tmp );
    //cout << last << " : " << curr << " == " << (n <= MAX ? n : -MAX) << endl;
    return n <= MAX ? n : -MAX;
  }
  lli mx = -MAX; 
  string tmp = s.substr( last, curr - last );
  lli n = atol( tmp );
  if( n <= MAX ){
    lli m = rec(s, curr, curr + 1);
    //cout << last << " : " << curr << " (rec1) " << m << endl;
    mx = max( mx, rec( s, curr, curr + 1 ) + n );
  }
  lli m = rec(s, last, curr + 1);
  //cout << last << " : " << curr << " (rec2) " << m << endl;
  mx = max( mx, m );
  //cout << last << " : " << curr << " == " << mx << endl;
  return t[last][curr] = mx;
}

int main(void)
{
  int tc;
  cin >> tc;
  while(tc--){
    string s;
    cin >> s;
    fill(&t[0][0], &t[T-1][T], -MAX);
    //t[0][0] = 0;
    cout << rec(s, 0, 0) << endl;
  }
  //cout << (lli)INT_MAX << endl;
  return 0;
}

