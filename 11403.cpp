#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long int lli;

inline
lli B2D(string s)
{
  lli sum = 0, b = 1;
  reverse(s.begin(), s.end());
  for(int i=0; i<s.size(); ++i, b *= 2){
    if(s[i] == '1')sum += b;
  }
  return sum;
}

inline
string D2B(lli n)
{
  string s;
  for(; 2 <= n; n /= 2){
    s += (char)('0' + n % 2);
  }
  s += (char)('0' + n % 2);
  reverse(s.begin(), s.end());
  return s;
}

int main(void)
{
  for(string s, t; cin >> s >> t; ){
    if(s == "0" && t == "0")break;

    string tmp = D2B(B2D(s) * B2D(t));

    int cnt = 0, lim, tmp_size = tmp.size();
    
    lim = tmp_size - (int)s.size();
    for(int i=0; i<lim; ++i)printf(" ");    
    printf("%s\n", s.c_str());

    lim = tmp_size - (int)t.size();
    for(int i=0; i<lim; ++i)printf(" ");
    printf("%s\n", t.c_str());    

    lim = max(s.size(), t.size());
    for(int i=0; i<tmp_size - lim; ++i)printf(" ");
    for(int i=0; i<lim; ++i)printf("-");    
    printf("\n");

    lim = tmp_size - (int)s.size();
    for(int i=t.size(); i--; ++cnt){
      for(int j=0; j < lim; ++j)printf(" ");
      if(t[i] == '1')printf("%s", s.c_str());
      else for(int j=s.size(); j--; )printf("0");
      printf("\n");
      --lim;
    }

    for(int i=0; i<tmp_size; ++i)printf("-"); 
    printf("\n");
    printf("%s\n", tmp.c_str());
    printf("\n");
  }
  return 0;
}
