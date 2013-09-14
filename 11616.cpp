//uva 11616
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

map<int, string> a2r;
map<string, int> r2a;

void gen(int n)
{
  const int size = 7;
  int d[size] =  {1000, 500, 100, 50,  10,  5,   1};
  char c[size] = {'M',  'D', 'C', 'L', 'X', 'V', 'I'};
  string s;
  int m = n;
  for(int i=0; i<size; i+=1){    
    while(n >= d[i]){
      s += c[i];
      n -= d[i];
    }
    if(i + 1 < 7){
      if(i % 2){
	if(n >= d[i] - d[i+1]){
	  s += c[i+1];
	  s += c[i];
	  n -= (d[i] - d[i+1]);
	}
      }
      else{
	if(n >= d[i] - d[i] / 10){
	  s += c[i+2];
	  s += c[i];
	  n -= (d[i] - d[i] / 10);
	} 
      }
    }
  }
  a2r[m] = s;
  r2a[s] = m;
  return ;
}

int main(void)
{
  for(int i=0; i<=4000; ++i){
    gen(i);
  }
  for(string s; cin >> s; ){
    if(isdigit(s[0])){
      cout << a2r[atoi(s.c_str())] << endl;
    }
    else{
      cout << r2a[s] << endl;
    }
  }
  return 0;
}
