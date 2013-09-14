#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main(void)
{
  for(int n, m; cin >> n >> m; ){
    int duty;
    set<string> taken;
    string s;
    for(int i=0; i<n; ++i){
      cin >> s;
      taken.insert(s);
    }    
    bool flg = true;
    for(int i=0; i<m; ++i){
      cin >> n;
      cin >> duty;
      for(int j=0; j<n; ++j){
	cin >> s;
	if(taken.count(s)){
	  --duty;
	}
      }
      flg = flg && (duty <= 0);
    }
    cout << (flg? "yes" : "no") << endl;
  }  
  return 0;
}
