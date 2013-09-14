#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>

#include <cstdio>

using namespace std;

void output(vector<int> n, vector<char> o, string t)
{
  for(int i=0; i<n.size(); ++i){
    if(i)cout << ' ';
    cout << n[i] << ' ' << o[i];
  }
  cout << ' ' << t << endl;
  return ;
}

string conv(string s)
{
  ostringstream oss;
  istringstream iss(s);
  string t;
  int n;
  char c;
  while(iss >> n >> c){
    oss << n << ' ' << c << ' ';
    if(c == '='){
      iss >> t;
      oss << t;
      break;
    }
  }
  return oss.str();
}

string itoa(int n)
{
  char buff[100];
  sprintf(buff, "%d", n);
  return string(buff);
}

int main(void)
{
  bool flg = true;
  for(string s; getline(cin, s); ){
    s = conv(s);
    vector<int> n;
    vector<char> o;
    istringstream iss(s);
    int num;
    char c;
    string t;
    if(flg)flg = false;
    else cout << endl;
    while(iss >> num >> c){
      n.push_back(num);
      o.push_back(c);
      if(c == '='){
        iss >> t;
        break;
      }
    }
    
    cout << s << endl;
    while(n.size() != 1){
      bool flg = true;
      for(int i=0; flg && i<o.size(); ++i){
        if(o[i] == '*' || o[i] == '/'){
          int a = n[i];
          int b = n[i+1];
          int c = (o[i] == '*')? a * b : a / b;
          n.erase( n.begin() + i + 1 );
          n.erase( n.begin() + i );
          n.insert( n.begin() + i, c );
          o.erase( o.begin() + i );
          flg = false;
        }
      }
      for(int i=0; flg && i<o.size(); ++i){
        if(o[i] == '+' || o[i] == '-'){
          int a = n[i];
          int b = n[i+1];
          int c = (o[i] == '+')? a + b : a - b;
          n.erase( n.begin() + i + 1 );
          n.erase( n.begin() + i );
          n.insert( n.begin() + i, c );
          o.erase( o.begin() + i );
          flg = false;
        }
      }      
      output(n, o, t);
    }

  }  
  return 0;
}
