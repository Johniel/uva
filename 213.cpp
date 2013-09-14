#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <set>

using namespace std;

void rec(string s, int lim, vector<string> &v)
{
  if(s.size() == lim){
    if( count(s.begin(), s.end(), '1') == s.size() ){}
    else v.push_back(s);
  }
  else{
    rec(s + "0", lim, v);
    rec(s + "1", lim, v);
  }
  return ;
}

vector<string> make_key(void)
{
  vector<string> v;
  for(int i=1; i<8; ++i){
    rec("", i, v);
  }
  return v;
}

int b2i(string s)
{
  int sum = 0;
  reverse( s.begin(), s.end() );
  for(int i=0; i<s.size(); ++i){
    if(s[i] == '1')sum += 1 << i;
  }
  return sum;
}

int main(void)
{
  string s;
  const vector<string> v = make_key();
  while( getline(cin, s) ){
    map<string, char> w;
    //cout << "s : " << s << endl;
    for(int i=0; i<s.size(); ++i){
      w[ v[i] ] = s[i];
    }
    while(true){
      string len;
      char c;
      for(int i=0; i<3; ++i){
        cin >> c;
        len += c;
      }
      if(len == "000")break;
      int l = b2i(len);
      //cout << len << endl;
      while(true){        
        string key;
        for(int i=0; i<l; ++i){
          cin >> c;
          key += c;
        }
        //cout << "key : " << key << endl;
        if( count( key.begin(), key.end(), '1' ) == key.size() )break;
        cout << w[key] << flush;
      }
    }
    cout << endl;
    cin.ignore();
  }
  return 0;
}
