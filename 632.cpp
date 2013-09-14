#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

inline
bool cmp(pair<string, int> s, pair<string, int> t)
{
  int tmp = strcmp(s.first.c_str(), t.first.c_str());
  if(tmp)return tmp < 0;
  else return s.second < t.second;
}

int main(void)
{
  int tc;
  for(cin >> tc; tc--; ){
    int n;
    string s, r;
    vector< pair<string, int> > v;
    cin >> n;
    cin.ignore();
    for(int i=0; i<n; ++i){
      char c;
      cin.get(c);
      if(c == '\n'){
	--i;
	continue;
      }
      s += c;
    }    

    for(int i=0; i<s.size(); ++i){
      string t;
      for(int j=0; j<s.size(); ++j){
	t += s[(i + j) % s.size()];
      }
      v.push_back(make_pair(t, i));
      if(i == 1)r = t;
    }
    sort(v.begin(), v.end(), cmp);
    cout << distance(v.begin(), find(v.begin(), v.end(), make_pair(r, 1))) << endl;

    for(int i=0; false && i<v.size(); ++i){
      cout << v[i].first << ' ' << v[i].second << endl;
    }

    int i;
    for(i=0; i<v.size(); ++i){
      cout << v[i].first[(int)s.size()-1];
      if(i+1 < v.size() && i && (i+1) % 50 == 0)cout << endl;
    }    
    if(false && i % 50){
      for(; i % 50; ++i){
	cout << ' ' ;
      }
    }
    cout << endl;
    if(tc)cout << endl;
  }
  return 0;
}
