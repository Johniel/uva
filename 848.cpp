#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

vector<char> get_input(void)
{
  vector<char> v;
  for(string s; getline(cin, s); ){
    for(int i=0; i<s.size(); ++i){
      v.push_back( s[i] );
    }
    v.push_back('@');
  }
  return v;
}

int main(void)
{
  vector<char> v = get_input();
  vector<string> u;
  for(int i=0; i<v.size(); ++i){  
    string s;
    for(int j=i; j<v.size(); ++j){
      while(j < v.size() && v[j] != ' ' && v[j] != '\n'){
        s += v[j];
        ++j;
      }
      s += v[j];
      if(s.size() > 72){
        i = j;
        break;
      }
      if(j < v.size() && v[j] == '\n' && 
         (v[j+1] == ' ' || v[j+1] == '\n' || j + 1 == v.size())){
        while(j < v.size() && v[j] == ' ')++j;
        i = j;
        break;
      }
    }
    u.push_back(s);
  }
  for(int i=0; i<u.size(); ++i){
    cout << u[i] << endl;
  }
  return 0;
}
