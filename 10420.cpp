#include <iostream>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

int main(void)
{
  int n;
  while(cin >> n){
    map< string, set<string> > M;
    for(int i=0; i<n; ++i){
      string s, name;
      cin >> s;
      getline(cin, name);
      M[s].insert(name);
    }
    map< string, set<string> > :: iterator country;
    set<string> :: iterator women;
    for(country = M.begin(); country != M.end(); ++country){
      cout << country->first << ' ' << country->second.size() << endl; 
    }
  }
  return 0;
}
