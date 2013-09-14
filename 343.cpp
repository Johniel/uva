#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int baseCon(string s, int b)
{
  int sum = 0;
  reverse(s.begin(), s.end());
  for(int i=0, c = 1; i<s.size(); ++i, c *= b){
    if(isalpha(s[i]))sum += (s[i] - 'A' + 10) * c;
    else sum += (s[i] - '0') * c;
  }
  return sum;
}

int main(void)
{
  string s, t;
  while(cin >> s >> t){
    if(s == "0" && t == "0"){
      cout << "0 (base 2) = 0 (base 2)" << endl;
      continue;
    }
    map<int, int> M;
    int b;
    b = -1;
    for(int i=0; i<s.size(); ++i)b = max(b, (int)s[i]);
    b = isalpha((char)b)? b - 'A' + 10 : b - '0' ; 
    //cout << max(2, b + 1) << endl;
    for(int i=max(2, b+1); i<=36; ++i){
      int tmp = baseCon(s, i);
      if(!M[tmp]){
	//cout << tmp << ' ' << i << endl;
	M[tmp] = i;
      }
    }
    bool flg = true;
    b = -1;
    for(int i=0; i<t.size(); ++i)b = max(b, (int)t[i]);
    b = isalpha((char)b)? b - 'A' + 10 : b - '0' ; 
    //cout << max(2, b + 1) << endl;
    for(int i=max(2, b+1); i<=36 && flg; ++i){
      int n = baseCon(t, i);
      //cout << n << ' ' << i << ' ' << M[n] << endl;
      if(n && M[n]){
	cout << s << " (base " << M[n] << ") = " 
	     << t << " (base " << i << ")" << endl;
	flg = false;
      }
    }
    if(flg)cout << s << " is not equal to " << t << " in any base 2..36" << endl;
  }
  return 0;
}
