#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
  while( !cin.eof() ){
    vector<char> v;
    for(string s; getline(cin, s) && s != "#"; ){
      for(int i=0; i<s.size(); ++i){
        if( isalpha(s[i]) )v.push_back( s[i] );
        else if( s[i] == ' ' || s[i] == '-' ){
          v.push_back( s[i] );
        }
      }
      v.push_back('\n');
    }    
    
    for(int i=0; i+1<v.size(); ++i){
      if( v[i] == '-' && v[i+1] == '\n' ){
        v.erase( v.begin() + i );
        v.erase( v.begin() + i );
        for(int j=i; 0<=j; --j){
          if( v[j] == ' ' || v[j] == '\n' || j == 0 ){
            v.insert( v.begin() + j + 1, '\n' );
            break;
          }
        }
        for(int j=i; j<v.size(); ++j){
          if( v[j] == ' ' ){
            v.insert( v.begin() + j, '\n' );
            break;
          }
        }
      }
    }
    
    for(int i=0; i<v.size(); ++i){
      if( v[i] == '-' )continue;
      cout << v[i];
    }
    //cout << endl;
  }
  return 0;
}
