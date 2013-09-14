#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

const int S = 120000;
string s[S];

int main(void)
{
  int cnt;
  set<string> t;
  for(cnt = 0; getline(cin, s[cnt]); ++cnt){
    t.insert(s[cnt]);
  }
  for(int i=0; i<cnt; ++i){
    if(i && s[i-1] == s[i])continue;
    int lim = s[i].size();
    string tmp;
    for(int j=0; j<lim; ++j){
      tmp += s[i][j];
      if(j+1 < lim && t.find(tmp) != t.end()){
	if(t.find(s[i].substr(j+1)) != t.end()){
	  cout << s[i] << endl;
	  break;
	}
      }
    }    
  }
  return 0;
}
