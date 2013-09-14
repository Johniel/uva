#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <sstream>
#include <vector>

using namespace std;

inline string check(string s)
{
  int cnt = 0;
  for(int i=0; i<s.size(); ++i){
    if( isalpha( s[i] ) )++cnt;
  }
  if( cnt == 0 )return "";
  return s;
}

int main(void)
{
  string s;
  set<string> v;
  for(string t; getline(cin, t); ){
    s += t;
    s += '\n';
  }

  for(int i=0; i<s.size(); ++i){
    if( isalpha( s[i] ) ){
      s[i] = tolower( s[i] );
    }
    else if( s[i] == '-' );
    else if( s[i] == '\n' );
    else s[i] = ' ';
  }  

  string t;
  for(int i=0; i<s.size(); ++i){
    if( s[i] == ' '){
      t = check( t );
      if( t.size() )v.insert( t );
      t = "";
    }
    else if( s[i] == '\n' ){
      if( t.size() && t[ (int)t.size() - 1 ] == '-' ){
        t.erase( t.begin() + (int)t.size() - 1 );
      }
      else{
        t = check( t );
        if( t.size() )v.insert( t );
        t = "";
      }
    }
    else t += s[i];    
  }
  
  set<string>::iterator itr;
  for( itr = v.begin(); itr != v.end(); ++itr){
    cout << *itr << endl;
  }
  return 0;
}
