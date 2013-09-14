#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
  const int N = 10000 + 1;
  string s[N];
  int tc;
  for(cin >> tc; tc--; ){
    int n;
    cin >> n;
    for(int i=0; i<n; ++i){
      cin >> s[i];
    }
    sort(s, s + n);
    bool flg = true;
    for(int i=0; i<n-1; ++i){
      if(strncmp(s[i].c_str(), 
		 s[i + 1].c_str(), 
		 min(s[i].size(), s[i + 1].size())) == 0){
	flg = false;
	break;
      }
    }
    cout << (flg? "YES" : "NO") << endl;
  }
  return 0;
}
