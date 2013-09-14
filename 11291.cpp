#include <iostream>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <sstream>

using namespace std;

inline
bool is_smeech(string s)
{
  for(int i=0; i<s.size(); ++i){
    if(s[i] == '(' || s[i] == ')')return true;
  }
  return false;
}

inline
double conv2double(string s)
{
  istringstream iss(s);
  double d;
  iss >> d;
  return d;
}

double parser(string s)
{
  if(!is_smeech(s)){
    return conv2double(s);
  }
  string t, a, b;
  int i, o, c;
  for(i = 1; i < s.size() && s[i] != ' '; ++i){
    t += s[i];
  }
  double p = conv2double(t);
  o = c = 0;
  for(++i; i < s.size(); ++i){
    if(s[i] == ' ' && o == c)break;
    a += s[i];    
    if(s[i] == '(')++o;
    if(s[i] == ')')++c;
  }
  double e1 = parser(a); 
  for(++i; i+1 < s.size(); ++i){
    b += s[i];
  }
  double e2 = parser(b);  

  /*
  cout << "(" << t << ' ' << a << ' ' << b << ")" << endl;
  cout << e1 << ' ' << e2 << endl;
  cout << p * (e1 + e2) << ' ' << (p - 1.0) * (e1 - e2) << endl;
  */
  
  return p * (e1 + e2) + (1.0 - p) * (e1 - e2);
}

int main(void)
{
  string s;
  while(getline(cin, s) && s != "()"){
    int b = 0, e = s.size();
    string t;
    for(int i=0; i<s.size(); ++i){
      if(s[i] == '.'){
	if(t[(int)t.size() - 1] == '('){
	  t += '0';
	}
      }
      t += s[i];
    }
    printf("%.2lf\n", parser(t));
  }
  return 0;
}
