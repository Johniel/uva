#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#include <stack>

using namespace std;

int main(void)
{
  int tc;
  for(cin >> tc; tc--; ){
    string s;
    stack< pair<int, int> > v;
    int sum = 0;
    cin >> s;
    for(int i=0, h=0; i<s.size(); ++i){
      if(s[i] == '/'){
	++h;
	while(v.size() && v.top().second < h){
	  sum += i - v.top().first;
	  v.pop();
	}
      }
      if(s[i] == '_'){
      }
      if(s[i] == '\\'){
	--h;
	v.push(make_pair(i, h));
      }
    }
    cout << sum << endl;
  }
  return 0;
}
