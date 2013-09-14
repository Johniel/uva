#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long int lli;

const string MSG = "such number is impossible!";

int conv(char c)
{
  if(isdigit(c))return c - '0';
  if(isupper(c))return c - 'A' + 10;
  if(islower(c))return c - 'a' + 36;    
  exit(1);
}

bool solve(vector<int> v, lli base)
{
  lli sum = 0;
  lli w = 1;
  reverse(v.begin(), v.end());
  for(int i=0; i<v.size(); ++i){
    sum = (sum * base + v[i]) % (base-1);
  }
  return sum == 0;
}

int main(void)
{
  while(!cin.eof()){
    int mx = -1;
    vector<int> v;
    string s;
    if(!getline(cin, s))break;
    for(int i=0; i<s.size(); ++i){
      if(!isalnum(s[i]))continue;
      v.push_back(conv(s[i]));
      mx = max(mx, v.back());
    }
    if(mx < 2){
      cout << 2 << endl;
      continue;
    }
    bool flg = true;    
    for(int i=mx+1; i<62+1; ++i){
      if(solve(v, i)){
	cout << i << endl;
	flg = false;
	break;
      }
    }
    if(flg)cout << MSG << endl;
  }
  return 0;
}
