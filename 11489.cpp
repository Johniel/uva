#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
  int tc,no = 0;
  for(cin >> tc; tc--; ){
    string s;
    cin >> s;
    //cout << endl; cout << s << endl;
    cout << "Case " << ++no << ": ";
    int sum = 0, cnt = 0;    
    for(int i=0; i<s.size(); ++i){
      sum += s[i] - '0';
      if((s[i] - '0') % 3 == 0){
	++cnt;
      }
    }
    if(s.size() == 1){
      cout << 'S' << endl;
      continue;
    }
    if(sum % 3){
      bool flg = false;
      for(int i=0; i<s.size(); ++i){
	int sub = sum - s[i] + '0';
	if(sub % 3 == 0){
	  flg = true;
	  break;
	}
      }  
      if(!flg){
	cout << 'T' << endl;
      }
      else{
	cout << (cnt%2? 'T' : 'S') << endl;
      }
    }
    else{
      cout << (cnt%2? 'S' : 'T') << endl;
    }
  }
  return 0;
}
