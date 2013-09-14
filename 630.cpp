#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <cstdio>

using namespace std;

int main(void)
{
  int tc;
  cin >> tc;
  while(tc--){
    int n;
    cin >> n;
    multimap<string, string> ms;
    for(int i=0; i<n; ++i){
      string s, t;
      cin >> s;
      t = s;
      sort(s.begin(), s.end());
      ms.insert(make_pair(s, t));
    }
    while(true){
      string s, t;
      cin >> s;
      t = s;
      sort(s.begin(), s.end());
      if(t == "END")break;
      cout << "Anagrams for: " << t << endl;
      multimap<string, string>::iterator itr;
      itr = ms.find(s);
      if(itr == ms.end())cout << "No anagrams for: " << t << endl;
      else{
	for(int i=1; ; ++i){
	  printf("%3d) %s\n", i, itr->second.c_str());
	  ++itr;
	  if(itr == ms.end())break;
	  if(itr->first != s)break;
	}
      }
    }
    if(tc)cout << endl;
  }
  return 0;
}
