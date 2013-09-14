//727
// all num is one digit
#include <iostream>
#include <stack>
#include <cstdlib>
#include <numeric>

using namespace std;

string parser(string t)
{
  string r;
  stack<char> s;
  for(int i=0; i<t.size(); ++i){
    char c = t[i];
    //cout << c << " : " << r << endl;
    if(isdigit(c)){
      r += c;
    }
    else if(c == ')'){
      while(s.top() != '('){
	r += s.top();
	s.pop();
      }
      s.pop();
    }
    else if(c == '('){
      s.push(c);
    }
    else{
      while(s.size() && s.top() != '('){
	if((s.top() == '+' || s.top() == '-') && (c == '*' || c == '/'))break;
	r += s.top();
	s.pop();
      }
      s.push(c);
    }
  }
  while(s.size()){
    r += s.top();
    s.pop();
  }
  return r;
}

int main(void)
{
  int tc;
  cin >> tc;
  cin.ignore();
  cin.ignore();
  while(tc--){
    string s, t;
    while(true){
      getline(cin, t);
      if(t.size() == 0)break;
      s += t;
    }
    cout << parser(s) << endl;
    if(tc)cout << endl;
  }
  return 0;
}
