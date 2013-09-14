#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

string s;

inline bool e(char c){ return c == 'e' || c == 'E'; }

int head(void)
{
  return 0;
  if( isdigit(s[0]) )return 0;
  else if(s[0] == '+' || s[0] == '-'){
    if( isdigit(s[1]) )return 1;    
  }
  return -1;
}

int integer(int i)
{
  if(i == -1)return -1;
  if(s[i] == '+' || s[i] == '-')++i;
  if( isdigit(s[i]) ){}else return -1;
  while( s[i] ){
    if( isdigit(s[i]) ){}
    else if( e(s[i]) )break;
    else return -1;
    ++i;
  }
  return i;
}

int real(int i)
{
  if(i == -1)return -1;
  if(s[i] == '+' || s[i] == '-')++i;
  if( isdigit(s[i]) ){} else return -1;  
  while( s[i] ){
    if( isdigit(s[i]) ){}
    else if(s[i] == '.')break;
    else return -1;
    ++i;
  }
  if(s[i] != '.')return -1;
  ++i;
  if( isdigit(s[i]) ){} else return -1;
  while( s[i] ){
    if( isdigit(s[i]) ){}
    else if( e(s[i]) )break;
    else return -1;
    ++i;
  }
  return i;
}

bool parse(void)
{
  if( e(s[0]) )return integer(1) != -1;
  else{
    int i = 0, a, b;
    a = integer(i);
    b = real(i);
    i = max(a, b);
    if(b != -1 && s[i] == '\0')return true;
    if(i == -1)return false;
    if( !e(s[i]) )return false;
    i = integer(i + 1);
    if( i == -1 || s[i] != '\0')return false;
    return true;
  }   
}

int main(void)
{
  while(getline(cin, s) && s != "*"){
    int i;
    for(i = 0; i<s.size(); ++i){
      if(s[i] != ' ')break;
    }
    string t;
    for(i; i<s.size(); ++i){
      t += s[i];
    }
    while( t[ (int)t.size() - 1] ==  ' ' ){
      t.erase( t.begin() + t.size() - 1 );
    }
    s = t + '\0';
    if(t.size())t = t + ' ';
    cout << t << "is " << (parse()? "" : "il") << "legal." << endl;
  }
  return 0;
}
