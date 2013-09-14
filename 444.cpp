#include <iostream>
#include <sstream>
#include <vector>

#define REP(i, n) for(int i=0; i<(int)n; i++)

using namespace std;

void enc(string s)
{
  reverse(s.begin(), s.end());
  int num = 0;
  REP(i, s.size()){
    num = num * 10 + s[i];
    if(' ' <= num <= 'z'){
      char c = num;
      cout << c ;
      num = 0;
    }
  }
  cout << endl;
}

void dec(string s) 
{
  vector<int> re;
  reverse(s.begin(), s.end());
  REP(i, s.size()){
    int n = s[i];
    while(n>10){
      re.push_back(n%10);
      n %= 10;
    }
    re.push_back(n);
  }
  REP(i, re.size())
    cout << (char)re[i];
  cout << endl;
}

int main(void)
{
  while(true){
    string in;
    getline(cin, in);
    if(cin.eof())
      break;
    if(isdigit(in[0]))
      enc(in);
    else
      dec(in);
  }
  return 0;
}
