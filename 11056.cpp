#include <iostream>
#include <algorithm>
#include <strings.h>

using namespace std;

typedef long long int lli;

struct pilot{
  string s;
  long long int time;
  pilot(){};
  pilot(string t, lli m, lli se, lli ms){
    s = t;
    time = ms + 1000 * (se + 60 * m);
  }
};

bool lexCmp(string a, string b)
{
  int lim = min(a.size(), b.size());
  for(int i=0; i<lim; ++i){
    if(toupper(a[i]) != toupper(b[i]))
      return toupper(a[i]) < toupper(b[i]);      
  }
  return a < b;
}

bool operator < (const pilot &a, const pilot &b)
{
  if(a.time != b.time)return a.time < b.time;
  return strcasecmp(a.s.c_str(), b.s.c_str()) < 0;
  return lexCmp(a.s, b.s);
  return a.s < b.s;
}

int main(void)
{
  for(int n; cin >> n; ){
    pilot s[n];
    for(int i=0; i<n; ++i){
      string t, u;
      char c;
      lli m, se, ms;
      cin >> t >> c >> m >> u >> se >> u >> ms >> u;
      s[i] = pilot(t, m, se, ms);
    }
    sort(s, s + n);
    for(int i=0, r = 0; i<n; ++i){
      if(i % 2 == 0){
	cout << "Row " << ++r << endl;
      }
      cout << s[i].s << endl;
    }
    cout  << endl;
  }
  return 0;
}
