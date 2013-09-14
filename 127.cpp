#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

vector< pair<char, char> > get_input(void)
{
  string s;
  vector< pair<char, char> > v;
  for(int i=52; i-- && cin >> s; ){
    v.push_back( make_pair(s[0], s[1]) );
  }
  return v;
}

inline
bool match(pair<char, char> a, pair<char, char> b)
{
  return a.first == b.first || a.second == b.second;
}

int main(void)
{
  while(true){
    vector< pair<char, char> > v = get_input();
    if(v.size() < 52)break;    
    vector< vector< pair<char, char> > > s(52);
    for(int i=0; i<52; ++i)s[i].push_back( v[i] );
    while(true){
      bool flg = true;
      for(int i=0; i<s.size(); ++i){
        if(0<=i-3 && match( s[i].back(), s[i-3].back() )){
          s[i-3].push_back( s[i].back() );
          s[i].pop_back();
          if(s[i].size() == 0)s.erase( s.begin() + i );
          flg = false;
          break;
        }
        if(0<=i-1 && match( s[i].back(), s[i-1].back() )){
          s[i-1].push_back( s[i].back() );          
          s[i].pop_back();
          if(s[i].size() == 0)s.erase( s.begin() + i );
          flg = false;
          break;
        }
      }
      if(flg)break;
    }
    if(s.size() == 1)cout << "1 pile remaining:";
    else cout << s.size() << " piles remaining:";
    for(int i=0; i<s.size(); ++i)cout << ' ' << s[i].size();cout << endl;
  }
  return 0;
}
