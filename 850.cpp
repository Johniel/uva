#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

const string key = "the quick brown fox jumps over the lazy dog";
map<char, char> dic;

bool solve(string s)
{
  if( s.size() != key.size() )return false;
  for(int i=0; i<key.size(); ++i){
    if( isalpha( key[i] ) != isalpha( s[i] ) )return false;
    for(int j=i+1; j<key.size(); ++j){
      if( (key[i] == key[j]) !=  (s[i] == s[j]) )return false;
    }
  }
  dic.clear();
  for(int i=0; i<s.size(); ++i){
    dic[ s[i] ] = key[i];
  }
  return true;
}

int main(void)
{
  int tc;
  cin >> tc;
  cin.ignore();
  cin.ignore();
  while( tc-- ){
    vector<string> v;
    for(string s; getline(cin, s) && s.size(); v.push_back(s));
    bool flg = false;
    for(int i=0; i<v.size() && !flg; ++i){
      if( solve(v[i]) )flg = true;
    }
    if(flg){
      for(int i=0; i<v.size(); ++i){
        for(int j=0; j<v[i].size(); ++j){
          cout << dic[ v[i][j] ] ;
        }
        cout << endl;
      }
    }
    else cout << "No solution." << endl;
    if(tc)cout << endl;
  }
  return 0;
}
