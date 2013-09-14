#include <iostream>
#include <algorithm>
#include <map>
#include <cassert>

using namespace std;

int main(void)
{
  map<char, char> conv;

  /*
  for(char c='A'; c<='Z'; ++c){
    conv[c] = c;
  }
  conv['.'] = '.';
  conv[','] = ',';
  conv[' '] = ' ';
  */

  conv['0'] = 'O';
  conv['1'] = 'I';
  conv['2'] = 'Z';
  conv['3'] = 'E';
  conv['4'] = 'A';
  conv['5'] = 'S';
  conv['6'] = 'G';
  conv['7'] = 'T';
  conv['8'] = 'B';
  conv['9'] = 'P';

  int tc;
  cin >> tc;  
  cin.ignore();
  while( tc-- ){
    for(string s; getline(cin, s) && s.size(); ){
      for(int i=0; i<s.size(); ++i){
        
        if( conv.find(s[i]) != conv.end() ) cout << conv[ s[i] ] ;
        else cout << s[i];
        continue;
        if( conv.find( s[i] ) == conv.end() ){
          assert(false);
        }
      }
      cout << endl;
    }
    if(tc)cout << endl;
  }
  return 0;
}
