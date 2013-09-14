#include <iostream>
#include <algorithm>
#include <map>

using namespace std;



int main(void)
{
  int n, v;
  while(cin >> v >> n){
    map<string, string> M;
    pair<string, int> p[n];
    for(int i=0; i<n; ++i)
      cin >> p[i].first >> p[i].second;
    for(int i=0; i<n; ++i){
      string s, t;
      for(int j=0; j<p[i].second; ++j){
	cin >> t; 
	s += t;
      }
      reverse(s.begin(), s.end());
      if(p[i].second == 0)s = "0";
      M.insert(make_pair(p[i].first, s));
    }
    int q;
    cin >> q;
    for(int i=0; i<q; ++i){
      string s;
      cin >> s;
      map<string, string>::iterator itr = M.find(s);
      if(itr == M.end())cout << s << "=" << endl; 
      else{
	string t = itr->second;
	unsigned long long int sum = 0, b = 1;
	for(int j=0; j<t.size(); ++j, b *= 2){
	  if(t[j] == '1')sum += b;
	}
	cout << s << "=" << sum << endl;
      }
    }
  }
  return 0;
}
