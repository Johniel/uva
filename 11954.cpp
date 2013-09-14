#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

bool is_bin(string s)
{
  return s[0] == '0' || s[0] == '1';
}

vector<string> cat_num(vector<string> v)
{
  for(int i=0; i+1<v.size(); ++i){
    if( is_bin(v[i]) && is_bin(v[i+1]) ){
      v[i] += v[i+1];
      v.erase( v.begin() + 1 + i );
    }
  }
  return v;
}

string reg(string s)
{
  while(s.size() && s[0] == '0')s.erase( s.begin() );
  return s.size() ? s : "0";
}

string op_not(string s)
{
  for(int i=0; i<s.size(); ++i){
    s[i] = '0' + (s[i] == '0');
  }
  return reg(s);
}

string op_shr(string s)
{
  s.erase( s.begin() + s.size() - 1 );
  return reg(s);
}

string op_shl(string s)
{
  return reg(s + "0");
}

string op_xor(string a, string b)
{
  while(a.size() < b.size())a = "0" + a;
  while(b.size() < a.size())b = "0" + b;
  string c;
  for(int i=0; i<a.size(); ++i){
    c += '0' + (a[i] != b[i]);
  }
  return reg(c);
}

string op_and(string a, string b)
{
  while(a.size() < b.size())a = "0" + a;
  while(b.size() < a.size())b = "0" + b;
  string c;
  for(int i=0; i<a.size(); ++i){
    c += '0' + (a[i] == '1' && b[i] == '1');
  }
  return reg(c);
}

string op_or(string a, string b)
{
  while(a.size() < b.size())a = "0" + a;
  while(b.size() < a.size())b = "0" + b;
  string c;
  for(int i=0; i<a.size(); ++i){
    c += '0' + (a[i] == '1' || b[i] == '1');
  }
  return reg(c);
}


string parse(vector<string> v)
{
  v = cat_num( v );
  for(int i=0; i<v.size(); ++i){
    v[i] = reg(v[i]);
  }
  for(int i=(int)v.size()-2; 0<=i; --i){
    if(v[i] == "not"){
      v[i] = op_not( v[i+1] );
      v.erase( v.begin() + i + 1 );
    }
    else if(v[i] == "shr"){
      v[i] = op_shr( v[i+1] );
      v.erase( v.begin() + i + 1 );
    }
    else if(v[i] == "shl"){
      v[i] = op_shl( v[i+1] );
      v.erase( v.begin() + i + 1 );
    }
  }
  for(int i=1; i<v.size(); ++i){
    if(v[i] == "xor"){
      v[i-1] = op_xor(v[i-1], v[i+1]);
      v.erase( v.begin() + i );
      v.erase( v.begin() + i );
      --i;
    }
    else if(v[i] == "and"){
      v[i-1] = op_and(v[i-1], v[i+1]);
      v.erase( v.begin() + i );
      v.erase( v.begin() + i );
      --i;
    }
    else if(v[i] == "or"){
      v[i-1] = op_or(v[i-1], v[i+1]);
      v.erase( v.begin() + i );
      v.erase( v.begin() + i );
      --i;
    }
  }
  return reg(v[0]);
}

int main(void)
{
  int tc, cnt = 0;
  cin >> tc;
  cin.ignore();
  while(tc--){
    string s;
    getline(cin, s);
    istringstream iss(s);
    vector<string> v;
    for(string t; iss >> t; v.push_back(t));
    cout << "Case " << ++cnt << ": " << parse(v) << endl;
  }
  return 0;
}
