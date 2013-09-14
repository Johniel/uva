#include <iostream>
#include <algorithm>
#include <sstream>
#include <map>
#include <vector>

using namespace std;

int main(void)
{
  string s;
  while(cin >> s){
    map<char, char> conv;
    for(char c='a'; c<='z'; ++c){
      char d;
      cin >> d;
      conv[c] = d;
    }
    const int size = s.size();
    int n;
    vector< pair<char, char> > v[size];   
    cin >> n;    
    for(int i=0; i<n; ++i){
      int m;
      char c, d;
      cin >> m >> c >> d;
      v[m].push_back( make_pair(c, d) );
    }
    string t;
    for(int i=0; i<size; ++i){
      for(int j=0; j<v[i].size(); ++j){
        conv[ v[i][j].first ] = v[i][j].second;
      }
      t += conv[ s[i] ];
    }
    static int cnt = 0;
    cout << "Case #" << ++cnt << ": The encoding string is " << t << "." << endl;
    cout << endl;
  }
  return 0;
}
