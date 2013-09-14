#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
  while(true){
    char c;
    string s, t;
    cin >> c >> s;
    if(c == '0' && s == "0"){
      break;
    }
    for(int i=0; i<s.size(); ++i){
      if(s[i] != c){
	if(!(s[i] == '0' && t.size() == 0)){
	  t += s[i];
	}
      }
    }    
    if(t.size() == 0)cout << '0' << endl;
    else cout << t << endl;
  }
  return 0;
}
