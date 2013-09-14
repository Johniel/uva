#include <iostream>
#include <climits>

using namespace std;

int main(void)
{
  int tc;
  cin >> tc;
  cin.ignore();
  while(tc--){
    string s;
    getline(cin, s);
    int cnt[CHAR_MAX], m = INT_MIN;
    fill(cnt, cnt + CHAR_MAX, 0);
    for(int i=0; i<s.size(); i++){
      if(isalpha(s[i])){
	cnt[ tolower(s[i]) ]++;
	m = max(m, cnt[tolower(s[i])]);
      }
    }
    //cout << m << " : " << s << endl;
    for(int i='a'; i<='z'; i++){
      if(cnt[i] == m)cout << (char)i ;
    }
    cout << endl;
  }
  return 0;
}
