#include <iostream>
#include <stack>

using namespace std;

bool parser(string s)
{
  stack<char> S;
  for(int i=0; i<s.size(); ++i){
    if(s[i] == '(')S.push(s[i]);
    else if(s[i] == '[')S.push(s[i]);
    else if(s[i] == ')'){
      if(S.empty() || S.top() != '(')return false;
      S.pop();
    }
    else if(s[i] == ']'){
      if(S.empty() || S.top() != '[')return false;
      S.pop();
    }
    else return false;
  }
  return S.empty();
}

int main(void)
{
  int tc;
  cin >> tc;
  cin.ignore();
  while(tc--){
    string s;
    getline(cin, s);
    cout << (parser(s)? "Yes" : "No") << endl;
  }
  return 0;
}
