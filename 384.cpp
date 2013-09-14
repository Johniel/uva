#include <iostream>
#include <algorithm>

using namespace std;

bool slump(string s, int &b, int &e)
{
  //cout << "slump " << s.substr(b, e - b) << endl;
  if(s[b] != 'E' && s[b] != 'D')return false;
  for(++b; b < e && s[b] == 'F'; ++b);
  if(b >= e)return false;
  if(s[b] == 'G'){
    ++b;
    //cout << b << ' ' << e << endl;
    return true;
  }
  else if(slump(s, b, e)){
    return true;
  }
  return false;
}

bool slimp(string s, int &b, int &e)
{
  //cout << "slimp " << s.substr(b, e - b) << endl;
  if(s[b] != 'A')return false;
  ++b;
  if(b >= e)return false;  
  if(s[b] == 'H'){
    ++b;
    return true;
  }
  else{
    if(s[b] == 'B'){
      ++b;
      if(b >= e)return false;  
      if(slimp(s, b, e)){
	if(b >= e)return false;  
	return s[b++] == 'C';
      }	
    }
    else{
      if(slump(s, b, e)){
	if(b >= e)return false;  
	return s[b++] == 'C';
      }
    }
  }
  return false;
}

bool parser(string s)
{
  int b = 0, e = s.size();
  if(slimp(s, b, e)){
    if(slump(s, b, e)){
      //cout << b <<' ' << e << endl;
      if(b == e){
	return true;
      }
    }
  }
  return false;
}

int main(void)
{
  int tc;
  cout << "SLURPYS OUTPUT" << endl;
  for(cin >> tc; tc--; ){
    string s;
    cin >> s;
    cout << (parser(s)? "YES" : "NO") << endl;
  }
  cout << "END OF OUTPUT" << endl;
  return 0;
}
